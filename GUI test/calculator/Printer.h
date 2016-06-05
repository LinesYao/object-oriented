#ifndef PRINTER_H
#define PRINTER_H

/*****************************************
Author:是光不是yao
Function List:
        printQue  打印接收的队列

*****************************************/

#include<iostream>
#include<queue>
#include<fstream>
using namespace std;

class Printer
{
    public:

        int flag;

        void printQue(queue<string> que);

        void print(int flag, string res);

        void printError(int flag);

        string write(int flag , string res);


};
#endif // PRINTER_H
