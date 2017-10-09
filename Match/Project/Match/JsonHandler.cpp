#include "JsonHandler.h"

string JsonHandler::readInputTestFile(const char *path) {
	FILE *file = fopen(path, "rb");
	if (!file)
		return std::string("");
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	std::string text;
	char *buffer = new char[size + 1];
	buffer[size] = 0;
	if (fread(buffer, 1, size, file) == (unsigned long)size)
		text = buffer;
	fclose(file);
	delete[] buffer;
	return text;
}

void JsonHandler::getDateFromJson(Value value, Student(&student)[305]) {
	int size = value.size();
	for (int i = 0;i < size;i++) {
		getSingleDateFromJson(value[i], student[i]);
	}
}

void JsonHandler::getDateFromJson(Value value, Department(&department)[25]) {
	int size = value.size();
	for (int i = 0;i < size;i++) {
		getSingleDateFromJson(value[i], department[i]);
	}
}

void JsonHandler::getSingleDateFromJson(Value value, Student &student) {

	// stu_no
	student.no = value[Sno].asString();

	// stu_freeTime
	Value freeTime = value[Sfree];
	student.free_size = freeTime.size();
	for (int i = 0;i < student.free_size;i++) {
		student.free_time[i] = freeTime[i].asString();
	}

	// stu_dept
	Value department = value[Sdept];
	student.dept_size = department.size();
	for (int i = 0;i < student.dept_size;i++) {
		student.department[i] = department[i].asString();
	}

	// stu_tags
	Value tags = value[Stag];
	student.tag_size = tags.size();
	for (int i = 0;i < student.tag_size;i++) {
		student.tag[i] = tags[i].asString();
	}

}


void JsonHandler::getSingleDateFromJson(Value value, Department &department) {

	// dept_no
	department.no = value[Dno].asString();

	// dept_schedule
	Value schedule = value[Dsche];
	department.sche_size = schedule.size();
	for (int i = 0;i < department.sche_size;i++) {
		department.event_schedules[i] = schedule[i].asString();
	}

	// dept_numberLimit
	department.num_limit = value[Dnum].asInt();

	// dept_tags
	Value tags = value[Dtag];
	department.tag_size = tags.size();
	for (int i = 0;i < department.tag_size;i++) {
		department.tag[i] = tags[i].asString();
	}

}