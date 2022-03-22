#include "P182_internal.h"
#include "P182.c"
#include <stdio.h>
#include <stdlib.h> 


/*
* HOW TO RUN:
* in the root folder, do "make p182_unit_test"
* executable will be named p182test
*/

int64_t cpu_cycles(void)
{ // Access system counter for benchmarking
#if (OS_TARGET == OS_WIN) && (TARGET == TARGET_AMD64 || TARGET == TARGET_x86)
    return __rdtsc();
#elif (OS_TARGET == OS_WIN) && (TARGET == TARGET_ARM)
    return __rdpmccntr64();
#elif (OS_TARGET == OS_LINUX) && (TARGET == TARGET_AMD64 || TARGET == TARGET_x86)
    unsigned int hi, lo;

    asm volatile("rdtsc\n\t"
                 : "=a"(lo), "=d"(hi));
    return ((int64_t)lo) | (((int64_t)hi) << 32);
#elif (OS_TARGET == OS_LINUX) && (TARGET == TARGET_ARM || TARGET == TARGET_ARM64)
    struct timespec time;

    clock_gettime(CLOCK_REALTIME, &time);
    return (int64_t)(time.tv_sec * 1e9 + time.tv_nsec);
#else
    return 0;
#endif
}

int compare_words(digit_t* a, digit_t* b, unsigned int nwords)
{ // Comparing "nword" elements, a=b? : (1) a>b, (0) a=b, (-1) a<b
  // SECURITY NOTE: this function does not have constant-time execution. TO BE USED FOR TESTING ONLY.
    int i;

    for (i = nwords-1; i >= 0; i--)
    {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }

    return 0; 
}

static void fprandom182_test(digit_t* a)
{ // Generating a pseudo-random field element in [0, p128-1] 
  // SECURITY NOTE: distribution is not fully uniform. TO BE USED FOR TESTING ONLY.
    unsigned int i, diff = 192-182, nwords = 3;                    
    unsigned char* string = NULL;

    string = (unsigned char*)a;
    for (i = 0; i < sizeof(digit_t)*nwords; i++) {
        *(string + i) = (unsigned char)rand();              // Obtain 182-bit number
    }
    a[nwords-1] &= (((digit_t)(-1) << diff) >> diff);

}

