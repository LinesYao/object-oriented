#include"Prework.h"
#include<iostream>
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl;
void Prework::init() {
	week_id.clear();
	for (int i = 0; i < 7; ++i) {
		week_id[week[i]] = i + 1;
	}
}



/*����һ��free_time���飬���ɿ���ʱ��ε�Timeslot����*/
Timeslot Prework::toMinute(int n, string * s) {
	Timeslot ans;
	string weekday = "";

	int i, h1 = 0, m1 = 0, h2 = 0, m2 = 0, day;
	for (int j = 0;j < n;++j) {
		int len = s[j].length();
		h1 = 0, m1 = 0, h2 = 0, m2 = 0;
		weekday = "";
		//de(s[j]);
		for (i = 0;i < len&&s[j][i] != '.';++i)
			weekday += s[j][i];
		//de(weekday);
		day = week_id[weekday];//de(day);
		for (++i;i < len&&s[j][i] != ':';++i)
			h1 = h1 * 10 + (s[j][i] - '0');
		

		for (++i;i < len&&s[j][i] != '~';++i)
			m1 = m1 * 10 + (s[j][i] - '0');
		

		for (++i;i < len&&s[j][i] != ':';++i)
			h2 = h2 * 10 + (s[j][i] - '0');


		for (++i;i < len;++i)
			m2 = m2 * 10 + (s[j][i] - '0');

		int tmp = (day - 1) * 24 * 60;
		ans.ns.push_back(make_pair(tmp + h1 * 60 + m1, tmp + h2 * 60 + m2));
		//de(ans.ns.size());
		/*ans.ns[j].first = ;
		ans.ns[j].second= ;*/

	}
	return ans;
}
Timeslot Prework::deal_tmie(int n, string *s) {

	return Prework::merge(Prework::toMinute(n, s));
}




/*����ʱ��ε�Timeslot���飬����ʱ��εĺϲ������ض�����ʱ��ε�node����*/
Timeslot Prework::merge(Timeslot ts) {
	//de(233);
	Timeslot ans;
	int n = ts.ns.size(), m = 0, now;
	sort(ts.ns.begin(), ts.ns.end());
	now = -1;
	for (int i = 0;i < n;++i) {
		
		if (ts.ns[i].first> now) ans.ns.push_back(ts.ns[i]),m++;
		else ans.ns[m - 1].second = max(ans.ns[m - 1].second, ts.ns[i].second);
		now = max(now, ts.ns[i].second);
	}
	/*for (int i = 0;i < ans.ns.size();++i) {
		de(ans.ns[i].first);de(ans.ns[i].second);
	}*/
	return ans;
}

/*�������ѧ������ʱ��ε�stu�����벿�ŵ�dep���飬�ж�ѧ������ʱ���Ƿ���ȫ��������Ҫ��ʱ��*/
bool Prework::is_time_match(Timeslot stu, Timeslot dep) {
	
	int n = stu.ns.size(), m = dep.ns.size();
	int j = 0, cnt = 0;
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j) {
			if (stu.ns[j].first <= dep.ns[i].first&&stu.ns[j].second >= dep.ns[i].second) ++cnt;
		}
		/*for (;j < n;++j) {
			if (stu.ns[j].first <= dep.ns[i].first&&stu.ns[j].second >= dep.ns[i].second) {
				++cnt, ++j;
				break;
			}
		}*/
	}//if(cnt>=m) de("iiii");
	return cnt >= m;
}

/*�������ƥ���һ��ѧ����һ�����ŵ�free_time���飬�������*/
Timeslot Prework::split(Timeslot stu, Timeslot dep) {
	Timeslot ans;
	int n = stu.ns.size(), m = dep.ns.size();
	int j = 0, tmp = 0;
	for (int i = 0;i < m;++i) {
		for (;j < n;++j) {
			if (stu.ns[j].first <= dep.ns[i].first&&stu.ns[j].second >= dep.ns[i].second) {
				int l1 = stu.ns[j].first, r1 = stu.ns[j].second, l2 = dep.ns[i].first, r2 = dep.ns[i].second;
				if (l1 == l2&&r1 == r2) continue;
				else {
					if (l1 < r1) {
						ans.ns[tmp++].first = l1, ans.ns[tmp].second = r1;
					}
					if (r2 < r1) {
						ans.ns[tmp++].first = r2, ans.ns[tmp].second = r1;
					}
				}
				++j; break;
			}
			else {
				ans.ns[m++] = stu.ns[j];
			}
		}
	}
	return ans;
}

/*���벿�ź�ѧ���ı�ǩ�������ƥ�����*/
int Prework::tag_match_check(int stu_tag_cnt, string *stuTag, int dep_tag_cnt, string *depTag) {
	int cnt = 0;
	for (int i = 0;i < dep_tag_cnt;++i) {
		for (int j = 0;j < stu_tag_cnt;++j) {
			if (depTag[i] == stuTag[j]) ++cnt;
		}
	}
	return cnt;
}


