#pragma once
#ifndef __SUDO_H_
#define __SUDO_H_
class Sudo {
public:
	int ans_cnt ,need;
	int a[85], blo[85], vis[85];
	int col_vis[11][11], blo_vis[11][11];

	void solve(int n);
	void init(int n);
	void dfs(int num, int row);
private:
	int FIR = (2+4)%9+1;
	int fir[15] = { 1,4,7,28,31,34,55,58,61 };
	int add[15] = { 1,2,9,10,11,18,19,20 };
};
#endif // !__SUDO_H_
