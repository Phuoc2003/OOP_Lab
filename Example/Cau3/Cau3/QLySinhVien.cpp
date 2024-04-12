#include "QLySinhVien.h"

QLySinhVien::QLySinhVien() {
	this->soLuong = 0;
	this->soLuongCLC = 0;
	this->soLuongCQ = 0;
}

void QLySinhVien::input() {
	Student* student;
	int studentType;
	cout << "Nhap he sinh vien(1 - Sinh vien chat luong cao, 2 - Sinh vien dai tra): ";
	cin >> studentType;
	if (studentType == 1) {
		student = new CLCStudent();
		this->soLuongCLC++;
	}
	else {
		student = new CQStudent();
		this->soLuongCQ++;
	}
	cin >> *student;
	studentsList.push_back(student);
}

void QLySinhVien::inputList() {
	cout << "Nhap vao so luong sinh vien: ";
	cin >> soLuong;
	for (int i = 0; i < soLuong; i++)
	{
		this->input();
	}
}

void QLySinhVien::outputList() {
	if (soLuongCQ) {
		cout << sep << setw(3) << "ID" << sep << setw(nameWidth) << "Ho va ten" << sep << setw(5) << "He" << sep << setw(intWidth) << "Gioi tinh"
			<< sep << setw(4) << "GPA" << sep << setw(intWidth) << "Xep loai" << sep << setw(12) << "SDT"
			<< sep << setw(intWidth) << "So mon LT" << sep << setw(intWidth) << "So mon TH" << sep << setw(8) << "Tong TC"
			<< sep << setw(intWidth) << "Hoc phi" << "\n";

		for (Student* s : studentsList) {
			if (s->getHe() == "CQ")
				cout << *s;
		}
	}

	cout << "\n\n";
	if (soLuongCLC) {
		cout << sep << setw(3) << "ID" << sep << setw(nameWidth) << "Ho va ten" << sep << setw(5) << "He" << sep << setw(intWidth) << "Gioi tinh"
			<< sep << setw(4) << "GPA" << sep << setw(intWidth) << "Xep loai" << sep << setw(12) << "SDT"
			<< sep << setw(intWidth) << "Hoc ki" << sep << setw(intWidth) << "Hoc phi" << "\n";
		for (Student* s : studentsList) {
			if (s->getHe() == "CLC")
				cout << *s;
		}
	}
	system("pause");
}

void QLySinhVien::addStudent() {
	cout << "Nhap vao so luong sinh vien can chen them: ";
	int num;
	cin >> num;
	soLuong += num;
	for (int i = 0; i < num; i++) {
		this->input();
	}
}

int QLySinhVien::findStudent(string name) {
	int indexStudent = -1;
	for (int i = 0; i < soLuong; i++) {
		if (studentsList[i]->getName() == name)
			indexStudent = i;
	}
	return indexStudent;
}

void QLySinhVien::deleteStudent() {
	cout << "Nhap vao ten sinh vien can xoa khoi danh sach: ";
	string tempName;
	cin.ignore();
	getline(cin, tempName);
	//cin.ignore();
	int indexStudent = findStudent(tempName);
	if (indexStudent == -1) {
		cout << "Khong tim thay sinh vien.\n";
		system("pause");
		return;
	}
	else {
		if (studentsList[indexStudent]->getHe() == "CQ")
			this->soLuongCQ--;
		if (studentsList[indexStudent]->getHe() == "CLC")
			this->soLuongCLC--;
		this->soLuong--;
		studentsList.erase(studentsList.begin() + indexStudent);
		cout << "Da xoa xong sinh vien.\n";
		system("pause");
		return;
	}
}

void QLySinhVien::sortFee() {
	sort(studentsList.begin(), studentsList.end(), compareFee); //Thu vien Algorithm
	cout << "Da sap xep xong.\n";
	system("pause");
}

unsigned int QLySinhVien::avgFee() {
	unsigned int avg = 0;
	for (Student* s : studentsList)
		avg += s->getFee();
	return avg/soLuong;
}

