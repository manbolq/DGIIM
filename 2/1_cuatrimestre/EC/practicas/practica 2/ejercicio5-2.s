.section .data 
#ifndef TEST
#define TEST 6
#endif 
 .macro linea    #  Resultado - Comentario 
  #if  TEST==1    // 16 – ejemplo muy sencillo 
  .int 1,1,1,1 
#elif  TEST==2    // 0x0 ffff fff0, casi acarreo 
  .int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff 
#elif  TEST==3
  .int 0x10000000, 0x10000000, 0x10000000, 0x10000000
#elif  TEST==4
  .int 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF
#elif  TEST==5
  .int -1, -1, -1, -1
#elif  TEST==6
  .int 200000000, 200000000, 200000000, 200000000
#elif  TEST==7    
  .int 300000000, 300000000, 300000000, 300000000
#elif  TEST==8
  .int 5000000000, 5000000000, 5000000000, 5000000000
#else 
 .error "Definir TEST entre 1..8" 
#endif 
 .endm 

lista: 	.irpc   i,1234 
		linea 
	.endr
longlista:	.int   (.-lista)/4
resultado:	.quad   0
formato: .ascii "resultado \t =   %18lu (uns)\n" 
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
#########################################################################

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
        syscall

	ret

suma:
	mov  $0, %eax
	mov  $0, %rsi
	mov  $0, %edx
bucle:
	add  (%rbx,%rsi,4), %eax
	adc   $0, %edx
	inc   %rsi
	cmp   %rsi,%rcx
	jne    bucle
	ret
