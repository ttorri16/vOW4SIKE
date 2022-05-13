/********************************************************************************************
* SIDH: an efficient supersingular isogeny cryptography library
*
* Abstract: supersingular isogeny parameters and generation of functions for P182
*********************************************************************************************/  

#include "P182_internal.h"


// Encoding of field elements, elements over Z_order, elements over GF(p^2) and elliptic curve points:
// --------------------------------------------------------------------------------------------------
// Elements over GF(p) and Z_order are encoded with the least significant octet (and digit) located at the leftmost position (i.e., little endian format). 
// Elements (a+b*i) over GF(p^2), where a and b are defined over GF(p), are encoded as {a, b}, with a in the least significant position.
// Elliptic curve points P = (x,y) are encoded as {x, y}, with x in the least significant position. 
// Internally, the number of digits used to represent all these elements is obtained by approximating the number of bits to the immediately greater multiple of 32.
// For example, a 182-bit field element is represented with Ceil(182 / 64) = 3 64-bit digits or Ceil(182 / 32) = 6 32-bit digits.

//
// Curve isogeny system "SIDHp182". Base curve: Montgomery curve By^2 = Cx^3 + Ax^2 + Cx defined over GF(p182^2), where A=0, B=1, C=1
//

// Values written in a readable way (arrays have least significant 64-bit int first)
// p182 =    0x002895ac20d5040b d9a6c7b117ffffff ffffffffffffffff
// p182+1 =  0x002895ac20d5040b d9a6c7b118000000 0000000000000000
// p182x2 =  0x00512b5841aa0817 b34d8f622fffffff fffffffffffffffe
// M_rprime= 0x326895ac20d5040b d9a6c7b118000000 0000000000000001
// M_R2 =    0x0011db6d93928d2c d16b783ad39e820b b5926932c396fc6a
// M_one =   0x00205cc901007d49 c681017ab0000000 000000000000064e
//A_order                              0x8000000 0000000000000000
//B_order                              0x512b584 1aa0817b34d8f623

/*
 * p182p1 = p182 + 1
 * p182x2 = 2*p182
 * Montgomery_rprime = -(p182)^-1 mod 2^192
 * Montgomery_R2 = (2^192)^2 mod p182
 * Montgomery_one = 2^192 mod p182
 */

    /* p182 = 2^91 * 3^57 - 1 */
    const uint64_t p182[NWORDS64_FIELD] = { 0xffffffffffffffff, 0xd9a6c7b117ffffff, 0x2895ac20d5040b };
    const uint64_t p182p1[NWORDS64_FIELD] = { 0x0000000000000000, 0xd9a6c7b118000000, 0x2895ac20d5040b };
    const uint64_t p182x2[NWORDS64_FIELD] = { 0xfffffffffffffffe, 0xb34d8f622fffffff, 0x512b5841aa0817 };
    
    
    // Order of Alice's subgroup = 2^91
    const uint64_t Alice_order[NWORDS64_ORDER]       = {0x0000000000000000, 0x8000000 }; 
    // Order of Bob's subgroup = 3^57
    const uint64_t Bob_order[NWORDS64_ORDER]         = { 0x1aa0817b34d8f623, 0x512b584 };
 
    const uint64_t Montgomery_rprime1[NWORDS64_FIELD] = { 0x0000000000000001, 0xd9a6c7b118000000, 0x326895ac20d5040b};
    const uint64_t Montgomery_R2[NWORDS64_FIELD] =  { 0xb5926932c396fc6a, 0xd16b783ad39e820b, 0x11db6d93928d2c};
    const uint64_t Montgomery_one[NWORDS64_FIELD] = { 0x000000000000064e, 0xc681017ab0000000, 0x205cc901007d49};

//strategies 
const unsigned int strat_Alice[MAX_Alice-1] = { 
19, 12, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 8, 4, 3, 2, 1, 1, 1, 1, 2, 1, 1, 
4, 2, 1, 1, 2, 1, 1};

const unsigned int strat_Bob[MAX_Bob-1] = { 
26, 15, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 11, 7, 4, 2, 1, 1, 2, 
1, 1, 3, 2, 1, 1, 1, 1, 4, 3, 2, 1, 1, 1, 1, 2, 1, 1};
// Setting up macro defines and including GF(p), GF(p^2), curve, isogeny and kex functions
#define fpcopy                        fpcopy182
#define fpzero                        fpzero182
#define fpadd                         fpadd182
#define fpsub                         fpsub182
#define fpneg                         fpneg182
#define fpdiv2                        fpdiv2_182
#define fpcorrection                  fpcorrection182
#define fpmul_mont                    fpmul182_mont
#define fpsqr_mont                    fpsqr182_mont
#define fpinv_mont                    fpinv182_mont
#define fpinv_chain_mont              fpinv182_chain_mont
#define fpinv_mont_bingcd             fpinv182_mont_bingcd
#define fp2copy                       fp2copy182
#define fp2zero                       fp2zero182
#define fp2add                        fp2add182
#define fp2sub                        fp2sub182
#define fp2neg                        fp2neg182
#define fp2div2                       fp2div2_182
#define fp2correction                 fp2correction182
#define fp2mul_mont                   fp2mul182_mont
#define fp2sqr_mont                   fp2sqr182_mont
#define fp2inv_mont                   fp2inv182_mont
#define fp2inv_mont_bingcd            fp2inv182_mont_bingcd
#define mp_add_asm                    mp_add182_asm
#define mp_subaddx2_asm               mp_subadd182x2_asm
#define mp_dblsubx2_asm               mp_dblsub182x2_asm
#define crypto_kem_keypair            crypto_kem_keypair_SIKEp182
#define crypto_kem_enc                crypto_kem_enc_SIKEp182
#define crypto_kem_dec                crypto_kem_dec_SIKEp182
#define random_mod_order_A            random_mod_order_A_SIDHp182
#define random_mod_order_B            random_mod_order_B_SIDHp182

#include "../fpx.c"
#include "../ec_isogeny.c"
// #include "../sidh.c"    
// #include "../sike.c"