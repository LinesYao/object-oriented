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
#include<fstream>
using namespace std;

class Scan
{
public:

	bool isTrue = true;   //�ж������Ƿ���ȷ��Ŀǰʵ���ж�����������Ƿ񳬹�ʮλ ������Ϊ false�� 

	queue<string> toStringQueue(string input);

	void clearQue();

	int getFlag();

	void read(string inpath , string outpath);

private:

	int flag;   //���������Ϣ

	queue<string> inputQue;  //��ű��ʽ�����Ķ��� 
	



};