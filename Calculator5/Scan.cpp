#include"Scan.h"
#include<cstdio>
#include<ctype.h>
#include"print.h"
using namespace std;


	
	queue<string> Scan::toStringQueue(string input)
	{
		string sign;  //��ŷ��� 
		string num;  //������� 
        int lbrace = 0;  //��¼(��Ŀ 
        int rbrace = 0;  //��¼)��Ŀ 
		int count = 0;  //��������λ�� 
		bool isNeg = false;  //�ж��Ƿ�Ϊ����
		flag = -1;
		
		for (int i = 0; i < input.size(); i++)
		{
			/*��ǰλΪ����*/ 
			if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
			{
				if (num!="") 
				{
					if(isNeg)
					{
						num="-"+num;
						isNeg=false; 
					}
					inputQue.push(num);	
					num = "";
					count = 0;
				}
				
				if(input[i] == '(')
				{
					lbrace++;
					if(i!=0 && isdigit(input[i-1])) 
					{
						inputQue.push("*");
					}
				}
				else if(input[i] == ')')
				{
					rbrace++;
				}
				
				if(input[i] == '/')
				{
					if(input[i+1] == '0')
					{
						
						//cout<<"ERROR : divided by zero "<<endl;
						flag = 1;
						isTrue = false;
					} 
				}
				
				/*������� '-' �����ִ���һ��*/ 
				if(input[i] == '-' && ((i == 0 || !isdigit(input[i-1]) && input[i-1]!=')' ) && ( i!= input.size()-1 && isdigit(input[i+1]) ) ))
				{
	
					isNeg=true; 
				}
				else 
				{
					inputQue.push(sign = input[i]);
				}
				
				 	
			
			}
			
			/*��ǰλΪ����*/ 
			else if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')  
			{
				count++;
				if (count > 10)
				{
					//cout << "ERROR : ��������ֳ���ʮλ������С��λ��" << endl;
					flag = 2;
					isTrue = false;
					break; 
				}
				
				num += input[i];
			}
		
	 	} 
	 	
	 	/*���һλΪ����*/
        if(num!="" && isTrue)
		{
			if(isNeg)
			{
				num="-"+num;
			}
			inputQue.push(num);
		}
		
		/*�ж������Ƿ�ƥ��*/ 
		if(lbrace!=rbrace)
		{
			//cout<<"ERROR : () don't match" <<endl;
			flag = 3;
			isTrue = false;
		} 
		
	
		
		/*���벻��Ҫ������ĿǰΪ��������ֳ���ʮλ,�������Ų�ƥ�䣬����Ϊ0������ն���*/ 
		if (isTrue == false)
		{
	
			int size = inputQue.size();
			
		 	for (int j = 0; j < size; j++)
		 	{	
		 		inputQue.pop();
			}
			  
		} 
	
		return inputQue;
	
    }
    
    int  Scan::clearQue()
    {
    	while(!inputQue.empty())
    	{
    		inputQue.pop();
		}
		
		return flag;
	}

	
