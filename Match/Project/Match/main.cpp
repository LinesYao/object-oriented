#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "json.h"
#include "MatchSolve.h"
#include "Constant.h"
#include "JsonHandler.h"
#include "createData.h"
#define de(x) cout<<#x<<" = "<<x<<endl;

using namespace std;
using namespace Json;    //jsonµÄÃüÃû¿Õ¼ä
	

Student student[305];
Department department[25];

int main()
{
	

	
	JsonHandler jsonHandler;
	std::string path = "./input_data.txt";
	std::string input = jsonHandler.readInputTestFile(path.c_str());
	
	Json::Reader reader;
	Json::Value root;
	freopen("./output_data.txt", "w", stdout);


	if (reader.parse(input, root)) {
		if (!root[Stu].isNull()) {
			jsonHandler.getDateFromJson(root[Stu], student);
		}
		if (!root[Dept].isNull()) {
			jsonHandler.getDateFromJson(root[Dept], department);
		}
	}
	

	MatchSolve ms;
	ms.solve(student, department);
	
	
	FastWriter fastWriter;

	Value valueRoot;
	Value ulStu;
	Value admt;
	Value ulDept;
	int cnt = 0;
	for (int i = 0;i < 300;i++) {
		if (student[i].admitted_size == 0) {
			++cnt;
			ulStu.append(student[i].no);
		}
	}

	int d = 0;
	for (int i = 0;i < 20;i++) {
		d += department[i].admit_size + department[i].num_limit;
		if (department[i].admit_size == 0) {
			ulDept.append(department[i].no);
		}
		else {
			Value temp_admt;
			temp_admt[Padmt_dept] = department[i].no;
			for (int j = 0;j < department[i].admit_size;j++) {
				temp_admt[Padmt_mem].append(department[i].admit_member[j]);
			}
			admt.append(temp_admt);
		}
	}
	

	valueRoot[Pstu]= ulStu;
	valueRoot[Padmt]= admt;
	valueRoot[Pdept].append(ulDept);

	cout << valueRoot << endl;

	
	
	return 0;
}








