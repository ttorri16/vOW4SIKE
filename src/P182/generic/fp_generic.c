/********************************************************************************************
* SIDH: an efficient supersingular isogeny cryptography library
*
* Abstract: portable modular arithmetic for P182
*********************************************************************************************/

#include "../P182_internal.h"
#include <stdio.h>

// Global constants
extern const uint64_t p182[NWORDS_FIELD];
extern const uint64_t p182p1[NWORDS_FIELD]; 
extern const uint64_t p182x2[NWORDS_FIELD]; 


__inline void fpadd182(const digit_t* a, const digit_t* b, digit_t* c)
{ // Modular addition, c = a+b mod p182.
  // Inputs: a, b in [0, 2*p182-1] 
  // Output: c in [0, 2*p182-1] 

    unsigned int i, carry = 0;
    digit_t mask;

    for (i = 0; i < NWORDS_FIELD; i++) {
        ADDC(carry, a[i], b[i], carry, c[i]); 
    }

    carry = 0;
    for (i = 0; i < NWORDS_FIELD; i++) {
        SUBC(carry, c[i], ((digit_t*)p182x2)[i], carry, c[i]); 
    }
    mask = 0 - (digit_t)carry;

    carry = 0;
    for (i = 0; i < NWORDS_FIELD; i++) {
        ADDC(carry, c[i], ((digit_t*)p182x2)[i] & mask, carry, c[i]); 
    }
} 


__inline void fpadd182_fast(const digit_t* a, const digit_t* b, digit_t* c) {
    
/* We know NWORDS_FIELD == 3, so use this info to avoid for loops -> hopefully 
    this will compile to fewer instructions */
/*NOTE: this is technically no longer generic since it assumes a 64-bit architecture, but
        I think there are other places in the code that also make this assumption */
/* Time difference between this and fpadd182 is probably negligible */

    unsigned int i, carry = 0;
    digit_t mask;

    ADDC(carry, a[0], b[0], carry, c[0]); 
    ADDC(carry, a[1], b[1], carry, c[1]); 
    ADDC(carry, a[2], b[2], carry, c[2]); 

    carry = 0;
    SUBC(carry, c[0], ((digit_t*)p182x2)[0], carry, c[0]); 
    SUBC(carry, c[1], ((digit_t*)p182x2)[1], carry, c[1]); 
    SUBC(carry, c[2], ((digit_t*)p182x2)[2], carry, c[2]); 
    mask = 0 - (digit_t)carry;

    carry = 0;
    ADDC(carry, c[0], ((digit_t*)p182x2)[0] & mask, carry, c[0]); 
    ADDC(carry, c[1], ((digit_t*)p182x2)[1] & mask, carry, c[1]); 
    ADDC(carry, c[2], ((digit_t*)p182x2)[2] & mask, carry, c[2]); 
}


__inline void fpsub182(const digit_t* a, const digit_t* b, digit_t* c)
{ // Modular subtraction, c = a-b mod p182.
  // Inputs: a, b in [0, 2*p182-1] 
  // Output: c in [0, 2*p182-1]
//   printf("fpsub182\n"); 
    unsigned int i, borrow = 0;
    digit_t mask;

    for (i = 0; i < NWORDS_FIELD; i++) {
        SUBC(borrow, a[i], b[i], borrow, c[i]); 
    }
    mask = 0 - (digit_t)borrow;

    borrow = 0;
    for (i = 0; i < NWORDS_FIELD; i++) {
        ADDC(borrow, c[i], ((digit_t*)p182x2)[i] & mask, borrow, c[i]); 
    }
}


__inline void fpneg182(digit_t* a)
{ // Modular negation, a = -a mod p182.
  // Input/output: a in [0, 2*p182-1] 
    unsigned int i, borrow = 0;

    for (i = 0; i < NWORDS_FIELD; i++) {
        SUBC(borrow, ((digit_t*)p182x2)[i], a[i], borrow, a[i]); 
    }
}


void fpdiv2_182(const digit_t* a, digit_t* c)
{ // Modular division by two, c = a/2 mod p182.
  // Input : a in [0, 2*p182-1] 
  // Output: c in [0, 2*p182-1] 
    unsigned int i, carry = 0;
    digit_t mask;
        
    mask = 0 - (digit_t)(a[0] & 1);    // If a is odd compute a+p182
    for (i = 0; i < NWORDS_FIELD; i++) {
        ADDC(carry, a[i], ((digit_t*)p182)[i] & mask, carry, c[i]); 
    }

    mp_shiftr1(c, NWORDS_FIELD);
} 


void fpcorrection182(digit_t* a)
{ // Modular correction to reduce field element a in [0, 2*p182-1] to [0, p182-1].
    unsigned int i, borrow = 0;
    digit_t mask;

    for (i = 0; i < NWORDS_FIELD; i++) {
        SUBC(borrow, a[i], ((digit_t*)p182)[i], borrow, a[i]); 
    }
    mask = 0 - (digit_t)borrow;

    borrow = 0;
    for (i = 0; i < NWORDS_FIELD; i++) {
        ADDC(borrow, a[i], ((digit_t*)p182)[i] & mask, borrow, a[i]); 
    }
}


