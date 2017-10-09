#include"Department.h"
#include<iostream>
using namespace std;
void Department::getTimesolt(Department department) {
	prework.init();
	department.time_solt=prework.deal_tmie(department.sche_size, department.event_schedules);
}

void Department::admitMember(string stu_no, Department &department) {
	department.admit_member[department.admit_size++] = stu_no;
	--department.num_limit;
}

int Department::getNumLimit(Department department) {
	return department.num_limit;
}