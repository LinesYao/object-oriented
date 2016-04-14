#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<iostream>
using namespace std;




int main(int argc, char* argv[]) 
{
	//string input;  //接收键盘输入的表达式 
	//cin>>input; 
	
	Scan sc;
	queue<string> q = sc.toStringQueue(sc.judge(argc,argv)); 
    //queue<string> q = sc.toStringQueue(input);  //存放获取的队列 

	Print pr;
	pr.printQue(q ,sc.isPrint);
	

	Calculation cal;
	cal.getResult(q);
	
	return 0;
}
