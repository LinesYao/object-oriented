#include"Scan.h"
using namespace std;

	
	void Scan::ToStringQueue(string input)
	{
		string sign;  //��ŷ��� 
		string num;  //������� 
		int count;  //��������λ�� 
		
		for (int i = 0; i < input.size(); i++)
		{
			/*��ǰλΪ����*/ 
			if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
			{
				if (num!="") 
				{
					inputQue.push(num);
				}
				
				num = "";
				count = 0;
				inputQue.push(sign = input[i]);
			
			}
			
			/*��ǰλΪ����*/ 
			else if (input[i] >= 48 && input[i] <= 57 || input[i] == '.')//˵�������� 
			{
				count++;
				if (count > 10)
				{
					cout << "��������ֳ���ʮλ������С��λ��" << endl;
					isTrue = false;
					break; 
				}
				
				num += input[i];
			}
			
			
		
	 	} 
	 	
	 	/*���һλΪ����*/
        if(num!="" && isTrue)
		{
			inputQue.push(num);
		}
		 
		/*���벻����ĿǰΪ��������ֳ���ʮλ������ն���*/ 
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
