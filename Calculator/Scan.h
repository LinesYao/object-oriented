#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Scan
{
	public:
		
		bool isTrue = true;   //判断输入是否正确（目前实现判断输入的数字是否超过十位 超过则为 false） 
		
		/*
			接收一个四则运算表达式，将表达式对应拆分存入队列 
		*/ 
		void ToStringQueue(string input);  
		
		
		/*
			获取表达式处理后的队列 
		*/ 
		queue<string> getQue();  
	
		
	private:
		
		queue<string> inputQue;  //存放表达式处理后的队列 
	
		
		
};
