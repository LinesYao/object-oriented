#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Scan
{
	public:
		
		bool isTrue = true;   //�ж������Ƿ���ȷ��Ŀǰʵ���ж�����������Ƿ񳬹�ʮλ ������Ϊ false�� 
		
		/*
			����һ������������ʽ�������ʽ��Ӧ��ִ������ 
		*/ 
		void ToStringQueue(string input);  
		
		
		/*
			��ȡ���ʽ�����Ķ��� 
		*/ 
		queue<string> getQue();  
	
		
	private:
		
		queue<string> inputQue;  //��ű��ʽ�����Ķ��� 
	
		
		
};
