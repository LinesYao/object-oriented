/*****************************************
Author:�ǹⲻ��yao
Function List:
		printQue  ��ӡ���յĶ���

*****************************************/

#include<iostream>
#include<queue>
#include<fstream>
using namespace std;

class Print
{

public:

	void printQue(queue<string> que);

	void print(int flag, string res);

	void printError(int flag);

	void write(string outpath, int flag, string res,ofstream &out);

};