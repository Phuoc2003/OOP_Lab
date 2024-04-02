#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

extern const int nameWidth;
extern const int intWidth;
extern const int feeWidth;
extern const string sep;

class Student //Base class
{
protected:
	unsigned int ID;
	string name;
	string he;
	unsigned int fee;
	double GPA; 
	string rank;
	bool sex; //0: Nu, 1: Nam
	string tel;

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

	friend istream& operator >> (istream& is, Student& student); // Nap chong toan tu
	friend const ostream& operator << (ostream& os, Student& student);
	//Doi tu 10 -> 4 GPA
	//Nhap GPA
	//Xep loai sv

};