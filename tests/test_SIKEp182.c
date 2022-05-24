/********************************************************************************************
* SIDH: an efficient supersingular isogeny cryptography library
*
* Abstract: benchmarking/testing isogeny-based key encapsulation mechanism SIKEp182
*********************************************************************************************/ 

#include <stdio.h>
#include <string.h>
#include "test_extras.h"
#include "../src/P182/P182_api_incomplete.h"


#define SCHEME_NAME    "SIKEp182"

#define crypto_kem_keypair            crypto_kem_keypair_SIKEp182
#define crypto_kem_enc                crypto_kem_enc_SIKEp182
#define crypto_kem_dec                crypto_kem_dec_SIKEp182

#include "test_sike.c"