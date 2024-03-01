#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

extern const int nameWidth;
extern const int intWidth;
extern const int feeWidth;
extern const string sep;

class Student
{
protected:
	string name;
	string he;
	unsigned int fee;
public:
	Student();
	
	void setName(string name);
	void setHe(string he);

	string getName() const;
	string getHe() const;
	unsigned int getFee() const;

	virtual void input(istream& is);
	virtual void output(ostream& os) const;
	virtual unsigned int calcFee() = 0;

	friend istream& operator >> (istream& is, Student& student);
	friend const ostream& operator << (ostream& os, Student& student);
};

