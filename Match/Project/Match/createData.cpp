#include "createData.h"
#include "json.h"
#include "Constant.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace Json;

/*
void createData::print() {
	srand((unsigned)time(NULL));
	int vis[3][9];
	Value root;
	Value stu;
	Value dept;
	string dno = "D0";
	int too_small = 0;
	string sno = "031502";
	int flag[8][8], f[25], ff[3][9];
	for (int i = 0;i < 20;++i) {
		Value temp_dep;
		string dno_tmp = dno;
		if (i < 10) dno_tmp += "0";
		dno_tmp += "" + i;
		temp_dep[Dno] = dno;

		int t = (rand() % 5)+10;
		temp_dep[Dnum] = t;

		int r = rand() % 6;
		memset(flag, 0, sizeof flag);
		string free_time = "";
		for (int j = 0;j < r;++j) {
			free_time = "";
			int t = rand() % 7;
			free_time += week[t] + ".";
			int tt = rand() % 6;
			if (flag[t][tt]) {
				tt = (2 * rand() + 5) % 6;
			}
			if (flag[t][tt]) continue;
			free_time += freetime[tt];
			flag[t][tt] = 1;
			temp_dep[Dsche].append(free_time);
		}


		int t = rand() % 3;
		memset(ff, 0, sizeof ff);
		string tagtmp = "";
		for (int i = 0;i < r;++i) {
			tagtmp = "";
			int tt = rand() % 8;
			if (ff[tt])
				int t = (2 * rand() + 7) % 8;
			if (f[t]) {
				t = (3 * rand() + 5) % 8;
				if (f[t]) continue;
			}
			tagtmp += tag[t][tt];
			temp_dep[Dtag].append(tagtmp);
			vis[t][tt] = 1;
			f[tt] = 1;
		}
		dept.append(temp_dep);

	}


	
	for (int i = 0;i < 300;i++) {
		Value temp_stu;
		string sno_tmp=sno;
		if (i < 10) sno_tmp += "0";
		if (i < 100) sno_tmp += "0";
		sno_tmp += "" + i;
		temp_stu[Sno] = sno;
		int r = (rand()+7) % 10;
		if (r < 2) ++too_small;
		if (too_small >= 15) {
			r = (rand() + 7) % 10;
		}
		memset(flag, 0, sizeof flag);
		string free_time = "";
		for (int j = 0;j < r;++j) {
			free_time = "";
			int t = rand() % 7;
			free_time += week[t]+".";
			int tt = rand() % 6;
			if (flag[t][tt]) {
				tt = (2*rand()+5) % 6;
			}
			if (flag[t][tt]) continue;
			free_time += freetime[tt];
			flag[t][tt] = 1;
			temp_stu[Sfree].append(free_time);
		}

		string dep = "D0";
		r = rand() % 5;
		memset(f, 0, sizeof f);
		for (int i = 0;i < r;++i) {
			int t = (2 * rand() + 7) % 20;
			if (f[t]) {
				t = (3 * rand() + 5) % 20;
				if (f[t]) continue;
			}
			if (t < 10) dep += "0";
			dep += "" + t;
			temp_stu[Sdept].append(dep);
			f[t] = 1;
		}

		
		
		r = rand() % 6;
		
		memset(ff, 0, sizeof ff);
		for (int i = 0;i < r;++i) {
			int t = rand() % 3;
			int tt = rand() % 8;
			if (!vis[t][tt]) continue;
			if (ff[t][tt]) {
				int t = (2 * rand() + 7) % 20;
				if (f[t]) {
					t = (3 * rand() + 5) % 20;
					if (f[t]) continue;
				}
			}
			if (ff[t][tt]) continue;
			ff[t][tt] = 1;
			
			
			temp_stu[Stag].append(tag[t][tt]);
		}
		stu.append(temp_stu);
	}


	root[Stu] = stu;
	root[Dept] = dept;

	cout << root << endl;
}
*/