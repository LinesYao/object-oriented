#include"Student.h"
#include<iostream>
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl;
/**/
void Student::getTimeslot(Student stu) {
	//de(free_size);
	prework.init();
	//stu.time_slot = prework.toMinute(free_size, free_time);
	stu.time_slot = prework.deal_tmie(free_size, free_time);
}

int Student::getTagMatch(int dep_tag_size,string *dep) {
		return prework.tag_match_check(free_size,free_time,dep_tag_size,dep);
}
void Student::beAdmitted(int round,Timeslot dep) {
	time_slot = prework.split(time_slot, dep);
	++admitted_size;
	is_accepted[round-1] = 1;
}