#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

extern const int nameWidth;
extern const int intWidth;
//extern const int feeWidth;
extern const string sep;

class Student //Base class
{
protected:
	string ID;
	string name;
	string he;
	unsigned int fee;
	double gpa; 
	string rank;
	string sex;
	string tel;

public:
	Student();
	void setId(string ID);
	void setName(string name);
	void setHe(string he);
	void setSex(string sex);
	void setGpa(double gpa);
	void setTel(string tel);
	void setRank();

	string getId() const;
	string getName() const;
	string getHe() const;
	unsigned int getFee() const;
	string getSex() const;
	double getGpa() const;
	string getTel() const;
	string getRank() const;

	virtual void input(istream& is);
	virtual void output(ostream& os) const;
	virtual unsigned int calcFee() = 0;

	friend istream& operator >> (istream& is, Student& student); // Nap chong toan tu
	friend const ostream& operator << (ostream& os, Student& student);
	//Doi tu 10 -> 4 GPA
	//Nhap GPA
	//Xep loai sv

};