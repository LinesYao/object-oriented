/****************************************************************************
    Author:�ǹⲻ��yao  
	Function List:
		1. toStringQueue 	����һ������������ʽ�������ʽ��Ӧ��ִ������ 
		2. getQue  	��ȡ���ʽ�����Ķ��� 	
****************************************************************************/

#include<iostream>
#include<stack> 
#include<string>
#include<queue>
using namespace std;

class Scan
{
	public:
		
		bool isTrue = true;   //�ж������Ƿ���ȷ��Ŀǰʵ���ж�����������Ƿ񳬹�ʮλ ������Ϊ false�� 
		bool isPrint = false; 
	
	
		queue<string> toStringQueue(string input);  
		
		string  judge(int argc,char* argv[]); 
	
		
		 
	
		
	private:
		
		queue<string> inputQue;  //��ű��ʽ�����Ķ��� 
	
		
		
};
