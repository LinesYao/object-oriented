#include"Print.h"
#include<cstdio>
#include<cstdlib>
#include<cstring>
void Print::print(int* a, int x) {
	int fir = a[1];
	char ans[205];
	int pos = 0,now=1;
	for (int i = 1;i <= 81;++i) {
		if (a[i] == fir) ans[pos++] = '0' + x;
		else if (a[i] == x) ans[pos++] = '0' + fir;
		else ans[pos++] = '0' + (a[now] ? a[now] : 9);
		ans[pos++] = ' ';
		++now;
		if (i % 9 == 0) ans[pos++] = '\n';
	}
	ans[pos++] = '\0';
	puts(ans);
}