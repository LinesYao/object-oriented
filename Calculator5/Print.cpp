#include"Print.h"
#include<string>
using namespace std;


string Print::printt(int flag ,string res)
{
	
	switch (flag)
	{
		case -1:
			if (isPrint)
			{
				cout << res << endl;
			}
			return res;
			break;
		case 1:
			if (isPrint)
			{
				cout << "ERROR : divided by zero " << endl;
			}
			return "ERROR : divided by zero ";
			break;
		case 2:
			if (isPrint)
			{
				cout << "ERROR : 输入的数字超过十位（包括小数位）" << endl;
			}
			return  "ERROR : 输入的数字超过十位（包括小数位）" ;
			break;
		case 3:
			if (isPrint)
			{
				cout << "ERROR : () don't match" << endl;
			}
			return "ERROR : () don't match" ;
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