void digit_x_digit(const digit_t a, const digit_t b, digit_t* c)
{ // Digit multiplication, digit * digit -> 2-digit result    
    register digit_t al, ah, bl, bh, temp;
    digit_t albl, albh, ahbl, ahbh, res1, res2, res3, carry;
    digit_t mask_low = (digit_t)(-1) >> (sizeof(digit_t)*4), mask_high = (digit_t)(-1) << (sizeof(digit_t)*4);

    al = a & mask_low;                        // Low part
    ah = a >> (sizeof(digit_t) * 4);          // High part
    bl = b & mask_low;
    bh = b >> (sizeof(digit_t) * 4);

    albl = al*bl;
    albh = al*bh;
    ahbl = ah*bl;
    ahbh = ah*bh;
    c[0] = albl & mask_low;                   // C00

    res1 = albl >> (sizeof(digit_t) * 4);
    res2 = ahbl & mask_low;
    res3 = albh & mask_low;  
    temp = res1 + res2 + res3;
    carry = temp >> (sizeof(digit_t) * 4);
    c[0] ^= temp << (sizeof(digit_t) * 4);    // C01   

    res1 = ahbl >> (sizeof(digit_t) * 4);
    res2 = albh >> (sizeof(digit_t) * 4);
    res3 = ahbh & mask_low;
    temp = res1 + res2 + res3 + carry;
    c[1] = temp & mask_low;                   // C10 
    carry = temp & mask_high; 
    c[1] ^= (ahbh & mask_high) + carry;       // C11
}


void mp_mul(const digit_t* a, const digit_t* b, digit_t* c, const unsigned int nwords)
{ // Multiprecision comba multiply, c = a*b, where lng(a) = lng(b) = nwords.   
    // printf("mp_mul\n");
    unsigned int i, j;
    digit_t t = 0, u = 0, v = 0, UV[2];
    unsigned int carry = 0;
    
    for (i = 0; i < nwords; i++) {
        for (j = 0; j <= i; j++) {
            MUL(a[j], b[i-j], UV+1, UV[0]); 
            ADDC(0, UV[0], v, carry, v); 
            ADDC(carry, UV[1], u, carry, u); 
            t += carry;
        }
        c[i] = v;
        v = u; 
        u = t;
        t = 0;
    }

    for (i = nwords; i < 2*nwords-1; i++) {
        for (j = i-nwords+1; j < nwords; j++) {
            MUL(a[j], b[i-j], UV+1, UV[0]); 
            ADDC(0, UV[0], v, carry, v); 
            ADDC(carry, UV[1], u, carry, u); 
            t += carry;
        }
        c[i] = v;
        v = u; 
        u = t;
        t = 0;
    }
    c[2*nwords-1] = v; 
}

