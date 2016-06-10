#ifndef SCANNER_H
#define SCANNER_H

/****************************************************************************
Author:是光不是yao
Function List:
1. toStringQueue 	接收一个四则运算表达式，将表达式对应拆分存入队列
2. getQue  	获取表达式处理后的队列
****************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

class Scanner
{
public:

    bool isTrue = true;   //判断输入是否正确（目前实现判断输入的数字是否超过十位 超过则为 false）

    queue<string> toStringQueue(string input);

    void clearQue();

    int getFlag();

    void read(string inpath , string outpath);

private:

    int flag;   //保存输出信息

    queue<string> inputQue;  //存放表达式处理后的队列


};

#endif // SCANNER_H
