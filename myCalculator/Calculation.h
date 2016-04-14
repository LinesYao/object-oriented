/****************************************************************************
    Author:是光不是yao  
	Function List:
		1.    comPri 返回运算符在优先级数组中的位置
		2.    toPrefix  将中缀表达式转换为后缀表达式 
		3.    Calculate  后缀表达式求值 
        4.    getResult  计算表达式 
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
		stack<string> numS;   //数字栈 
		
		stack<string> signS;  //符号栈 
	
};
