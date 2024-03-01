#pragma once
#include "Student.h"
#include "CLCStudent.h"
#include "CQStudent.h"
#include <vector>
#include <algorithm>
#include <fstream>

class QLySinhVien
{
private:
	vector<Student*> studentsList;
	int soLuong;
public:
	void input();
	void inputList();
	void outputList();
	void addStudent();
	int findStudent(string name);
	void deleteStudent();
	void sortFee();
	unsigned int avgFee();
	void listFee();
	void writeToFile();
	void console();
};

bool compareFee(Student* a, Student* b);