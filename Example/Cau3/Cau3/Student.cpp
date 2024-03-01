#include "Student.h"

const int nameWidth = 15;
const int intWidth = 10;
const int feeWidth = 15;
const string sep = " |";

Student::Student() {
	this->name = "";
	this->he = "";
	this->fee = 0;
}

void Student::setName(string name) {
	this->name = name;
}

void Student::setHe(string he) {
	this->he = he;
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

void Student::input(istream& is) {
	cout << "Nhap ho va ten: ";
	is.ignore();
	getline(is, name);
}

void Student::output(ostream& os) const {
	os << sep << setw(nameWidth) << name << sep << setw(intWidth) << he;
}

istream& operator >> (istream& is, Student& student) {
	student.input(is);
	return is;
}

const ostream& operator << (ostream& os, Student& student) {
	student.output(os);
	return os;
}