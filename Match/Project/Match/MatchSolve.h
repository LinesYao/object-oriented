#pragma once
#include<map>
#include<string>
#include"Department.h"
#include"Student.h"
using namespace std;
class MatchSolve {
public:
	map<string, int>  dep_id;
	void init(Student(&stu)[305], Department (&dep)[25]);
	void generateValue(int round, Student(&stu)[305], Department(&dep)[25]);
	void singleMatchInit(int round, Student(&stu)[305], Department(&dep)[25]);
	void singleMatchSolve(int round, Student(&stu)[305], Department(&dep)[25]);
	void Matchsolve(int round, Student(&stu)[305], Department(&dep)[25]);
	void successMatchOperator(int round, int stu_id, int dep_id, Student(&stu)[305], Department(&dep)[25]);
	const int INF = 1005;
	Prework prework;
	
	void solve(Student(&stu)[305], Department(&dep)[25]);
	const int stu_size = 300, dep_size = 20;
	//Student stu[305];
	//Department dep[25];
};