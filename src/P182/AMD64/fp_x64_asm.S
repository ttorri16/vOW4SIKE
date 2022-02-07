//*******************************************************************************************
// SIDH: an efficient supersingular isogeny cryptography library
//
// Abstract: field arithmetic in x64 assembly for P434 on Linux
//*******************************************************************************************  

.intel_syntax noprefix 

// Registers that are used for parameter passing:
#define reg_p1  rdi
#define reg_p2  rsi
#define reg_p3  rdx

// Define addition instructions
#ifdef _MULX_
#ifdef _ADX_

#define ADD1    adox
#define ADC1    adox
#define ADD2    adcx
#define ADC2    adcx

#else

#define ADD1    add
#define ADC1    adc
#define ADD2    add
#define ADC2    adc

#endif    
#endif

.text

// p182
p182:
.quad  0xffffffffffffffff
.quad  0xd9a6c7b117ffffff
.quad  0x2895ac20d5040b

// 2 * p182
p182x2:
.quad  0xfffffffffffffffe
.quad  0xb34d8f622fffffff
.quad  0x512b5841aa0817

// p182 + 1
p182p1:
.quad  0x0000000000000000
.quad  0xd9a6c7b118000000
.quad  0x2895ac20d5040b


//***********************************************************************
//  Field addition
//  Operation: c [reg_p3] = a [reg_p1] + b [reg_p2]
//*********************************************************************** 
.global fpadd182_asm
fpadd182_asm:
  // push   r12
  // push   r13
  // push   r14
  // push   r15
  // push   rbx
  // push   rbp
  
  xor    rax, rax
  mov    r8, [reg_p1]
  mov    r9, [reg_p1+8]
  mov    r10, [reg_p1+16]
  // mov    r11, [reg_p1+24]
  // mov    r12, [reg_p1+32]
  // mov    r13, [reg_p1+40]
  // mov    r14, [reg_p1+48]
  add    r8, [reg_p2] 
  adc    r9, [reg_p2+8] 
  adc    r10, [reg_p2+16] 
  // adc    r11, [reg_p2+24] 
  // adc    r12, [reg_p2+32] 
  // adc    r13, [reg_p2+40] 
  // adc    r14, [reg_p2+48]

  mov    rbx, [rip+p182x2]
  sub    r8, rbx
  mov    rcx, [rip+p434x2+8]
  sbb    r9, rcx
  mov    rdi, [rip+p434x2+16]
  sbb    r10, rdi
  // mov    rdi, [rip+p434x2+24]
  // sbb    r11, rdi
  // mov    rsi, [rip+p434x2+32]
  // sbb    r12, rsi
  // mov    rbp, [rip+p434x2+40]
  // sbb    r13, rbp
  // mov    r15, [rip+p434x2+48]
  // sbb    r14, r15
  sbb    rax, 0
  
  and    rbx, rax
  and    rcx, rax
  and    rdi, rax
  // and    rsi, rax
  // and    rbp, rax
  // and    r15, rax
  
  add    r8, rbx  
  adc    r9, rcx  
  adc    r10, rdi  
  // adc    r11, rdi 
  // adc    r12, rsi 
  // adc    r13, rbp   
  // adc    r14, r15
  mov    [reg_p3], r8
  mov    [reg_p3+8], r9 
  mov    [reg_p3+16], r10 
  // mov    [reg_p3+24], r11
  // mov    [reg_p3+32], r12 
  // mov    [reg_p3+40], r13 
  // mov    [reg_p3+48], r14
  
  // pop    rbp
  // pop    rbx
  // pop    r15
  // pop    r14
  // pop    r13
  // pop    r12
  ret


//***********************************************************************
//  Field subtraction
//  Operation: c [reg_p3] = a [reg_p1] - b [reg_p2]
//*********************************************************************** 
.global fpsub182_asm
fpsub182_asm:
  // push   r12
  // push   r13
  // push   r14
  
  xor    rax, rax
  mov    r8, [reg_p1]
  mov    r9, [reg_p1+8]
  mov    r10, [reg_p1+16]
  // mov    r11, [reg_p1+24]
  // mov    r12, [reg_p1+32]
  // mov    r13, [reg_p1+40]
  // mov    r14, [reg_p1+48]
  sub    r8, [reg_p2] 
  sbb    r9, [reg_p2+8] 
  sbb    r10, [reg_p2+16] 
  // sbb    r11, [reg_p2+24] 
  // sbb    r12, [reg_p2+32] 
  // sbb    r13, [reg_p2+40] 
  // sbb    r14, [reg_p2+48]
  sbb    rax, 0
  
  mov    rcx, [rip+p182x2]
  mov    rdi, [rip+p182x2+8]
  mov    rsi, [rip+p182x2+16]
  and    rcx, rax
  and    rdi, rax
  and    rsi, rax  

  add    r8, rcx  
  adc    r9, rdi  
  adc    r10, rsi  
  // adc    r11, rsi 
  mov    [reg_p3], r8
  mov    [reg_p3+8], r9 
  mov    [reg_p3+16], r10 
  // mov    [reg_p3+24], r11 
  // setc   cl  

  // mov    r8, [rip+p182x2+32]
  // mov    rdi, [rip+p182x2+40]
  // mov    rsi, [rip+p182x2+48]
  // and    r8, rax
  // and    rdi, rax
  // and    rsi, rax  
  // bt     rcx, 0  
  // adc    r12, r8 
  // adc    r13, rdi   
  // adc    r14, rsi
  // mov    [reg_p3+32], r12 
  // mov    [reg_p3+40], r13
  // mov    [reg_p3+48], r14
  
  // pop    r14
  // pop    r13
  // pop    r12
  ret