/* fast multiplication in Fp using Karatsuba       written by Tori Mannarelli (so theres probably bugs) */
void mp_mul3(const digit_t* a, const digit_t* b, digit_t* c) {
    // first do (a[1], a[2])*(b[1], b[2]) using karatsuba

    //high
    MUL(a[1], b[1], c[3], c[2]);
    //low
    MUL(a[0], b[0], c[1], c[0]);

    //middle
                            // (a[1] + a[0])*(b[1] + b[0]) - a1b1 - a0b0; 

    bool carrya, carryb;
    digit_t a0pa1, b0pb1;
    ADDC(0, a[1], a[0], carrya, a0pa1);
    ADDC(0, b[1], b[0], carryb, b0pb1);

    digit_t prod[3] = {0,0,0};
    MUL(a0pa1, b0pb1, prod[1], prod[0]);

    //manually handle any carries from the addition 
    //assumes carrya and carryb can only be 1 or 0 (true since its 1-digit addition)
    //sets carrya and carryb to carry of the addition with prod[1]
    prod[2] = carrya && carryb;
    ADDC(0, prod[1], b0pb1*carrya, carrya, prod[1]);
    ADDC(0, prod[1], a0pa1*carryb, carryb, prod[1]);

    //account for any carries
    prod[2] += carrya + carryb;

    //Now prod is the 3-digit value (a[1]+a[0])(b[1]+b[0])

    //To get a1b1(x^2) + (prod - a1b1 - a0b0)(x)  + a0b0(1)    we do:

    //      [ prod[2] ] [ prod[1] ] [ prod[0] ] [         ]
    //   -  [         ] [ a0b0[1] ] [ a0b0[0] ] [         ]
    //   -  [         ] [ a1b1[1] ] [ a1b1[0] ] [         ]
    //   +  [ a1b1[1] ] [ a1b1[0] ] [ a0b0[1] ] [ a0b0[0] ]  (c[0:4])

    // prod - a0b0
    SUBC(0, prod[0], c[0], carrya, prod[0]); 
    SUBC(carrya, prod[1], c[1], carrya, prod[1]);
    prod[2] -= carrya;
    // assert(carrya == 0);

    //prod - a1b1
    SUBC(0, prod[0], c[2], carrya, prod[0]); 
    SUBC(carrya, prod[1], c[3], carrya, prod[1]);
    prod[2] -= carrya;
    // assert(carrya == 0);

    // add a1b1[1] a1b1[0] a0b0[1] a0b0[0] 
    ADDC(0, c[1], prod[0], carrya, c[1]);
    ADDC(carrya, c[2], prod[1], carrya, c[2]);
    ADDC(carrya, c[3], prod[2], carrya, c[3]);
    // assert(carrya == 0);

    // printf("Result of Karatsuba intermed is: \t0x%016lx%016lx%016lx%016lx\n", intermed[3], intermed[2], intermed[1], intermed[0]);

    //Now include the high digits:
    // c =  (a2, a1, a0) * (b2, b1, b0)
    //   = a2b2, a2*(b1,b0) + (a1,a0)*b2, (a1,a0)(b1,b0)
    //   = (a2b2, a2*b1 + a1*b2, a2*b0 + a0*b2, intermed) 

    //  [5] [4] [3] [] [] []
    //  [ a2b2] [ intermed ]


    digit_t temp[2] = {0,0};
    MUL(a[2], b[2], c[5], c[4]);

    // printf("c: %016lx%016lx%016lx%016lx%016lx%016lx\n", c[5], c[4], c[3], c[2], c[1], c[0]);

    // a2b0
    MUL(a[2], b[0], temp[1], temp[0]);
    ADDC(0, temp[0], c[2], carrya, c[2]);
    ADDC(carrya, temp[1], c[3], carrya, c[3]);
    c[4] += carrya;

    // a0b2
    MUL(a[0], b[2], temp[1], temp[0]);
    ADDC(0, temp[0], c[2], carrya, c[2]);
    ADDC(carrya, temp[1], c[3], carrya, c[3]);
    c[4] += carrya;

    //a2b1
    MUL(a[2], b[1], temp[1], temp[0]);
    ADDC(0, temp[0], c[3], carrya, c[3]);
    ADDC(carrya, temp[1], c[4], carrya, c[4]);
    c[5] += carrya;

    //a1b2
    MUL(a[1], b[2], temp[1], temp[0]);
    ADDC(0, temp[0], c[3], carrya, c[3]);
    ADDC(carrya, temp[1], c[4], carrya, c[4]);
    c[5] += carrya;

    // assert(carrya==0);

}


void rdc_mont(digit_t* ma, digit_t* mc)
{ // Efficient Montgomery reduction using comba and exploiting the special form of the prime p182.
  // mc = ma*R^-1 mod p182x2, where R = 2^182.
  // If ma < 2^182*p182, the output mc is in the range [0, 2*p182-1].
  // ma is assumed to be in Montgomery representation.
//   printf("rdc_mont\n");
    unsigned int i, j, carry, count = p182_ZERO_WORDS;
    digit_t UV[2], t = 0, u = 0, v = 0;

    for (i = 0; i < NWORDS_FIELD; i++) {
        mc[i] = 0;
    }

    for (i = 0; i < NWORDS_FIELD; i++) {
        for (j = 0; j < i; j++) {
            if (j < (i-p182_ZERO_WORDS+1)) { 
                MUL(mc[j], ((digit_t*)p182p1)[i-j], UV+1, UV[0]);
                ADDC(0, UV[0], v, carry, v); 
                ADDC(carry, UV[1], u, carry, u); 
                t += carry; 
            }
        }
        ADDC(0, v, ma[i], carry, v); 
        ADDC(carry, u, 0, carry, u); 
        t += carry; 
        mc[i] = v;
        v = u;
        u = t;
        t = 0;
    }    

    for (i = NWORDS_FIELD; i < 2*NWORDS_FIELD-1; i++) {
        if (count > 0) {
            count -= 1;
        }
        for (j = i-NWORDS_FIELD+1; j < NWORDS_FIELD; j++) {
            if (j < (NWORDS_FIELD-count)) { 
                MUL(mc[j], ((digit_t*)p182p1)[i-j], UV+1, UV[0]);
                ADDC(0, UV[0], v, carry, v); 
                ADDC(carry, UV[1], u, carry, u); 
                t += carry;
            }
        }
        ADDC(0, v, ma[i], carry, v); 
        ADDC(carry, u, 0, carry, u); 
        t += carry; 
        mc[i-NWORDS_FIELD] = v;
        v = u;
        u = t;
        t = 0;
    }
    ADDC(0, v, ma[2*NWORDS_FIELD-1], carry, v); 
    mc[NWORDS_FIELD-1] = v;
}
