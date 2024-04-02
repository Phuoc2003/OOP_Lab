#pragma once
#include "Student.h"
#include <cmath>

class CLCStudent : public Student //Extend Student
{
private:
	unsigned int HK; // Hoc ki
public:
	CLCStudent();

	void setHK(unsigned int HK);

	unsigned int getHK() const;

	void input(istream& is) override;
	void output(ostream& os) const override;
	unsigned int calcFee();

	friend istream& operator >> (istream& is, CLCStudent& student);
	friend ostream& operator << (ostream& os, CLCStudent& student);

};

