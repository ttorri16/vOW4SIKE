#pragma once
#include <inttypes.h>
#include <stdbool.h>
#include "../settings.h"

#if defined(VOW_SIKE) || defined(VOW_SIDH)
#include "../curve_math.h" // to get CurveandPointsSIDH
#endif

/* For testing instances */
#if defined(VOW_SIDH)
typedef struct
{
    char MODULUS[10];
    unsigned long NBITS_K;
    unsigned long MEMORY_LOG_SIZE;
    double ALPHA;
    double BETA;
    double GAMMA;
    uint64_t PRNG_SEED;
    uint16_t N_OF_CORES;
    CurveAndPointsSIDH E[2];
    f2elm_t jinv; /* For verifying */
    bool PRECOMP;
    bool HANSEL_GRETEL;
    uint64_t MAX_CRUMBS;
} instance_t;

#elif defined(VOW_SIKE)

typedef struct
{
    char MODULUS[10];
    unsigned long e; // e2 / 2 ?? or is it d ?? see page 14 of Cosello et. al.
    unsigned long MEMORY_LOG_SIZE; // w = 2^MEMORY_LOG_SIZE
    double ALPHA; // theta = alpha * sqrt( memory size / 2^(e-1) ), page 6 of Costello et. al.
    double BETA; // change function version after (beta * memory size) distinguished points, page 7 Costello et. al.
    double GAMMA; // max vow steps before restarting is gamma/theta 
    uint64_t PRNG_SEED; 
    uint16_t N_OF_CORES;
    CurveAndPointsSIDH E[2]; // left and right precomputation curves, page 13-15, see PrecompRightCurve and PrecompLeftCurve in sike.c
    unsigned long delta; /* Depth of pre-computation */
    f2elm_t jinv;        /* For verifying */
    bool HANSEL_GRETEL;
    uint64_t MAX_CRUMBS;
} instance_t;

#else // generic function

/* For testing instances */
typedef struct
{
    uint64_t NBITS_STATE;
    uint64_t MEMORY_LOG_SIZE;
    double ALPHA;
    double BETA;
    double GAMMA;
    unsigned long PRNG_SEED;
    uint16_t N_OF_CORES;
    bool HANSEL_GRETEL;
    uint64_t MAX_CRUMBS;
} instance_t;
#endif