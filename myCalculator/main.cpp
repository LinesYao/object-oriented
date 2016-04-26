#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<iostream>
using namespace std;


int main(int argc, char* argv[]) 
{

	string input;	//接收键盘输入的表达式 	
	Scan sc;
	//cin>>input; 
	
	if(argc == 2)
	{
		input = argv[1];
	}
	else if(argc > 2)
	{
		sc.isPrint = true;
		input = argv [argc-1];
	} 

        queue<string> q = sc.toStringQueue(input);  //存放获取的队列 

	Print pr;
	pr.printQue(q);
	

	Calculation cal;
	cal.getResult(q);
	
	return 0;
}
