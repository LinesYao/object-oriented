#include"Print.h">
using namespace std;


void Print::printQue(queue<string> que)
{
	int size = que.size();  //��Ŷ��еĴ�С 
	
	/*�����зǿ�ʱ��ӡ���У�������Ϊ�������벻��*/ 
	if (!que.empty())
	{
		for (int i=0; i< size; i++)
		{
			cout << que.front() << endl;
			que.pop();
		}
	}
	
	
	
}
