#include"Printer.h"
#include<string>
using namespace std;

void Printer::print(int flag, string res)
{
    if (flag == -1)
    {
        cout << res << endl;
    }
    else
    {
        Printer::printError(flag);
    }
}

void Printer::printError(int flag)
{

    switch (flag)
    {
    case 1:
        cout << "ERROR : divided by zero " << endl;
        break;
    case 2:
        cout << "ERROR : 输入的数字超过十位（包括小数位）" << endl;
        break;
    case 3:
        cout << "ERROR : () don't match" << endl;
        break;
    }
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



string Printer::write( int flag, string res)
{
    //ofstream out(outpath, ios::out);
    switch (flag)
    {
    case -1:
        return res;
        //out << res << endl;
        break;
    case 1:
        //out << "ERROR : divided by zero " << endl;
        return "ERROR : divided by zero ";
        break;
    case 2:
        //out << "ERROR : 输入的数字超过十位（包括小数位）" << endl;
        return "ERROR : 输入的数字超过十位（包括小数位）";
        break;
    case 3:
        //out << "ERROR : () don't match" << endl;
        return "ERROR : () don't match";
        break;
    }
    //out.close();
}
