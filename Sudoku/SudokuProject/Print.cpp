#include"Print.h"
#include<cstdio>
#include<cstdlib>
#include<cstring>
void Print::print(int* a,int x) {
	int fir = a[1];
	for (int i = 1;i <= 81;++i) {
		char c = '0';
		if (a[i] == fir) c += x;
		else if (a[i] == x) c += fir;
		else c += (a[i] ? a[i] : 9);
		putchar(c);putchar(' ');
		if (i % 9 == 0) puts("");
	}
	puts("");

}