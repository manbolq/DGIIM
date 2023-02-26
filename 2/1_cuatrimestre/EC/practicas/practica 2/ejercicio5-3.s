.section .data 
#ifndef TEST 
#define TEST 8
#endif 
 .macro linea    #  Resultado - Comentario 
  #if  TEST==1    // 16 – ejemplo muy sencillo 
  .int -1,-1,-1,-1 
#elif  TEST==2    // 0x0 ffff fff0, casi acarreo 
  .int 0x04000000, 0x04000000, 0x04000000, 0x04000000
#elif  TEST==3
  .int 0x08000000, 0x08000000, 0x08000000, 0x08000000
#elif  TEST==4
  .int 0x10000000, 0x10000000, 0x10000000, 0x10000000
#elif  TEST==5
  .int 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF
#elif  TEST==6
  .int 0x80000000, 0x80000000, 0x80000000, 0x80000000
#elif  TEST==7    
  .int 0xF0000000, 0xF0000000, 0xF0000000, 0xF0000000
#elif  TEST==8
  .int 0xF8000000, 0xF8000000, 0xF8000000, 0xF8000000
#elif  TEST==9
  .int 0xF7FFFFFF, 0xF7FFFFFF, 0xF7FFFFFF, 0xF7FFFFFF
#elif  TEST==10
  .int 100000000, 100000000, 100000000, 100000000
#elif  TEST==11
  .int 200000000, 200000000, 200000000, 200000000
#elif  TEST==12
  .int 300000000, 300000000, 300000000, 300000000
#elif  TEST==13
  .int 2000000000, 2000000000, 2000000000, 2000000000
#elif  TEST==14
  .int 3000000000, 3000000000, 3000000000, 3000000000
#elif  TEST==15
  .int -100000000, -100000000, -100000000, -100000000
#elif  TEST==16
  .int -200000000, -200000000, -200000000, -200000000
#elif  TEST==17
  .int -300000000, -300000000, -300000000, -300000000
#elif  TEST==18
  .int -2000000000, -2000000000, -2000000000, -2000000000
#elif  TEST==19
  .int -3000000000, -3000000000, -3000000000, -3000000000
  
#else 
 .error "Definir TEST entre 1..8" 
#endif 
 .endm 

lista:  .irpc i,1234 
  	     linea 
	.endr 
longlista:	.int   (.-lista)/4
resultado:	.quad   0
formato: .ascii "resultado \t =   %18ld (sgn)\n" 
         .ascii    "\t\t = 0x%18lx (hex)\n" 
         .asciz    "\t\t = 0x %08x %08x \n" 

########################################################################
# opción: 1) no usar printf, 2)3) usar printf/fmt/exit, 4) usar tb main
# 1) as  suma.s -o suma.o
#    ld  suma.o -o suma					1232 B
# 2) as  suma.s -o suma.o				6520 B
#    ld  suma.o -o suma -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2
# 3) gcc suma.s -o suma -no-pie –nostartfiles		6544 B
# 4) gcc suma.s -o suma	-no-pie				8664 B
########################################################################

.section .text
#_start: .global _start
main: .global  main

	mov     $lista, %rbx
        mov  longlista, %ecx
        call suma               # == suma(&lista, longlista);
        mov  %eax, resultado
        mov  %edx, resultado+4

	mov   $formato, %rdi
        mov   resultado,%rsi
        mov   resultado,%rdx
        mov          $0,%eax    # varargin sin xmm
        call  printf

	mov        $60, %rax
        mov  resultado, %edi
        syscall                 # == _exit(resultado)

	ret

suma:
	mov  $0, %eax
	mov  $0, %rsi
	mov  $0, %edx
	mov  $0, %ebp
	mov  $0, %edi
bucle:
	mov  (%rbx,%rsi,4), %eax
	CDQ
	add   %eax, %ebp
	adc   %edx, %edi
	inc   %rsi
	cmp   %rsi,%rcx
	jne    bucle
	mov   %edi, %edx
	mov   %ebp, %eax
	ret
