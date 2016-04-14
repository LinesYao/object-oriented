#include"Print.h"
#include<string>
using namespace std;



void Print::printQue(queue<string> que ,bool isPrint)
{
	
	
	int size = que.size();  //存放队列的大小 
	
	/*当队列非空时打印队列，队列若为空则输入不符*/ 
	if (!que.empty() && isPrint)
	{
		
		for (int i=0; i< size; i++)
		{
			cout << que.front();
			que.pop();
		}
		cout<<" = ";
	}

}
