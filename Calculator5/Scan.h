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
		
		int flag;
		
		bool isTrue = true;   //�ж������Ƿ���ȷ��Ŀǰʵ���ж�����������Ƿ񳬹�ʮλ ������Ϊ false�� 
	
	
		queue<string> toStringQueue(string input);  
	
		int clearQue();
		
	private:
		
		queue<string> inputQue;  //��ű��ʽ�����Ķ��� 
	
		
		
};
