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

	void print(string res);

	string getInfomation(int flag, string res);

	void write(string res,ofstream &out);

};