
_ALPHA = 2.25
_BETA = 10.0
_GAMMA = 20.0

insts_stats = [
    # { "NBITS_STATE": 03, "MEMORY_LOG_SIZE": 02, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10381},
    # { "NBITS_STATE": 07, "MEMORY_LOG_SIZE": 06, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10382},
    #ifdef STORE_IN_DATABASE
    # { "NBITS_STATE": 07, "MEMORY_LOG_SIZE": 06, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10382},
    #endif
    # { "NBITS_STATE": 08, "MEMORY_LOG_SIZE": 04, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10381},
    # { "NBITS_STATE": 09, "MEMORY_LOG_SIZE": 04, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10382},
    # { "NBITS_STATE": 09, "MEMORY_LOG_SIZE": 07, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10383},
    # { "NBITS_STATE": 10, "MEMORY_LOG_SIZE": 07, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10383},
    # { "NBITS_STATE": 11, "MEMORY_LOG_SIZE": 07, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 11, "MEMORY_LOG_SIZE": 08, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10383},
    # { "NBITS_STATE": 12, "MEMORY_LOG_SIZE": 07, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10385},
    # { "NBITS_STATE": 13, "MEMORY_LOG_SIZE": 07, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10386},
    { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 0},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 1},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 2},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 3},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 4},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 5},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 6},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 7},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 8},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 9},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 11},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 12},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 13},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 14},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 15},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 16},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 17},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 18},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 19},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 20},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 21},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 22},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 23},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 24},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 25},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 26},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 27},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 28},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 29},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 30},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 31},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 32},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 33},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 34},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 35},
    # { "NBITS_STATE": 14, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 36},
    # { "NBITS_STATE": 15, "MEMORY_LOG_SIZE": 02, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 15, "MEMORY_LOG_SIZE": 04, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 15, "MEMORY_LOG_SIZE": 06, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 15, "MEMORY_LOG_SIZE": 07, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10388},
    # { "NBITS_STATE": 15, "MEMORY_LOG_SIZE": 08, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 15, "MEMORY_LOG_SIZE": 09, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 17, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 18, "MEMORY_LOG_SIZE": 12, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10388},
    # { "NBITS_STATE": 19, "MEMORY_LOG_SIZE": 11, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    { "NBITS_STATE": 20, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 20, "MEMORY_LOG_SIZE": 12, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 21, "MEMORY_LOG_SIZE": 13, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 22, "MEMORY_LOG_SIZE": 12, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 23, "MEMORY_LOG_SIZE": 11, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 23, "MEMORY_LOG_SIZE": 13, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 7, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10381},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 12, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 24, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 25, "MEMORY_LOG_SIZE": 11, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 25, "MEMORY_LOG_SIZE": 13, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 25, "MEMORY_LOG_SIZE": 15, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 26, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 27, "MEMORY_LOG_SIZE": 11, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 27, "MEMORY_LOG_SIZE": 13, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 27, "MEMORY_LOG_SIZE": 15, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 27, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 27, "MEMORY_LOG_SIZE": 17, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 13, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 13, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 18, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 28, "MEMORY_LOG_SIZE": 18, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 29, "MEMORY_LOG_SIZE": 11, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 29, "MEMORY_LOG_SIZE": 13, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 29, "MEMORY_LOG_SIZE": 15, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 29, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 29, "MEMORY_LOG_SIZE": 17, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 29, "MEMORY_LOG_SIZE": 19, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 10, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 18, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 20, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20.0, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 12, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 14, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 18, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 30, "MEMORY_LOG_SIZE": 20, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 7.7, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 31, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 32, "MEMORY_LOG_SIZE": 7, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10381},
    # { "NBITS_STATE": 32, "MEMORY_LOG_SIZE": 16, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 33, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 34, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 35, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 36, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 37, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 38, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 39, "MEMORY_LOG_SIZE": 16, "ALPHA": 2.25, "BETA": 10.0, "GAMMA": 20, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 40, "MEMORY_LOG_SIZE": 16, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 48, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
    # { "NBITS_STATE": 56, "MEMORY_LOG_SIZE": 10, "ALPHA": _ALPHA, "BETA": _BETA, "GAMMA": _GAMMA, "PRNG_SEED": 10384},
]

NUM_INSTS_STATS = len(insts_stats)
