#include"Scan.h"
#include<cstdio>
#include<ctype.h>
#include"print.h"
#include"Calculation.h"
using namespace std;

queue<string> Scan::toStringQueue(string input)
{
	string sign;  //存放符号 
	string num;  //存放数字 
	int lbrace = 0;  //记录 ( 数目 
	int rbrace = 0;  //记录 ) 数目 
	int count = 0;  //记忆数字位数 
	bool isNeg = false;  //判断是否为负数
	flag = -1;

	for (int i = 0; i < input.size(); i++)
	{
		/*当前位为符号*/
		if (input[i] == '-' || input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '*' || input[i] == '/')
		{
			if (num != "")
			{
				if (isNeg)
				{
					num = "-" + num;
					isNeg = false;
				}
				inputQue.push(num);
				num = "";
				count = 0;
			}

			if (input[i] == '(')
			{
				lbrace++;
				if (i != 0 && isdigit(input[i - 1]))
				{
					inputQue.push("*");
				}
			}
			else if (input[i] == ')')
			{
				rbrace++;
			}

			if (input[i] == '/')
			{
				if (input[i + 1] == '0')
				{

					flag = 1;
					isTrue = false;
				}
			}

			/*负数情况 '-' 与数字存在一起*/
			if (input[i] == '-' && ((i == 0 || !isdigit(input[i - 1]) && input[i - 1] != ')') && (i != input.size() - 1 && isdigit(input[i + 1]))))
			{

				isNeg = true;
			}
			else
			{
				inputQue.push(sign = input[i]);
			}
		}

		/*当前位为数字*/
		else if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')
		{
			count++;
			if (count > 10)
			{
				flag = 2;
				isTrue = false;
				break;
			}

			num += input[i];
		}
	}

	/*最后一位为数字*/
	if (num != "" && isTrue)
	{
		if (isNeg)
		{
			num = "-" + num;
		}
		inputQue.push(num);
	}

	/*判断括号是否匹配*/
	if (lbrace != rbrace)
	{
		flag = 3;
		isTrue = false;
	}



	/*输入不符要求或错误（目前为输入的数字超过十位,左右括号不匹配，除数为0），清空队列*/
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

void  Scan::clearQue()
{
	while (!inputQue.empty())
	{
		inputQue.pop();
	}

}

int Scan::getFlag()
{
	Calculation cal;
	return flag;
}


void Scan::read(string inpath, string outpath)
{
	Calculation cal;
	Print pr;
	queue<string> q;
	string s, res;
	ifstream in(inpath, ios::in);   //为读入而打开文件 	
	ofstream out(outpath, ios::out); //为写而打开文件

	while (getline(in, s))
	{
		if (s == "") break;
		q = Scan::toStringQueue(s);
		Scan::clearQue();
		res = cal.getResult(q);
		pr.write(outpath, flag, res,out);
	
	}

	in.close();
	out.close();

}

