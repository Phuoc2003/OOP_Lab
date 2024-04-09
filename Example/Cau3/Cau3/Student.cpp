#include "Student.h"

const int nameWidth = 15;
const int intWidth = 10;
//const int feeWidth = 15;
const string sep = " |";

Student::Student() {
	this->ID = "";
	this->name = "";
	this->he = "";
	this->fee = 0;
	this->sex = "";
	this->gpa = 0;
	this->tel = "";
}

void Student::setId(string ID) {
	this->ID = ID;
}

void Student::setName(string name) {
	this->name = name;
}

void Student::setHe(string he) {
	this->he = he;
}

void Student::setSex(string sex) {
	this->sex = sex;
}

void Student::setGpa(double gpa) {
	this->gpa = gpa;
}

void Student::setTel(string tel) {
	this->tel = tel;
}

void Student::setRank() {
	string rank;
	if (this->gpa >= 8.5) rank = "A";
	else if (this->gpa >= 8.0) rank = "B+";
	else if (this->gpa >= 7.0) rank = "B";
	else if (this->gpa >= 6.5) rank = "C+";
	else if (this->gpa >= 5.5) rank = "C";
	else if (this->gpa >= 5.0) rank = "D+";
	else if (this->gpa >= 4.0) rank = "D";
	else rank = "F";
	this->rank = rank;
}

string Student::getId() const {
	return this->ID;
}

string Student::getName() const {
	return this->name;
}
string Student::getHe() const {
	return this->he;
}

unsigned int Student::getFee() const {
	return this->fee;
}

string Student::getSex() const {
	return this->sex;
}

double Student::getGpa() const {
	return this->gpa;
}

string Student::getTel() const {
	return this->tel;
}

string Student::getRank() const{
	return this->rank;
}

void Student::input(istream& is) {
	do {
		cout << "Nhap ma so sinh vien (2 ky tu): "; is >> ID;
	} while (ID.size() != 2);
	cout << "Nhap ho va ten: ";
	is.ignore();
	getline(is, name);
	do {
		cout << "Nhap gioi tinh (Nam/Nu): "; is >> sex;
	} while (!(sex == "Nam" || sex == "Nu"));
	cout << "Nhap GPA (theo he 10): "; is >> gpa;
	cout << "Nhap so dien thoai: "; is >> tel;
}

void Student::output(ostream& os) const {
	os << sep << setw(3) << ID << sep << setw(nameWidth) << name << sep << setw(5) << he << sep << setw(intWidth) << sex
		<< sep << fixed << setprecision(1) << setw(4) << gpa << sep << setw(intWidth) << rank << sep << setw(12) << tel;
}

istream& operator >> (istream& is, Student& student) {
	student.input(is);
	return is;
}

const ostream& operator << (ostream& os, Student& student) {
	student.output(os);
	return os;
}