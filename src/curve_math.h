#pragma once

/* Functions specific to PXXX */
#ifdef P128
    #include "P128/P128_internal.h"
    extern const uint64_t Montgomery_one[NWORDS64_FIELD];
    #define fpcopy                        fpcopy128
    #define fpzero                        fpzero128
    #define fpsub                         fpsub128
    #define fpneg                         fpneg128
    #define fp2copy                       fp2copy128
    #define fp2add                        fp2add128
    #define fp2sub                        fp2sub128
    #define fp2neg                        fp2neg128
    #define fp2correction                 fp2correction128
    #define fp2mul_mont                   fp2mul128_mont
    #define fp2sqr_mont                   fp2sqr128_mont
    #define fpinv_mont                    fpinv128_mont
    #define fp2inv_mont                   fp2inv128_mont
#elif defined(P434)
    #include "P434/P434_internal.h"
    extern const uint64_t Montgomery_one[NWORDS64_FIELD];
    #define fpcopy                        fpcopy434
    #define fpzero                        fpzero434
    #define fpsub                         fpsub434
    #define fpneg                         fpneg434
    #define fp2copy                       fp2copy434
    #define fp2add                        fp2add434
    #define fp2sub                        fp2sub434
    #define fp2neg                        fp2neg434
    #define fp2correction                 fp2correction434
    #define fp2mul_mont                   fp2mul434_mont
    #define fp2sqr_mont                   fp2sqr434_mont
    #define fpinv_mont                    fpinv434_mont
    #define fp2inv_mont                   fp2inv434_mont
#elif defined(P182)
    #include "P182/P182_internal.h"
    extern const uint64_t Montgomery_one[NWORDS64_FIELD];
    #define fpcopy                        fpcopy182
    #define fpzero                        fpzero182
    #define fpsub                         fpsub182
    #define fpneg                         fpneg182
    #define fp2copy                       fp2copy182
    #define fp2add                        fp2add182
    #define fp2sub                        fp2sub182
    #define fp2neg                        fp2neg182
    #define fp2correction                 fp2correction182
    #define fp2mul_mont                   fp2mul182_mont
    #define fp2sqr_mont                   fp2sqr182_mont
    #define fpinv_mont                    fpinv182_mont
    #define fp2inv_mont                   fp2inv182_mont
#endif

/* Functions from an isogeny library */
#define xDBL_SIDH                               xDBL
#define xDBLe_SIDH                              xDBLe
#define xDBLADD_SIDH                            xDBLADD

#define GetFourIsogenyWithKernelXneZ            get_4_isog
#define EvalFourIsogenyWithKernelXneZ           eval_4_isog

typedef struct {
	f2elm_t a24;
	f2elm_t xp;
	f2elm_t xq;
	f2elm_t xpq;
} CurveAndPointsSIDH;
