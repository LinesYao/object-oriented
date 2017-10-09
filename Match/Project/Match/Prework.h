#pragma once
#include<map>
#include<string>
#include<algorithm>
#include"Timeslot.h"
using namespace std;
class Prework {
public:

	void init();
	string week[7] = { "Mon","Tues","Wed","Thur","Fri","Sat","Sun" };
	map<string, int> week_id;
	

	Timeslot timeslot;

	int tag_match_check(int n, string *stu, int m, string *dep);
	Timeslot deal_tmie(int n, string *s);
	Timeslot toMinute(int n, string *s);
	Timeslot merge(Timeslot ts);
	bool is_time_match(Timeslot stu, Timeslot dep);
	Timeslot split(Timeslot stu, Timeslot dep);
};