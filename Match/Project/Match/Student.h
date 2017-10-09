#pragma once
#include <string>
#include"Prework.h"
using namespace std;

class Student {
public:
	int tag_size;
	int free_size;
	int dept_size;
	int can_match;
	int admitted_size;
	int tag_match[105];
	int round_dep;
	double round_value;
	string no;
	string tag[15];
	string free_time[55];
	string department[7];
	string addimited_dep[7];
	int department_id[7];
	int is_accepted[7];
	Student() { 
		tag_size = 0, free_size = 0, dept_size = 0, admitted_size = 0, can_match = 0, round_dep = 0;
		memset(tag_match, 0, sizeof tag_match);
		memset(is_accepted, 0, sizeof is_accepted);
	}
	
	Timeslot time_slot;
	void getTimeslot(Student stu);
	int getTagMatch(int m, string *dep);
	void beAdmitted(int id,Timeslot dep);
	Prework prework;
	

private:
};

