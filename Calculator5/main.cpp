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

	string input;	//���ռ�������ı��ʽ 	
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

		ifstream in(argv[2],ios::in);   //Ϊ��������ļ� 	
		ofstream out(argv[3],ios::out);  //Ϊд�����ļ�
		string s;
		while(getline(in,s))
		{
			input = s;
			q = sc.toStringQueue(input);  //��Ż�ȡ�Ķ��� 	
			
			out << pr.printt(sc.clearQue(),cal.getResult(q))<<endl;
	
		}
			in.close(); 
			out.close();	
	}
	
	return 0;
}
