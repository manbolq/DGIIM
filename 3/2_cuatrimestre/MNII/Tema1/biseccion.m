#####################################################
#### script para ilustrar el metodo de biseccion ####
#####################################################

clear all; clc; more off; 

function y = f(x)
	y = x^5*pi - 2^x/3^x;
endfunction

a = -1;
b = 1;
eps = 1e-6;

fa = f(a);
db = f(b);

disp('-----------------------------------------------');
disp('------------ METODO DE BISECCION --------------');
disp('-----------------------------------------------');
disp('	n	a	b	m	f(m)	error');

formato = '%3d %6.8f %6.8f %6.8f %9.2e %9.2e\n';

n = 0;

do
	m = (a+b)/2; 
	fm = f(m);
	printf(formato, n, a, b, m, fm, (b-a)/2);

	if fa*fm < 0
		b=m;
		fb = fm;
	else
		a = m;
		fa = fm;
	endif
	n++;
until b-a <= eps