//      reg_p2 16   regp2 8  reg_p2
//  x   reg_p1 16   regp1 8  reg_p1

//      reg_p2 16   regp2 8  reg_p2
//  x   reg_p1 16   regp1 8     r8

// .global mul182_asm
// mul182_asm:    
//   xor    r10, r10
//   mov    rcx, reg_p3
  
//   mov    rax, [reg_p2]
//   mov    r8, [reg_p1]
//   mul    r8
//   mov    [rcx], rax        // c0
//   mov    r9, rdx
  
//   mov    rax, [reg_p2+8]
//   mul    r8
//   add    r9, rax
//   adc    r10, rdx
  
//   xor    r11, r11
//   mov    rax, [reg_p2]
//   mov    r8, [reg_p1+8] 
//   mul    r8
//   add    r9, rax
//   mov    [rcx+8], r9       // c1 
//   adc    r10, rdx
//   adc    r11, 0
  
//   mov    rax, [reg_p2+8]
//   mul    r8
//   add    r10, rax          
//   adc    r11, rdx         
//   mov    [rcx+16], r10      // c2 
//   mov    [rcx+24], r11      // c3 
//   ret


// //***********************************************************************
// //  Montgomery reduction
// //  Based on comba method
// //  Operation: c [reg_p2] = a [reg_p1]                                                      
// //  NOTE: a=c is not allowed
// //*********************************************************************** 
// .global rdc434_asm
// rdc434_asm:

//   ret

// // # error "CONFIGURATION NOT SUPPORTED. TRY USE_MULX=TRUE"

// //   #endif


// //***********************************************************************
// //  434-bit multiprecision addition
// //  Operation: c [reg_p3] = a [reg_p1] + b [reg_p2]
// //*********************************************************************** 
// .global mp_add434_asm
// mp_add434_asm: 
//   mov    r8, [reg_p1]
//   mov    r9, [reg_p1+8]
//   mov    r10, [reg_p1+16]
//   mov    r11, [reg_p1+24]
//   add    r8, [reg_p2] 
//   adc    r9, [reg_p2+8] 
//   adc    r10, [reg_p2+16] 
//   adc    r11, [reg_p2+24] 
//   mov    [reg_p3], r8
//   mov    [reg_p3+8], r9
//   mov    [reg_p3+16], r10
//   mov    [reg_p3+24], r11
  
//   mov    r8, [reg_p1+32]
//   mov    r9, [reg_p1+40]
//   mov    r10, [reg_p1+48]
//   adc    r8, [reg_p2+32] 
//   adc    r9, [reg_p2+40] 
//   adc    r10, [reg_p2+48] 
//   mov    [reg_p3+32], r8
//   mov    [reg_p3+40], r9
//   mov    [reg_p3+48], r10
//   ret


// //***************************************************************************
// //  2x434-bit multiprecision subtraction/addition
// //  Operation: c [reg_p3] = a [reg_p1] - b [reg_p2]. If c < 0, add p434*2^448
// //*************************************************************************** 
// .global mp_subadd434x2_asm
// mp_subadd434x2_asm:
//   push   r12
//   push   r13 
//   push   r14 
//   push   r15 
//   xor    rax, rax
//   mov    r8, [reg_p1]
//   mov    r9, [reg_p1+8]
//   mov    r10, [reg_p1+16]
//   mov    r11, [reg_p1+24]
//   mov    r12, [reg_p1+32]
//   sub    r8, [reg_p2] 
//   sbb    r9, [reg_p2+8] 
//   sbb    r10, [reg_p2+16] 
//   sbb    r11, [reg_p2+24] 
//   sbb    r12, [reg_p2+32] 
//   mov    [reg_p3], r8
//   mov    [reg_p3+8], r9
//   mov    [reg_p3+16], r10
//   mov    [reg_p3+24], r11
//   mov    [reg_p3+32], r12

