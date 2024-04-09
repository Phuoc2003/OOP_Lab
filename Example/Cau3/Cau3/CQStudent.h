#pragma once
#include "Student.h"

class CQStudent : public Student //Extend Student
{
private:
	unsigned int MonLT;
	unsigned int MonTH;
	unsigned int totalCredit;
public:
	CQStudent();

	void setMonLT(unsigned int MonLT);
	void setMonTH(unsigned int MonTH);
	
	unsigned int getMonLT() const;
	unsigned int getMonTH() const;
	unsigned int getTotalCredit() const;
	
	void input(istream& is) override;
	void output(ostream& os) const override;
	unsigned int calcFee();
	
	friend istream& operator >> (istream& is, CQStudent& student);
	friend ostream& operator << (ostream& os, CQStudent& student);
};

