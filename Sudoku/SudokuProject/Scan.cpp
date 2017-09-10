#include"Scan.h"
#include<cstdio>
#include<cstring>
int Scan::read_check(int argc, char* argv[]) {
	int type = 0, num = 0;
	if (argc != 3) {
		type = 1;
	}
	else {
		if (strcmp(argv[1], "-c")) type = 2;
		else {
			len = strlen(argv[2]);
			if (len > 7 || (argv[2][0]<'0'&&argv[2][0]>'9')) type = 3;
			else {
				for (int i = 0;i < len;++i) {
					if (!(argv[2][i] >= '0'&&argv[2][i] <= '9')) {
						type = 3; break;
					}
					num = num * 10 + argv[2][i] - '0';
				}
				if (num > upper_limit) printf("���棺����ֵ����%d\n", upper_limit);
			}
		}
	}
	switch (type) {
	case 1:
		puts("������������!"); break;
	case 2:
		puts("������ʽ����!"); break;
	case 3:
		printf("����ֵ���Ϸ�����������ֵ��ΧΪ%d-%d������!\n", lower_limit, upper_limit);
	}
	if(!type) freopen("sudoku.out", "w", stdout);
	return type ? -1 : num;
}

