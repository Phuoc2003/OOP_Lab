#include "CQStudent.h"

CQStudent::CQStudent() : Student() {
	this->MonLT = 0;
	this->MonTH = 0;
	this->totalCredit = 0;
}

void CQStudent::setMonLT(unsigned int MonLT) {
	this->MonLT = MonLT;
}

void CQStudent::setMonTH(unsigned int MonTH) {
	this->MonTH = MonTH;
}

unsigned int CQStudent::getMonLT() const {
	return this->MonLT;
}

unsigned int CQStudent::getMonTH() const {
	return this->MonTH;
}

unsigned int CQStudent::getTotalCredit() const {
	return this->totalCredit;
}

void CQStudent::input(istream& is) {
	Student::input(is);

	cout << "Nhap vao so mon LT: ";
	is >> MonLT;
	is.ignore();

	cout << "Nhap vao so mon TH: ";
	is >> MonTH;
	is.ignore();

	totalCredit = (this->MonLT * 2) + (this->MonTH * 3);
	he = "CQ";
	fee = calcFee();
}

void CQStudent::output(ostream& os) const {
	Student::output(os);
	os << sep << setw(intWidth) << MonLT << sep << setw(intWidth) << MonTH << sep << setw(8) << totalCredit 
		<< sep << setw(intWidth) << fee << "\n";
}

unsigned int CQStudent::calcFee() {
	this->fee = this->totalCredit * 200000;
	return this->fee;
}

istream& operator >> (istream& is, CQStudent& student) {
	student.input(is);
	return is;
}

ostream& operator << (ostream& os, CQStudent& student) {
	student.output(os);
	return os;
}