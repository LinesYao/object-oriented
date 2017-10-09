#include"MatchSolve.h"
#include<iostream>
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl;


void MatchSolve::solve(Student(&stu)[305], Department(&dep)[25]) {
	init(stu, dep);
	Matchsolve(5,stu, dep);
}

void MatchSolve::init(Student(&stu)[305], Department(&dep)[25]) {
	for (int i = 0;i < stu_size;++i) {

		sort(stu[i].tag, stu[i].tag + stu[i].tag_size);
		stu[i].tag_size = unique(stu[i].tag, stu[i].tag + stu[i].tag_size) - stu[i].tag;
		stu[i].getTimeslot(stu[i]);
	}
	
	dep_id.clear();
	for (int i = 0;i < dep_size;++i) {
		sort(dep[i].tag, dep[i].tag + dep[i].tag_size);
		dep[i].tag_size = unique(dep[i].tag, dep[i].tag + dep[i].tag_size) - dep[i].tag;
		dep_id[dep[i].no] = i;
		dep[i].getTimesolt(dep[i]);
	}

	for (int i = 0;i < stu_size;++i) {
		//处理学生和部门标签匹配度
		for (int j = 0;j < stu[i].dept_size;++j) {
			int now = dep_id[stu[i].department[j]];
			stu[i].department_id[j] = now;
			stu[i].tag_match[j] = stu[i].getTagMatch(dep[now].tag_size, dep[now].tag);
			//Prework::tag_match_check(stu[i].tag_size, stu[i].tag, );
		}
	}
	

}


bool cmpAll(Student a, Student b) {
	return a.round_dep < b.round_dep;
}
bool cmpValue(Student a, Student b) {
	return a.round_value > b.round_value;
}
//这里需要一个评价函数
void MatchSolve::generateValue(int round, Student(&stu)[305], Department(&dep)[25]) {
	for (int i = 0;i < stu_size;++i) {
		if (stu[i].round_dep == INF) continue;
		stu[i].round_value = 1.0 / (1.0 + stu[i].admitted_size) + 1.0 / (5.0 + stu[i].can_match) + 0.15*stu[i].tag_match[stu[i].round_dep];
	}
}

void MatchSolve::Matchsolve(int round, Student(&stu)[305], Department(&dep)[25]) {
	for (int i = 1;i <= round;++i) {
		//
		//de(i);
		singleMatchSolve(i, stu, dep);
	}
}

void MatchSolve::singleMatchInit(int round, Student(&stu)[305], Department(&dep)[25]) {
	//重新判断每个学生还能匹配的部门数量
	
	
	//de("------------------------------------");
	//cout << round << endl;
	for (int i = 0;i < stu_size;++i) {
		
		if (stu[i].dept_size < round) {
			stu[i].round_dep = INF;
			continue;
		}
		
		
		int tmp = stu[i].department_id[round - 1];
		if (!dep[tmp].getNumLimit(dep[tmp])) {
			stu[i].round_dep = INF;
			continue;
		}
		if (prework.is_time_match(stu[i].time_slot, dep[tmp].time_solt) == false) {
			stu[i].round_dep = INF;
			continue;
		}/**///de(stu[i].dept_size);
		//de(i);
		stu[i].can_match = 0;
		stu[i].round_dep = tmp;
		for (int j = round - 1;j < stu[i].dept_size;++j) {
			//if (stu[i].is_accepted[j]) continue;
			int now = stu[i].department_id[j];
			if (!dep[now].getNumLimit(dep[now]) || now == tmp) continue;
			if (prework.is_time_match(stu[i].time_slot, dep[now].time_solt)) {
				++stu[i].can_match;
			}
		}
	}
}
void MatchSolve::successMatchOperator(int round, int stu_id, int dep_id, Student(&stu)[305], Department(&dep)[25]) {

	//学生空闲时段拆分 学生已录取部门数+1
	stu[stu_id].beAdmitted(round, dep[dep_id].time_solt);

	//部门录取人数+1
	dep[dep_id].admitMember(stu[stu_id].no, dep[dep_id]);
}

//单轮匹配操作
void MatchSolve::singleMatchSolve(int round, Student(&stu)[305], Department(&dep)[25]) {

	singleMatchInit(round, stu, dep);

	//排序 将本轮同部门的学生分组
	sort(stu, stu + stu_size, cmpAll);

	//重新生成每个学生的权值
	generateValue(round, stu, dep);
	//de("uu");
	//同组间按权值排序 排序完可能存在问题!!
	int last = 0, now = stu[0].round_dep;
	stu[stu_size].round_dep = 2 * INF;
	int tmp_now;
	for (int i = 0;i <= stu_size;++i) {
		/*if (stu[i].round_dep == INF) {
			if (now != INF) {

			}
			break;
		}*/
		
		if (stu[i].round_dep != now) {
			sort(stu + last, stu + i, cmpValue);

			int lim = min(dep[now].getNumLimit(dep[now]), i - last);
			tmp_now = stu[i].round_dep;
			if (lim) {
				//cout << "rr" << endl;
				//同个部门的匹配
				for (int j = 0;j < lim;++j) {
					successMatchOperator(round, last + j, now, stu, dep);
				}
			}

			now = tmp_now;
			last = i;

		}

		if (stu[i].round_dep == INF) {
			break;
		}
	}

}





/*
bool checkIsAdmitted(int stu_id, int dep_id) {
for (int i = 0;i < stu[stu_id].admitted_size;++i) {
if (stu[stu_id].accepted_dep[i] == dep[dep_id].no) return true;
}
return false;
}
*/
