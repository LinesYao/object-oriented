#include"Scan.h"
using namespace std;

	
	void Scan::toStringQueue(string input)
	{
		string sign;  //存放符号 
		string num;  //存放数字 
		int count;  //记忆数字位数 
		
		for (int i = 0; i < input.size(); i++)
		{
			/*当前位为符号*/ 
			if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
			{
				if (num!="") 
				{
					inputQue.push(num);	
					num = "";
					count = 0;
				}
				
			
				inputQue.push(sign = input[i]);
			
			}
			
			/*当前位为数字*/ 
			else if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')  
			{
				count++;
				if (count > 10)
				{
					cout << "输入的数字超过十位（包括小数位）" << endl;
					isTrue = false;
					break; 
				}
				
				num += input[i];
			}
			
			
		
	 	} 
	 	
	 	/*最后一位为数字*/
        if(num!="" && isTrue)
		{
			inputQue.push(num);
		}
		 
		/*输入不符（目前为输入的数字超过十位），清空队列*/ 
		if (!isTrue)
		{
		
			int size = inputQue.size();
			
		 	for (int j = 0; j < size; j++)
		 	{	
		 		inputQue.pop();
			}
			  
		} 
	
    }



	queue<string> Scan::getQue()
	{
		return inputQue;
	}
