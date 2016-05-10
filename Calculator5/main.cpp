#include"Scan.h"
#include"Print.h"
#include"Calculation.h"
#include<iostream>
#include<string.h>
#include<fstream> 
#include<stdlib.h>
using namespace std;


int main(int argc, char* argv[]) 
{

	string input;	//接收键盘输入的表达式 	
	Scan sc;
	//cin>>input; 
	
	Print pr;
	
	queue<string> q ;
	
	Calculation cal;
	
	if (argc == 2)
	{
		pr.isPrint = true ;
		input = argv[1];
		q = sc.toStringQueue(input);
		pr.printt(sc.clearQue(),cal.getResult(q));
	}
	else if (argc == 3 && strcmp(argv[1],"-a") == 0 )
	{	

		pr.isPrint = true ;
		input = argv [argc-1];	
		q = sc.toStringQueue(input);
		pr.printQue(q);
		pr.printt(sc.clearQue(),cal.getResult(q));
	
	} 
	else if (argc == 4 && strcmp(argv[1],"-f") == 0) 
	{

		ifstream in(argv[2],ios::in);   //为读入而打开文件 	
		ofstream out(argv[3],ios::out);  //为写而打开文件
		string s;
		while(getline(in,s))
		{
			input = s;
			q = sc.toStringQueue(input);  //存放获取的队列 	
			
			out << pr.printt(sc.clearQue(),cal.getResult(q))<<endl;
	
		}
			in.close(); 
			out.close();	
	}
	
	return 0;
}
