/****************************************************************************
    Author:�ǹⲻ��yao  
	Function List:
		1.    comPri ��������������ȼ������е�λ��
		2.    toPrefix  ����׺���ʽת��Ϊ��׺���ʽ 
		3.    Calculate  ��׺���ʽ��ֵ 
        4.    getResult  ������ʽ 
****************************************************************************/
#include<queue>
#include<stack> 
#include<string>
#include<sstream>
using namespace std;

class Calculation
{
	public:
		
		void toPrefix(queue<string> q);  
		
		void Calculate();
		
		int comPri(string input);
		
		void getResult(queue<string> q);    
		


	private:
		stack<string> numS;   //����ջ 
		
		stack<string> signS;  //����ջ 
	
};
