/*****************************************
Author:是光不是yao
Function List:
		printQue  打印接收的队列

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