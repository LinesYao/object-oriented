/****************************************************************************
    Author:是光不是yao  
	Function List:
		1. toStringQueue 	接收一个四则运算表达式，将表达式对应拆分存入队列 
		2. getQue  	获取表达式处理后的队列 	
****************************************************************************/

#include<iostream>
#include<stack> 
#include<string>
#include<queue>
using namespace std;

class Scan
{
	public:
		
		int flag;
		
		bool isTrue = true;   //判断输入是否正确（目前实现判断输入的数字是否超过十位 超过则为 false） 
	
	
		queue<string> toStringQueue(string input);  
	
		int clearQue();
		
	private:
		
		queue<string> inputQue;  //存放表达式处理后的队列 
	
		
		
};
