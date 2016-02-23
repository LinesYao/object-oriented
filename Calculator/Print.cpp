#include"Print.h">
using namespace std;


void Print::printQue(queue<string> que)
{
	int size = que.size();  //存放队列的大小 
	
	/*当队列非空时打印队列，队列若为空则输入不符*/ 
	if (!que.empty())
	{
		for (int i=0; i< size; i++)
		{
			cout << que.front() << endl;
			que.pop();
		}
	}
	
	
	
}