int main() {

    digit_t num1[3] = {0x6829576def293748, 0x0849274957284e60, 0x001999992f293948};
    digit_t num2[3] = {0x0517b96254856264, 0x758214abc5214856, 0x00089625874152d6};
    digit_t ans[3];


    printf("num1 is:\t0x%016lx%016lx%016lx\n", num1[2], num1[1], num1[0]);
    printf("num2 is:\t0x%016lx%016lx%016lx\n", num2[2], num2[1], num2[0]);

    //modular addition
    fpadd(&num1[0], &num2[0], &ans[0]);
    printf("num1+num2 is:\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be:\t0x0x222fbeb66a8c1e7dcb3bf51c4996b66d4110d043ae99ac\n\n");

    //modular subtraction (positive answer)
    fpsub(&num1[0], &num2[0], &ans[0]);
    printf("num1-num2 is:\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be \t0x00110373a7e7e67192c7129d9207060a63119e0b9aa3d4e4\n\n");

    //modular subtraction (negative answer)
    fpsub(&num2[0], &num1[0], &ans[0]);
    printf("num2-num1 (mod p182x2):\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be \t\t0x004027e499c221a620867cc49df8f9f59cee61f4655c2b1a\n\n");
    
    fpcorrection(&ans[0]);
    printf("num2-num1 (mod p182):\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be \t\t0x0017923878ed1d9a46dfb51385f8f9f59cee61f4655c2b1b\n\n");

    //modular subtraction (0 answer)
    fpsub(&num1[0], &num1[0], &ans[0]);
    printf("num1-num1 is:\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be \t0x0\n\n");


    digit_t zero[3] = {0,0,0};

    // negate num1
    digit_t ans1[3] = {0x6829576def293748, 0x0849274957284e60, 0x001999992f293948};
    fpneg(ans1);
    printf("-num1 (mod p182x2) is:\t0x%016lx%016lx%016lx\n", ans1[2], ans1[1], ans1[0]);
    printf("Supposed to be \t\t0x003791bf1280cecfab046818d8d7b19f97d6a89210d6c8b6\n\n");

    fpcorrection(&ans1[0]);
    printf("-num1 (mod p182) is:\t0x%016lx%016lx%016lx\n", ans1[2], ans1[1], ans1[0]);
    printf("Supposed to be \t\t0x000efc12f1abcac3d15da067c0d7b19f97d6a89210d6c8b7\n\n");


    // divide even number by 2
    fpdiv2(&num1[0], &ans[0]);
    printf("num1/2 is:\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be \t0x000ccccc97949ca4042493a4ab9427303414abb6f7949ba4\n\n");
    
    //divide even number by 2
    fpdiv2(&num2[0], &ans[0]);
    printf("num2/2 is:\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be \t0x00044b12c3a0a96b3ac10a55e290a42b028bdcb12a42b132\n\n");

    //divide odd number by 2
    digit_t num1m1[3] = {0x6829576def293747, 0x0849274957284e60, 0x001999992f293948};
    fpdiv2(&num1m1[0], &ans[0]);
    printf("(num1-1)/2 is:\t0x%016lx%016lx%016lx\n", ans[2], ans[1], ans[0]);
    printf("Supposed to be \t0x002117a2a7ff1ea9f0f7f77d379427303414abb6f7949ba3\n\n");

    int64_t cycles = 0, cycles182 = 0;
    int loops = 10000000;
    for(int i = 0; i < loops; i++) {
        digit_t ans2x[6] = {0,0,0,0,0,0};
        digit_t _ans2x[6] = {0,0,0,0,0,0};

        digit_t a[3], b[3];
        fprandom182_test(a);
        fprandom182_test(b);

        // printf("a: %016lx %016lx %016lx\n", a[2], a[1], a[0]);
        // printf("b: %016lx %016lx %016lx\n", b[2], b[1], b[0]);
        int64_t cyc = cpu_cycles();
        mp_mul3(&a[0], &b[0], &ans2x[0]);
        cycles182 += (cpu_cycles() - cyc);
        // printf("a*b is:  \t0x%016lx%016lx%016lx%016lx%016lx%016lx\n", ans2x[5], ans2x[4], ans2x[3], ans2x[2], ans2x[1], ans2x[0]);
        cyc = cpu_cycles();
        mp_mul(&a[0], &b[0], &_ans2x[0], 3);
        cycles += (cpu_cycles() - cyc);
        // printf("Should be:\t0x%016lx%016lx%016lx%016lx%016lx%016lx\n", _ans2x[5], _ans2x[4], _ans2x[3], _ans2x[2], _ans2x[1], _ans2x[0]);
        if(compare_words(ans2x, _ans2x, 6) == 0) {
            // printf("PASS\n");
        } else {
            printf("*** FAIL on %016lx%016lx%016lx * %016lx%016lx%016lx\n", a[2], a[1], a[0], b[2], b[1], b[0]);
        }


        // printf("num1[1,0] * num2[1,0] should be: \t0x%016lx%016lx%016lx%016lx\n", ans2x[3], ans2x[2], ans2x[1], ans2x[0]);

    }

    printf("Generic:\t%ld\n", cycles/loops);
    printf("Karatsuba:\t%ld\n", cycles182/loops);

    // //digit multiplication
    // digit_x_digit(num1[0], num2[0], &ans[0]);
    // printf("num1[0] * num2[0] is:\t0x%016lx%016lx\n", ans[1], ans[0]);
    // printf("Supposed to be \t0x021275d9e2f20ae5b867349c8bab2820\n\n");


    //MONTGOMERY REPRESENTATION
    // digit_t mnum1[3];
    // digit_t mnum2[3];
    // to_mont(&num1[0], &mnum1[0]);
    // to_mont(&num2[0], &mnum2[0]);


    // fpmul_mont(&mnum1[0], &mnum1[0], &ans[0]);

    // fpsqr_mont        
    // fpinv_mont        
// fpinv_chain_mont  
// fpinv_mont_bingcd 
// fp2copy           
// fp2zero           
// fp2add            
// fp2sub            
// fp2neg            
// fp2div2           
// fp2correction     
// fp2mul_mont       
// fp2sqr_mont       
// fp2inv_mont       
// fp2inv_mont_bingcd
    
}

