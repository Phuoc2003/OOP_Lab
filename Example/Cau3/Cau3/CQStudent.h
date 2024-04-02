#pragma once
#include "Student.h"

class CQStudent : public Student //Extend Student
{
private:
	unsigned int TCLT;
	unsigned int TCTH;
	unsigned int totalCredit;
public:
	CQStudent();

	void setTCLT(unsigned int TCLT);
	void setTCTH(unsigned int TCTH);
	
	unsigned int getTCLT() const;
	unsigned int getTCTH() const;
	unsigned int getTotalCredit() const;
	
	void input(istream& is) override;
	void output(ostream& os) const override;
	unsigned int calcFee();
	
	friend istream& operator >> (istream& is, CQStudent& student);
	friend ostream& operator << (ostream& os, CQStudent& student);
};

