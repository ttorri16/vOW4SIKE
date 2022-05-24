#include "P128_internal.h"
#include "P128.c"
#include <stdio.h>



/*
* HOW TO RUN:
* in the root folder, do "make p128_unit_test"
* executable will be named p182test
*/

int main() {

    digit_t num1[2] = {0x0849274957284e60, 0x001999992f293948};
    digit_t num2[2] = {0x758214abc5214856, 0x00089625874152d6};
    digit_t ans[2];


    printf("num1 is:\t0x%016lx%016lx\n", num1[1], num1[0]);
    printf("num2 is:\t0x%016lx%016lx\n", num2[1], num2[0]);

    //modular addition
    fpadd128(&num1[0], &num2[0], &ans[0]);
    printf("num1+num2 is:\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be:\t0x0x222fbeb66a8c1e7dcb3bf51c4996b66d4110d043ae99ac\n\n");

    //modular subtraction (positive answer)
    fpsub128(&num1[0], &num2[0], &ans[0]);
    printf("num1-num2 is:\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be \t0x00110373a7e7e67192c7129d9207060a63119e0b9aa3d4e4\n\n");

    //modular subtraction (negative answer)
    fpsub128(&num2[0], &num1[0], &ans[0]);
    printf("num2-num1 (mod p182x2):\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be \t\t0x004027e499c221a620867cc49df8f9f59cee61f4655c2b1a\n\n");
    
    fpcorrection128(&ans[0]);
    printf("num2-num1 (mod p182):\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be \t\t0x0017923878ed1d9a46dfb51385f8f9f59cee61f4655c2b1b\n\n");

    //modular subtraction (0 answer)
    fpsub128(&num1[0], &num1[0], &ans[0]);
    printf("num1-num1 is:\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be \t0x0\n\n");


    digit_t zero[2] = {0,0};

    // negate num1
    digit_t ans1[3] = {0x6829576def293748, 0x0849274957284e60, 0x001999992f293948};
    fpneg128(ans1);
    printf("-num1 (mod p182x2) is:\t0x%016lx%016lx\n", ans1[1], ans1[0]);
    // printf("Supposed to be \t\t0x003791bf1280cecfab046818d8d7b19f97d6a89210d6c8b6\n\n");

    fpcorrection128(&ans1[0]);
    printf("-num1 (mod p182) is:\t0x%016lx%016lx\n", ans1[1], ans1[0]);
    // printf("Supposed to be \t\t0x000efc12f1abcac3d15da067c0d7b19f97d6a89210d6c8b7\n\n");


    // divide even number by 2
    fpdiv2_128(&num1[0], &ans[0]);
    printf("num1/2 is:\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be \t0x000ccccc97949ca4042493a4ab9427303414abb6f7949ba4\n\n");
    
    //divide even number by 2
    fpdiv2_128(&num2[0], &ans[0]);
    printf("num2/2 is:\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be \t0x00044b12c3a0a96b3ac10a55e290a42b028bdcb12a42b132\n\n");

    //divide odd number by 2
    digit_t num1m1[3] = {0x6829576def293747, 0x0849274957284e60, 0x001999992f293948};
    fpdiv2_128(&num1m1[0], &ans[0]);
    printf("(num1-1)/2 is:\t0x%016lx%016lx\n",  ans[1], ans[0]);
    // printf("Supposed to be \t0x002117a2a7ff1ea9f0f7f77d379427303414abb6f7949ba3\n\n");

    // //digit multiplication
    // digit_x_digit(num1[0], num2[0], &ans[0]);
    // printf("num1[0] * num2[0] is:\t0x%016lx%016lx\n", ans[1], ans[0]);
    // printf("Supposed to be \t0x021275d9e2f20ae5b867349c8bab2820\n\n");

    // //digit multiplication
    // digit_x_digit(num1[1], num2[1], &ans[0]);
    // printf("num1[1] * num2[1] is:\t0x%016lx%016lx\n", ans[1], ans[0]);

    //multi-precision multiplication
    digit_t ans_double[4]; 
    mp_mul(num1, num2, ans_double, 2);
    printf("num1*num2 is:\t0x%016lx%016lx%016lx%016lx\n", ans_double[3], ans_double[2], ans_double[1], ans_double[0]);

    digit_t rans_double[4]; 
    rdc_mont(ans_double, rans_double);
    printf("Montgomery Reduction of num1*num2 is:\t0x%016lx%016lx%016lx%016lx\n", rans_double[3], rans_double[2], rans_double[1], rans_double[0]);

}

