#pragma once
#ifndef __SCAN_H_
#define __SCAN_H_
#include<string>
using namespace std;
class Scan {
public:
	int len;
	int read_check(int argc, char* argv[]);
	string file_path;
private:
	int upper_limit = 1000000, lower_limit = 0;
	string file_name = "sudoku.txt";
};
#endif // !__SCAN_H_
