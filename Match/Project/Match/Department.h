#pragma once
#include"Prework.h"
#include <string>
using namespace std;

class Department {
public:
	int tag_size;
	int sche_size;
	int num_limit;
	int admit_size;
	string no;
	string tag[15];
	string admit_member[35];
	string event_schedules[55];
	Department() {
		tag_size = 0, sche_size = 0, admit_size = 0;
	}
	int getNumLimit(Department department);
	void admitMember(string stu_no, Department &department);

	Timeslot time_solt;
	void getTimesolt(Department department);
	Prework prework;
private:
};