void QLySinhVien::listFee() {
	unsigned int avg = avgFee();
	cout << "Hoc phi trung binh: " << avg << "\n";
	cout << "Cac sinh vien co hoc phi lon hon hoc phi trung binh\n";
	cout << sep << setw(nameWidth) << "Ho va ten" << sep << setw(intWidth) << "He"
		<< sep << setw(intWidth) << "So mon LT" << sep << setw(intWidth) << "So mon TH" << sep << setw(intWidth) << "Tong TC"
		<< sep << setw(intWidth) << "Hoc phi" << "\n";
	for (Student* s : studentsList) {
		if (s->getHe() == "CQ" && (s->getFee()) > avg)
			cout << *s;
	}

	cout << "\n\n";

	cout << sep << setw(nameWidth) << "Ho va ten" << sep << setw(intWidth) << "He"
		<< sep << setw(intWidth) << "Hoc ki" << sep << setw(intWidth) << "Hoc phi" << "\n";
	for (Student* s : studentsList) {
		if (s->getHe() == "CLC" && s->getFee() > avg)
			cout << *s;
	}
	system("pause");
}


void QLySinhVien::writeToFile() {
	fstream file;
	file.open("danhsach.txt", ios::out);
	if (!file) {
		cout << "Mo file bi loi!\n";
		system("pause");
		return;
	}
	else {
		if (soLuongCQ) {
			file << sep << setw(3) << "ID" << sep << setw(nameWidth) << "Ho va ten" << sep << setw(5) << "He" << sep << setw(intWidth) << "Gioi tinh"
				<< sep << setw(4) << "GPA" << sep << setw(intWidth) << "Xep loai" << sep << setw(12) << "SDT"
				<< sep << setw(intWidth) << "So mon LT" << sep << setw(intWidth) << "So mon TH" << sep << setw(8) << "Tong TC"
				<< sep << setw(intWidth) << "Hoc phi" << "\n";
			for (Student* s : studentsList) {
				if (s->getHe() == "CQ")
					file << *s;
			}
		}

		file << "\n\n";
		if (soLuongCLC) {
			file << sep << setw(3) << "ID" << sep << setw(nameWidth) << "Ho va ten" << sep << setw(5) << "He" << sep << setw(intWidth) << "Gioi tinh"
				<< sep << setw(4) << "GPA" << sep << setw(intWidth) << "Xep loai" << sep << setw(12) << "SDT"
				<< sep << setw(intWidth) << "Hoc ki" << sep << setw(intWidth) << "Hoc phi" << "\n";
			for (Student* s : studentsList) {
				if (s->getHe() == "CLC")
					file << *s;
			}
		}
		file.close();
		cout << "Da ghi vao file.\n";
		system("pause");
	}
}

void QLySinhVien::console() {
	int option;
	do {
		system("cls");
		cout << "===== MENU =====";
		cout << "\n1. Nhap danh sach";
		cout << "\n2. In danh sach";
		cout << "\n3. Them sinh vien vao danh sach";
		cout << "\n4. Xoa thong tin sinh vien";
		cout << "\n5. Sap xep sinh vien theo hoc phi tang dan";
		cout << "\n6. Liet ke cac sinh vien co hoc phi cao hon hoc phi trung binh";
		cout << "\n7. Ghi danh sach vao file";
		cout << "\n8. Thoat";
		cout << "\nNhap lua chon: ";
		cin >> option;
		switch (option) {
		case 1:
			inputList();
			break;
		case 2:
			outputList();
			break;
		case 3:
			addStudent();
			break;
		case 4:
			deleteStudent();
			break;
		case 5:
			sortFee();
			break;
		case 6:
			listFee();
			break;
		case 7:
			writeToFile();
			break;
		}
	} while (option != 8);
}

bool compareFee(Student* a, Student* b) {
	return (a->getFee()) < (b->getFee());
}