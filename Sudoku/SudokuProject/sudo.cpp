#include"sudo.h"
#include"Print.h"
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
void Sudo::solve(int n) {
	if (n > 0) {
		init(n);
		dfs(1, 1);
	}
}
void Sudo::init(int n) {
	for (int i = fir[0],cnt=0;cnt<9;i=fir[cnt]) {
		int f = fir[cnt++];
		blo[f] = cnt;
		for (int j = 0;j < 8;++j) {
			blo[f + add[j]] = cnt;
		}
	}
	ans_cnt = 0, need = n;
	memset(a, 0, sizeof a);
	memset(vis, 0, sizeof vis);
	memset(col_vis, 0, sizeof col_vis);
	memset(blo_vis, 0, sizeof blo_vis);
}

void Sudo::dfs(int num, int row) {
	if (num == 9 && row >= 1) {
		Print::print(a,FIR);
		++ans_cnt;
		if (ans_cnt >= need) exit(0);
		return;
	}
	for (int j = 1;j <= 9;++j) {
		int pos = (row - 1) * 9 + j;
		if (vis[pos] || col_vis[num][j] || blo_vis[num][blo[pos]]) continue;
		a[pos] = num, vis[pos] = 1, col_vis[num][j] = 1, blo_vis[num][blo[pos]] = 1;
		if (row == 9) dfs(num + 1, 1);
		else dfs(num, row + 1);
		a[pos] = 0, vis[pos] = 0, col_vis[num][j] = 0, blo_vis[num][blo[pos]] = 0;
	}
}
	