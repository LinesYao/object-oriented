#pragma once
#ifndef __SCAN_H_
#define __SCAN_H_
class Scan {
public:
	int len;
	int read_check(int argc, char* argv[]);
private:
	int upper_limit = 1000000, lower_limit = 0;
};
#endif // !__SCAN_H_
