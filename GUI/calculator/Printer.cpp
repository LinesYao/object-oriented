#include "Printer.h"
#include <string>
using namespace std;

string Printer::getInfomation(int flag , string res)
{
    switch (flag)
    {
    case -1:
        return  res;
        break;
    case 1:
        return  "ERROR : divided by zero ";
        break;
    case 2:
        return  "ERROR : 输入的数字超过十位（包括小数位）";
        break;
    case 3:
        return  "ERROR : () don't match";
        break;
    }

}

void Printer::print(string res)
{
    cout << res << endl;
}


void Printer::printQue(queue<string> que)
{
    while (!que.empty())
    {
        cout << que.front();
        que.pop();
    }
    cout << "= ";

}



void Printer::write(string res,ofstream &out)
{

    out << res << endl;

}
