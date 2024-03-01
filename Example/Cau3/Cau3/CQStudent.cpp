#include "CQStudent.h"

CQStudent::CQStudent() : Student() {
	this->TCLT = 0;
	this->TCTH = 0;
	this->totalCredit = 0;
}

void CQStudent::setTCLT(unsigned int TCLT) {
	this->TCLT = TCLT;
}

void CQStudent::setTCTH(unsigned int TCTH) {
	this->TCTH = TCTH;
}

unsigned int CQStudent::getTCLT() const {
	return this->TCLT;
}

unsigned int CQStudent::getTCTH() const {
	return this->TCTH;
}

unsigned int CQStudent::getTotalCredit() const {
	return this->totalCredit;
}

void CQStudent::input(istream& is) {
	Student::input(is);

	cout << "Nhap vao so tin chi LT: ";
	is >> TCLT;
	is.ignore();

	cout << "Nhap vao so tin chi TH: ";
	is >> TCTH;
	is.ignore();

	totalCredit = (this->TCLT * 2) + (this->TCTH * 3);
	he = "CQ";
	fee = calcFee();
}

void CQStudent::output(ostream& os) const {
	Student::output(os);
	os << sep << setw(intWidth) << TCLT << sep << setw(intWidth) << TCTH << sep << setw(intWidth) << totalCredit 
		<< sep << setw(feeWidth) << fee << "\n";
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