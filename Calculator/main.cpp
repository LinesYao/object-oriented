#include"Scan.h"
#include"Print.h">
using namespace std;



int main() 
{
	string input;  //���ռ�������ı��ʽ 
	cin>>input;
	
	Scan sc;
    sc.ToStringQueue(input) ;
    queue<string> q = sc.getQue();  //��Ż�ȡ�Ķ��� 

	Print pr;
	pr.printQue(q);


	return 0;
}

