#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<iostream>
using namespace std;




int main(int argc, char* argv[]) 
{
	//string input;  //���ռ�������ı��ʽ 
	//cin>>input; 
	
	Scan sc;
	queue<string> q = sc.toStringQueue(sc.judge(argc,argv)); 
    //queue<string> q = sc.toStringQueue(input);  //��Ż�ȡ�Ķ��� 

	Print pr;
	pr.printQue(q);
	

	Calculation cal;
	cal.getResult(q);
	
	return 0;
}