//   mov    r8, [reg_p1+40]
//   mov    r9, [reg_p1+48]
//   mov    r10, [reg_p1+56] 
//   mov    r11, [reg_p1+64]
//   mov    r12, [reg_p1+72] 
//   sbb    r8, [reg_p2+40] 
//   sbb    r9, [reg_p2+48] 
//   sbb    r10, [reg_p2+56]
//   sbb    r11, [reg_p2+64] 
//   sbb    r12, [reg_p2+72]
//   mov    [reg_p3+40], r8
//   mov    [reg_p3+48], r9
//   mov    [reg_p3+56], r10
  
//   mov    r13, [reg_p1+80]
//   mov    r14, [reg_p1+88] 
//   mov    r15, [reg_p1+96]
//   mov    rcx, [reg_p1+104]
//   sbb    r13, [reg_p2+80]
//   sbb    r14, [reg_p2+88]
//   sbb    r15, [reg_p2+96] 
//   sbb    rcx, [reg_p2+104] 
//   sbb    rax, 0
  
//   // Add p434 anded with the mask in rax 
//   mov    r8, [rip+p434]
//   mov    r9, [rip+p434+24]
//   mov    r10, [rip+p434+32]
//   mov    rdi, [rip+p434+40]
//   mov    rsi, [rip+p434+48]
//   and    r8, rax
//   and    r9, rax
//   and    r10, rax
//   and    rdi, rax
//   and    rsi, rax
//   mov    rax, [reg_p3+56]
//   add    rax, r8
//   adc    r11, r8
//   adc    r12, r8
//   adc    r13, r9
//   adc    r14, r10
//   adc    r15, rdi
//   adc    rcx, rsi
  
//   mov    [reg_p3+56], rax
//   mov    [reg_p3+64], r11
//   mov    [reg_p3+72], r12
//   mov    [reg_p3+80], r13
//   mov    [reg_p3+88], r14
//   mov    [reg_p3+96], r15
//   mov    [reg_p3+104], rcx
//   pop    r15
//   pop    r14
//   pop    r13
//   pop    r12
//   ret


// //***********************************************************************
// //  Double 2x434-bit multiprecision subtraction
// //  Operation: c [reg_p3] = c [reg_p3] - a [reg_p1] - b [reg_p2]
// //*********************************************************************** 
// .global mp_dblsub434x2_asm
// mp_dblsub434x2_asm:
//   push   r12
//   push   r13
  
//   xor    rax, rax
//   mov    r8, [reg_p3]
//   mov    r9, [reg_p3+8]
//   mov    r10, [reg_p3+16]
//   mov    r11, [reg_p3+24]
//   mov    r12, [reg_p3+32]
//   mov    r13, [reg_p3+40]
//   mov    rcx, [reg_p3+48]
//   sub    r8, [reg_p1]
//   sbb    r9, [reg_p1+8] 
//   sbb    r10, [reg_p1+16] 
//   sbb    r11, [reg_p1+24] 
//   sbb    r12, [reg_p1+32] 
//   sbb    r13, [reg_p1+40] 
//   sbb    rcx, [reg_p1+48]
//   adc    rax, 0
//   sub    r8, [reg_p2]
//   sbb    r9, [reg_p2+8] 
//   sbb    r10, [reg_p2+16] 
//   sbb    r11, [reg_p2+24] 
//   sbb    r12, [reg_p2+32] 
//   sbb    r13, [reg_p2+40] 
//   sbb    rcx, [reg_p2+48]
//   adc    rax, 0  
//   mov    [reg_p3], r8
//   mov    [reg_p3+8], r9
//   mov    [reg_p3+16], r10
//   mov    [reg_p3+24], r11
//   mov    [reg_p3+32], r12
//   mov    [reg_p3+40], r13
//   mov    [reg_p3+48], rcx
    
//   mov    r8, [reg_p3+56]
//   mov    r9, [reg_p3+64]
//   mov    r10, [reg_p3+72]
//   mov    r11, [reg_p3+80]
//   mov    r12, [reg_p3+88]
//   mov    r13, [reg_p3+96]
//   mov    rcx, [reg_p3+104]
//   sub    r8, rax 
//   sbb    r8, [reg_p1+56] 
//   sbb    r9, [reg_p1+64] 
//   sbb    r10, [reg_p1+72] 
//   sbb    r11, [reg_p1+80] 
//   sbb    r12, [reg_p1+88] 
//   sbb    r13, [reg_p1+96] 
//   sbb    rcx, [reg_p1+104]
//   sub    r8, [reg_p2+56] 
//   sbb    r9, [reg_p2+64] 
//   sbb    r10, [reg_p2+72] 
//   sbb    r11, [reg_p2+80] 
//   sbb    r12, [reg_p2+88] 
//   sbb    r13, [reg_p2+96] 
//   sbb    rcx, [reg_p2+104] 
//   mov    [reg_p3+56], r8
//   mov    [reg_p3+64], r9
//   mov    [reg_p3+72], r10
//   mov    [reg_p3+80], r11
//   mov    [reg_p3+88], r12
//   mov    [reg_p3+96], r13
//   mov    [reg_p3+104], rcx
  
//   pop    r13
//   pop    r12
//   ret
