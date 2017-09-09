#include"sudo.h"
#include"Scan.h"
#include<cstdio>
#include<cstdlib>

int main(int argc ,char* argv[]) {
	Sudo sd;
	Scan sc;
	int n = sc.read_check(argc, argv);
	sd.solve(n);
	return 0;
}
