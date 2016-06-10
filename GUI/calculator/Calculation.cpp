#include"Calculation.h"
#include<sstream>
#define SIGNNUM 6
#include<iostream>
#include<ctype.h>
using namespace std;
string priority[SIGNNUM][2] = { { "(","5" },{ ")","5" },{ "+","1" },{ "-","1" },{ "*","2" },{ "/","2" } }; // 储存运算符优先级数组

                                                                                                           /*返回运算符在优先级数组中的位置，方便优先级比较*/
int Calculation::comPri(string input)
{
    for (int j = 0; j < SIGNNUM; j++)
    {
        if (input == priority[j][0])
        {
            return j;
        }
    }
}

/*将中缀表达式转换为后缀表达式*/
void Calculation::toPrefix(queue<string> q)
{


    string last;
    int size = q.size();
    numS.push("0");
    for (int i = 0;i < size; i++)
    {
        if (isdigit(q.front()[0]) || (q.front()[0] == '-' && isdigit(q.front()[1])))
        {

            numS.push(q.front());
        }
        else if (q.front() == "(")
        {
            signS.push(q.front());
        }
        else if (q.front() == ")")
        {
            while (signS.top() != "(")
            {
                numS.push(signS.top());
                signS.pop();
            }
            signS.pop();
        }
        else if (q.front() == "+" || q.front() == "-" || q.front() == "*" || q.front() == "/")
        {

            while (1)
            {
                if (signS.empty() || signS.top() == "(" || priority[comPri(q.front())][1] > priority[comPri(signS.top())][1])
                {
                    signS.push(q.front());
                    break;
                }
                else
                {
                    numS.push(signS.top());
                    signS.pop();
                }
            }
        }

        last = q.front();
        q.pop();

    }

    while (!signS.empty())
    {
        numS.push(signS.top());
        signS.pop();
    }
    while (!numS.empty())
    {
        signS.push(numS.top());
        numS.pop();
    }

}


/*后缀表达式求值*/
void Calculation::Calculate()
{
    stringstream stream;
    double num1;
    double num2;
    double res;
    string result;
    int size = signS.size();
    for (int i = 0; i < size; i++)
    {
        if (isdigit(signS.top()[0]) || (signS.top()[0] == '-' && isdigit(signS.top()[1])))
        {
            numS.push(signS.top());
        }
        else if (signS.top() == "+" || signS.top() == "-" || signS.top() == "*" || signS.top() == "/")
        {
            stream << numS.top();
            stream >> num1;

            stream.clear();
            numS.pop();
            stream << numS.top();
            stream >> num2;

            stream.clear();
            numS.pop();


            if (signS.top() == "+")
            {
                res = num1 + num2;
            }
            else if (signS.top() == "-")
            {
                res = num2 - num1;
            }
            else if (signS.top() == "*")
            {
                res = num1 * num2;
            }
            else if (signS.top() == "/")
            {
                res = num2 / num1;
            }
            stream << res;
            stream >> result;
            stream.clear();
            numS.push(result);

        }

        signS.pop();
    }

    outputres = numS.top();

}

/*计算表达式*/
string Calculation::getResult(queue<string> q)
{
    Calculation::toPrefix(q);
    Calculation::Calculate();
    return outputres;

}
