.section .data

#ifndef TEST
#define TEST 20
#endif

.macro linea 
  #if   TEST==1  //Cíclicamente 1, 2...
            .int 1, 2, 1, 2
  #elif TEST==2  //Cíclicamente -1, -2...
            .int -1, -2, -1, -2

#EJEMPLOS FÁCILES DE CALCULAR EN HEXADECIMAL
  #elif TEST==3 //positivo grande
            .int 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff
  #elif TEST==4 //negativo grande
            .int 0x80000000, 0x80000000, 0x80000000, 0x80000000
  #elif TEST==5 //negativo más pequeño
            .int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
            
#EJEMPLOS FÁCILES DE CACULAR EN DECIMAL
  #elif TEST==6
            .int 2000000000, 2000000000, 2000000000, 2000000000
  #elif TEST==7
            .int 3000000000, 3000000000, 3000000000, 3000000000
  #elif TEST==8 
            .int -2000000000, -2000000000, -2000000000, -2000000000
  #elif TEST==9
            .int -3000000000, -3000000000, -3000000000, -3000000000
            
#EJEMPLOS FÁCILES DECIMAL: DIVISION EUCL. VS TRUNC.
  #elif TEST>=10 && TEST<=14
            .int 1, 1, 1, 1
  #elif TEST>=15 && TEST<=19
            .int -1, -1, -1, -1
  #else
      .error "Definir TEST entre 1..19"
  #endif
      .endm

.macro linea0
  #if   TEST>=1 && TEST<=9
            linea
  #elif TEST==10
            .int 0, 2, 1, 1
  #elif TEST==11
            .int 1, 2, 1, 1          
  #elif TEST==12
            .int 8, 2, 1, 1          
  #elif TEST==13
            .int 15, 2, 1, 1  
  #elif TEST==14
            .int 16, 2, 1, 1
  #elif TEST==15
            .int 0, -2, -1, -1
  #elif TEST==16
            .int -1, -2, -1, -1
  #elif TEST==17
            .int -8, -2, -1, -1
  #elif TEST==18
            .int -15, -2, -1, -1          
  #elif TEST==19
            .int -16, -2, -1, -1
  #else
      .error "Definir TEST entre 1..19"
  #endif
      .endm
      

lista:  linea0 
	 .irpc i,123 
 	 linea 
      .endr 

longlista:	.int   (.-lista)/4
resultado:	.quad	0
cociente:	.int	0
resto:		.int	0

formato:
	.ascii "media \t = %11d \t resto \t = %11d   \n" 
  	.asciz  "\t = 0x%08x \t    \t = 0x%08x\n"

# opción: 1) no usar printf, 2)3) usar printf/fmt/exit, 4) usar tb main
# 1) as  suma.s -o suma.o
#    ld  suma.o -o suma					1232 B
# 2) as  suma.s -o suma.o				6520 B
#    ld  suma.o -o suma -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2
# 3) gcc suma.s -o suma -no-pie –nostartfiles		6544 B
# 4) gcc suma.s -o suma	-no-pie				8664 B

.section .text
#_start: .global _start
main: .global  main

	mov     $lista, %rbx
        mov  longlista, %ecx
        call suma               # == suma(&lista, longlista);
        mov %eax, resultado
        mov %edx, resultado+4
        idiv  %ecx
        mov %eax, cociente
        mov %edx, resto

	mov   $formato, %rdi
        mov   cociente,%rsi
        mov   resto,%rdx
        mov   cociente,%rcx
        mov   resto,%r8
        mov          $0,%eax    # varargin sin xmm
        call  printf            # == printf(formato, res, res);

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

imprim_C:			# requiere libC
	mov   $formato, %rdi
	mov   cociente,%rsi
	mov   resto,%rdx
	mov   cociente,%rcx
	mov   resto,%r8
	mov          $0,%eax	# varargin sin xmm
	ccall  printf		# == printf(formato, res, res);
	ret
