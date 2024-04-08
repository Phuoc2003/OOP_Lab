#include "CLCStudent.h"

CLCStudent::CLCStudent() :Student() {
	this->HK = 1;
}

void CLCStudent::setHK(unsigned int HK) {
	this->HK = HK;
}

unsigned int CLCStudent::getHK() const {
	return this->HK;
}

void CLCStudent::input(istream& is) {
	Student::input(is);

	do {
		cout << "Nhap vao so hoc ki: ";
		is >> HK;
		is.ignore();
	} while (HK > 8);

	he = "CLC";
	fee = calcFee();
} 

void CLCStudent::output(ostream& os) const {
	Student::output(os);
	os << sep << setw(intWidth) << HK << sep << setw(intWidth) << fee << "\n";
}

unsigned int CLCStudent::calcFee() {
	unsigned int initialFee = unsigned int(20000000 * pow((1 + 0.1), 0));
	this->fee = initialFee * pow((1 + 0.1), this->HK - 1);
	return this->fee;
}

istream& operator >> (istream& is, CLCStudent& student) {
	student.input(is);
	return is;
}

ostream& operator << (ostream& os, CLCStudent& student) {
	student.output(os);
	return os;
}