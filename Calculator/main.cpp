#include"Scan.h"
#include"Print.h">
using namespace std;



int main() 
{
	string input;  //接收键盘输入的表达式 
	cin>>input;
	
	Scan sc;
    sc.ToStringQueue(input) ;
    queue<string> q = sc.getQue();  //存放获取的队列 

	Print pr;
	pr.printQue(q);


	return 0;
}

