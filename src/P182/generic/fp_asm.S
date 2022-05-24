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
  mov    rcx, [rip+p182x2+8]
  sbb    r9, rcx
  mov    rdi, [rip+p182x2+16]
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
