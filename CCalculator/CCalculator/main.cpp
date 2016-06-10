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
	Print pr;
	Calculation cal;
	queue<string> q;

	
	if (argc == 2)
	{
		input = argv[1];
		q = sc.toStringQueue(input);
		sc.clearQue();
		pr.print(sc.getFlag(), cal.getResult(q));
	}
	else if (argc == 3 && strcmp(argv[1], "-a") == 0)
	{
		input = argv[argc - 1];
		q = sc.toStringQueue(input);
		pr.printQue(q);
		sc.clearQue();
		pr.print(sc.getFlag(), cal.getResult(q));
	}
	else if (argc == 4 && strcmp(argv[1], "-f") == 0)
	{
		sc.read(argv[2], argv[3]);
		
	}

	return 0;
}