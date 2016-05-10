/*****************************************
    Author:是光不是yao  
	Function List: 
	        printQue  打印接收的队列 
		   
*****************************************/

#include<iostream>
#include<queue>
using namespace std;

class Print
{
	public:
	
		int flag;
		bool isPrint = false;
	
		void printQue(queue<string> que);
		string printt(int flag ,string res);
	
};
