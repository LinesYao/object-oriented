#pragma once
#include <string>

#include "json.h"
#include "Constant.h"
#include "Student.h"
#include "Department.h"

using namespace std;
using namespace Json;

class JsonHandler
{
public:
	JsonHandler() {};
	~JsonHandler() {};

	static string readInputTestFile(const char *path);

	void getDateFromJson(Value value, Student (&student)[305]);

	void getDateFromJson(Value value, Department(&department)[25]);


private:

	void getSingleDateFromJson(Value value, Student &student);

	void getSingleDateFromJson(Value value, Department &department);

};
