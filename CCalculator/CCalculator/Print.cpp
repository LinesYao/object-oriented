#include"Print.h"
#include<string>
using namespace std;

void Print::print(int flag, string res)
{
	if (flag == -1)
	{
		cout << res << endl;
	}
	else
	{
		Print::printError(flag);
	}
}

void Print::printError(int flag)
{

	switch (flag)
	{
	case 1:
		cout << "ERROR : divided by zero " << endl;
		break;
	case 2:
		cout << "ERROR : 输入的数字超过十位（包括小数位）" << endl;
		break;
	case 3:
		cout << "ERROR : () don't match" << endl;
		break;
	}
}


void Print::printQue(queue<string> que)
{
	while (!que.empty())
	{
		cout << que.front();
		que.pop();
	}
	cout << "= ";

}



void Print::write(string outpath, int flag, string res,ofstream &out)
{
	
	switch (flag)
	{
	case -1:
	
		out << res << endl;
		break;
	case 1:
		out << "ERROR : divided by zero " << endl;
		
		break;
	case 2:
		out << "ERROR : 输入的数字超过十位（包括小数位）" << endl;
	
		break;
	case 3:
		out << "ERROR : () don't match" << endl;
		
		break;
	}
	
}
