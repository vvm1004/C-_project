#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
#include<typeinfo>
#include<vector>
#include<conio.h>
#include<Windows.h>

using namespace std;
class Address {
private:
	int number;
	string street, district, city;
public:
	//ham khoi tao co doi so
	Address(int number = 0, string street = " ", string district = " ", string city = " ") {
		this->number = number;
		this->street = street;
		this->district = district;
		this->city = city;
	}
	int getNumber() {
		return this->number;

	}
	string getStreet() {
		return street;
	}
	string getDistrict() {
		return district;
	}
	string getCity() {
		return city;
	}
	void setNumber(int x) {
		number = x;
	}
	void setStreet(string s) {
		street = s;
	}
	void setDistrict(string s) {
		district = s;
	}
	void setCity(string s) {
		city = s;
	}

	void input() {
		cout << "ADDRESS:\nEnter number:"; cin >> number;
		cout << "Enter street:";
		cin.ignore();//xoa ky tu dau tien trong bo nho dem
		getline(cin, street);
		cout << "Enter district:";
		getline(cin, district);
		cout << "Enter city:";
		getline(cin, city);
	}
	void output() {
		cout << "Address: Number " << number << " " << street << ", " << district << ", " << city << "city" << endl;
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend

	friend istream& operator >> (istream& in, Address& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, Address& another) {
		another.output();
		return out;
	}
};
class DateOfBirth {
private:
	int day, month, year;
	int maxDay(int month, int year) {
		switch (month)
		{
		case 1:case 3: case 5: case 7:case 8: case 10: case 12: return 31;
		case 4: case 6:case 9: case 11: return 30;
		case 2:
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 29;
			else return 28;
		default: return 0;
		}
	}
public:
	//ham khoi tao
	DateOfBirth(int day = 1, int month = 1, int year = 1000) {
		setYear(year);
		setMonth(month);
		setDay(day);


	}
	void setDay(int day) {
		if (day <= 0 || day > maxDay(month, year)) this->day = 1;
		else this->day = day;
	}
	void setMonth(int month) {
		if (month <= 0 || month > 12) this->month = 1;
		else this->month = month;
	}
	void setYear(int year) {
		if (year <= 0) this->year = 1000;
		else this->year = year;
	}
	int getDay() {
		return this->day;
	}
	int getMonth() {
		return this->month;
	}
	int getYear() {
		return this->year;
	}

	void input()
	{

		cout << "DATE OF BIRTH\nEnter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
		setYear(year);
		setMonth(month);
		setDay(day);
	}
	void output() {
		cout << "Date of brith: " << day << "/" << month << "/" << year << endl;
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend
	friend istream& operator >> (istream& in, DateOfBirth& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, DateOfBirth& another) {
		another.output();
		return out;
	}
};
class Person {
protected:
	string firstName, lastName;
	bool gender;
	string phone;
	Address address;
	DateOfBirth dob;
public:
	//ham tao co doi
	Person(string fristName = "", string lastName = "", bool gender = true, string phone = "", Address address1 = NULL, DateOfBirth dob = NULL)
	{
		this->firstName = fristName;
		this->lastName = lastName;
		this->gender = gender;
		this->phone = phone;
		address = address1;
		this->dob = dob;
	}

	string getFirstName() {
		return firstName;
	}
	string getLastName() {
		return lastName;
	}
	bool getGender() {
		return gender;
	}
	string getPhone() {
		return phone;
	}
	DateOfBirth getDOB() {
		return dob;
	}
	Address getAddress() {
		return address;
	}
	void setFirstName(string firstname)
	{
		this->firstName = firstname;
	}
	void setLastName(string lastname)
	{
		this->lastName = lastname;
	}
	void setGender(bool gender)
	{
		this->gender = gender;
	}
	void setPhone(string phone)
	{
		this->phone = phone;
	}
	void setDOB(DateOfBirth dob)
	{
		this->dob = dob;
	}
	void setAddress(Address address)
	{
		this->address = address;
	}
	void input() {
		cout << "Enter last name: ";
		cin.ignore();
		getline(cin, lastName);
		cout << "Enter first name: ";
		getline(cin, firstName);
		cout << "Enter phone: ";
		getline(cin, phone);
		cout << "Enter 1 if you are male, enter 0 if you are female." << endl;
		cin >> gender;
		address.input();
		dob.input();
	}
	void output() {
		cout << "Name: " << lastName << " " << firstName << endl;
		cout << "Phone: " << getPhone() << endl;
		if (gender) {
			cout << "Gender: male" << endl;
		}
		else cout << "Gender: female" << endl;
		dob.output();
		address.output();
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend
	friend istream& operator >> (istream& in, Person& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, Person& another) {
		another.output();
		return out;
	}
};
class Student :public Person {//thua ke tu class person
protected:
	string department;
	long id;
	double mediumScore;
	double math, physical;

public:
	Student(string department = "", long studentCode = 0, string fristName = "", string lastName = "", bool gender = true, string phone = "", Address address1 = NULL, DateOfBirth dob = NULL, double math = 0, double physical = 0, double mediumScore = 0) :Person(fristName, lastName, gender, phone, address1, dob)
	{
		this->department = department;
		this->id = studentCode;
		this->math = math;
		this->physical = physical;
		this->mediumScore = computeMediumScore();
	}
	virtual void input() {//tinh da hinh
		cout << "Enter student code:";
		cin >> id;

		Person::input();
		cout << "Enter math point:";
		cin >> math;
		cout << "Enter physical point:";
		cin >> physical;


	}
	void setDepartment(string k) {
		department = k;
	}
	void setID(long k) {
		id = k;
	}
	void setMath(double k) {
		math = k;
	}
	void setPhysical(double k) {
		physical = k;
	}
	virtual void setOOP(double k) {}//tinh da hinh
	virtual void setEconomics(double k) {}//tinh da hinh
	virtual void setArt(double k) {}//tinh da hinh
	long getID() {
		return id;
	}
	string getDepartment() {
		return department;
	}
	double getMath() {
		return math;
	}
	double getPhysical() {
		return physical;
	}
	virtual double getOOP() {//tinh da hinh
		return 0;
	}
	virtual double getEconomics() {//tinh da hinh
		return 0;
	}
	virtual double getArt() {//tinh da hinh
		return 0;
	}
	virtual void output() {//tinh da hinh
		cout << "\n\nDepartment: " << department << endl;
		cout << "Student code: " << id << endl;
		Person::output();
		cout << "Math: " << math << endl;
		cout << "Physical: " << physical << endl;
	}
	virtual double computeMediumScore() {//tinh da hinh
		return 0;
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend
	friend istream& operator >> (istream& in, Student& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, Student& another) {
		another.output();
		return out;
	}

};
class CMU :public Student {//Thuaf ke tu class Student
private:
	double OOP;
public:
	CMU(string choose = "", long id = 0, string firstName = "", string lastName = "", bool gender = true, string phone = "", Address add = NULL, DateOfBirth dob = NULL, double math = 0, double physical = 0, double OOP = 0) :Student(choose, id, firstName, lastName, gender, phone, add, dob, math, physical, 0) {
		this->OOP = OOP;
	}
	void input() {
		Student::input();
		cout << "Enter OOP point:";
		cin >> OOP;
	}
	double computeMediumScore() {
		return mediumScore = (OOP + math + physical) / 3;
	}
	void output() {
		Student::output();
		cout << "OOP: " << OOP << endl;
		cout << "Medium score: " << computeMediumScore() << endl;
	}
	void setOOP(double x) {
		OOP = x;
	}
	double getOOP() {
		return OOP;
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend
	friend istream& operator << (istream& in, CMU& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, CMU& another) {
		another.output();
		return out;
	}
};
class PSU :public Student {//Thuaf ke tu class Student
private:
	double economics;
public:
	PSU() :Student("", 0, "", "", true, "", NULL, NULL, 0, 0, 0) {
		economics = 0;
	}
	PSU(string choose, long id, string firstName, string lastName, bool gender, string phone, Address add, DateOfBirth dob, double math, double physical, double lec) :Student(choose, id, firstName, lastName, gender, phone, add, dob, math, physical, 0) {
		this->economics = lec;
	}
	void input() {
		Student::input();
		cout << "Enter economics point:";
		cin >> economics;
	}
	double computeMediumScore() {
		return mediumScore = (economics + math + physical) / 3;
	}
	void output() {
		Student::output();
		cout << "economics: " << economics << endl;
		cout << "Medium score: " << computeMediumScore() << endl;
	}
	void setEconomics(double k) {
		economics = k;
	}
	void inputFile(ifstream& filein) {
		filein >> economics;
	}
	double getEconomics() {
		return economics;
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend
	friend istream& operator << (istream& in, PSU& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, PSU& another) {
		another.output();
		return out;
	}
};
class CSU :public Student {//Thuaf ke tu class Student
private:
	double art;
public:
	CSU() :Student("", 0, "", "", true, "", NULL, NULL, 0, 0, 0) {
		art = 0;
	}
	CSU(string choose, long id, string firstName, string lastName, bool gender, string phone, Address add, DateOfBirth dob, double math, double physical, double art) :Student(choose, id, firstName, lastName, gender, phone, add, dob, math, physical, 0) {
		this->art = art;
	}
	void input() {
		Student::input();
		cout << "Enter art point:";
		cin >> art;
	}
	double computeMediumScore() {
		return mediumScore = (art + math + physical) / 3;
	}
	void output() {
		Student::output();
		cout << "Art: " << art << endl;
		cout << "Medium score: " << computeMediumScore() << endl;
	}
	double getArt() {
		return art;
	}
	void setArt(double k) {
		art = k;
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend
	friend istream& operator << (istream& in, CSU& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, CSU& another) {
		another.output();
		return out;
	}
};
class ArrayOfStudents  {
private:
	Student** a;
	int n;
public:
	ArrayOfStudents(Student** a = NULL, int n = 0) {
		this->n = n;
		this->a = new Student * [this->n];
		for (int i = 0; i < n; i++) {
			this->a[i] = a[i];
		}
	}
	//Ham sao chep
	ArrayOfStudents(const ArrayOfStudents& nguon) {
		this->n = nguon.n;
		this->a = new Student * [this->n];//khoi tao a la mot mang con tro
		for (int i = 0; i < n; i++) {
			this->a[i] = nguon.a[i];
		}
	}
	//Toan tu gan
	ArrayOfStudents& operator=(ArrayOfStudents& nguon) {
		this->n = nguon.n;
		this->a = new Student * [this->n];
		for (int i = 0; i < n; i++) {
			this->a[i] = nguon.a[i];
		}
		return *this;
	}
	~ArrayOfStudents() {
		if (a != NULL) delete[]a;
	}

	void inputFile() {

		fstream filein;
		filein.open("ListStudent.txt", ios::in);
		filein >> n;
		string choose;
		getline(filein, choose);
		a = new Student * [n];
		for (int i = 0; i < n; ++i)
		{
			filein >> choose;
			if (choose == "CMU")
			{

				long id;
				filein >> id;

				string tmp;
				filein.ignore();
				getline(filein, tmp);
				int x = tmp.rfind(' ');// tim ky tu ' ' tu phai qua trai
				string firstname = tmp.substr(x + 1, tmp.length());
				string lastname = tmp.substr(0, x);
				bool gender;
				filein >> gender;
				string phone;
				filein.ignore();
				getline(filein, phone);
				int day;
				filein >> day;
				filein.ignore();
				int month;
				filein >> month;
				filein.ignore();
				int year;
				filein >> year;
				int number;
				filein >> number;
				string street;
				getline(filein, street, ',');
				getline(filein, street, ',');
				string district;
				getline(filein, district, ',');
				string city;
				getline(filein, city);
				double math, physical, OOP;
				filein >> math;

				filein >> physical;
				filein >> OOP;
				DateOfBirth dob(day, month, year);
				Address add(number, street, district, city);
				this->a[i] = new CMU(choose, id, firstname, lastname, gender, phone, add, dob, math, physical, OOP);
			}
			else if (choose == "PSU") {


				long id;
				filein >> id;

				string tmp;
				filein.ignore();
				getline(filein, tmp);
				int x = tmp.rfind(' ');// tim ky tu ' ' tu phai qua trai
				string firstname = tmp.substr(x + 1, tmp.length());
				string lastname = tmp.substr(0, x);
				bool gender;
				filein >> gender;
				string phone;
				filein.ignore();
				getline(filein, phone);
				int day;
				filein >> day;
				filein.ignore();
				int month;
				filein >> month;
				filein.ignore();
				int year;
				filein >> year;
				int number;
				filein >> number;
				string street;
				getline(filein, street, ',');
				getline(filein, street, ',');
				string district;
				getline(filein, district, ',');
				string city;
				getline(filein, city);
				double math, physical, OOP;
				filein >> math;

				filein >> physical;
				filein >> OOP;
				DateOfBirth dob(day, month, year);
				Address add(number, street, district, city);
				this->a[i] = new PSU(choose, id, firstname, lastname, gender, phone, add, dob, math, physical, OOP);

			}
			else
			{

				long id;
				filein >> id;

				string tmp;
				filein.ignore();
				getline(filein, tmp);
				int x = tmp.rfind(' ');// tim ky tu ' ' tu phai qua trai
				string firstname = tmp.substr(x + 1, tmp.length());
				string lastname = tmp.substr(0, x);
				bool gender;
				filein >> gender;
				string phone;
				filein.ignore();
				getline(filein, phone);
				int day;
				filein >> day;
				filein.ignore();
				int month;
				filein >> month;
				filein.ignore();
				int year;
				filein >> year;
				int number;
				filein >> number;
				string street;
				getline(filein, street, ',');
				getline(filein, street, ',');
				string district;
				getline(filein, district, ',');
				string city;
				getline(filein, city);
				double math, physical, OOP;
				filein >> math;

				filein >> physical;
				filein >> OOP;
				DateOfBirth dob(day, month, year);
				Address add(number, street, district, city);
				this->a[i] = new CSU(choose, id, firstname, lastname, gender, phone, add, dob, math, physical, OOP);
			}
			string t;
			filein >> t;

		}

		filein.close();

	}
	void outputFile() {
		ofstream fileout;
		fileout.open("ListST.txt", ios::out);
		if (fileout.is_open()) {
			for (int i = 0; i < n; i++) {
				fileout << a[i]->getDepartment() << endl << a[i]->getID() << endl << a[i]->getLastName() << " " << a[i]->getFirstName() << endl;
				fileout << a[i]->getGender() << endl << a[i]->getPhone() << endl;
				fileout << a[i]->getDOB().getDay() << "/" << a[i]->getDOB().getMonth() << "/" << a[i]->getDOB().getYear() << endl;
				fileout << a[i]->getAddress().getNumber() << ", " << a[i]->getAddress().getStreet() << ", " << a[i]->getAddress().getDistrict() << ", " << a[i]->getAddress().getCity() << endl;
				fileout << a[i]->getMath() << endl << a[i]->getPhysical() << endl;
				if (typeid(*a[i]) == typeid(CMU)) {
					fileout << a[i]->getOOP() << endl;
				}
				else if (typeid(*a[i]) == typeid(PSU)) {
					fileout << a[i]->getEconomics() << endl;
				}
				else fileout << a[i]->getArt() << endl;

				fileout << a[i]->computeMediumScore() << endl;
				fileout << "-------------------*-------------------" << endl;
			}
		}
		fileout.close();
	}
	void input() {
		cout << "Enter n:" << endl;
		cin >> n;
		a = new Student * [n];
		for (int i = 0; i < n; i++) {
			cout << "------------------STUDENT " << i << " ------------------" << endl;
			string k;
			cout << "Enter department(CMU/PSU/CSU):";
			cin >> k;
			for (int j = 0; j < k.length(); j++)
				k[j] = toupper(k[j]);

			if (k == "CMU") {
			
				a[i] = new CMU(); //tinh da hinh
				a[i]->setDepartment(k);
				a[i]->input();
				for(int m=0;m<i;m++)
	        	{	
	            	while(a[i]->getID()==a[m]->getID())
	            	{
	                	
	                	delete a[i];
	                	cout<<"\n\nDuplicate id ! Please re-enter: \n\n";
	                	cout << "------------------STUDENT " << i << " ------------------" << endl;
	                	a[i] = new CMU(); //tinh da hinh
						a[i]->setDepartment(k);
	                	a[i]->input(); //nhap lai
	                	
	            	}
	        	}
				
				
			}
			else if (k == "PSU") {
				a[i] = new PSU(); //tinh da hinh
				a[i]->setDepartment(k);
				a[i]->input();
				for(int m=0;m<i;m++)
	        	{	
	            	while(a[i]->getID()==a[m]->getID()) // neu id trung thi lap
	            	{
	                	
	                	delete a[i]; //neu id trung thi xoa phan tu do roi nhap lai
	                	cout<<"\n\nDuplicate id ! Please re-enter: \n\n";
	                	cout << "------------------STUDENT " << i << " ------------------" << endl;
	                	a[i] = new PSU(); //tinh da hinh
						a[i]->setDepartment(k);
	                	a[i]->input();//nhap lai
	                	
	            	}
	        	}
			}
			else if (k == "CSU") {
				a[i] = new CSU(); //tinh da hinh
				a[i]->setDepartment(k);
				a[i]->input();
				for(int m=0;m<i;m++)
	        	{	
	            	while(a[i]->getID()==a[m]->getID()) // neu id trung thi lap
	            	{
	                	
	                	delete a[i]; //neu id trung thi xoa phan tu do roi nhap lai
	                	cout<<"\n\nDuplicate id ! Please re-enter: \n\n";
	                	cout << "------------------STUDENT " << i << " ------------------" << endl;
	                	a[i] = new CSU(); //tinh da hinh
						a[i]->setDepartment(k);
	                	a[i]->input(); //nhap lai
	                	
	            	}
	        	}
		}
	}
}
	void output() {
		cout << "----------------------*Students list*----------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << "----------------------*Students " << i << " * ----------------------" << endl;
			a[i]->output();

		}
	}
	void deleteStudent() {
		long choose;
		cout << "\t\t\t\t*------------------------DELETE------------------------*" << endl;
		cout << "\t\t\t\tEnter the student code to delete: ";
		cin >> choose;
		int index;
		bool check = false;
		for (index = 0; index < n; index++) {
			if (a[index]->getID() == choose) {
				check = true;
				break;
			}
		}
		if (check == true) {
			for (int i = index; i < n; i++) {
				a[i] = a[i + 1];
			}
			n--;
			cout << "\n\n\n\n\t\t\t\t*--------------------Successful delete---------------------*" << endl;
		}
		else cout << "\t\t\t\t*------------------------Student not found------------------------*" << endl;

	}



	void addNewStudent() {

		string k;
		cout << "Enter department:";
		cin >> k;
		for (int i = 0; i < k.length(); i++) {
			k[i] = toupper(k[i]);
		}
		n++;
		if (k == "CMU") {
			a[n - 1] = new CMU();//tinh da hinh
			a[n - 1]->setDepartment(k);
			a[n - 1]->input();
		}
		else if (k == "PSU") {
			a[n - 1] = new PSU();//tinh da hinh
			a[n - 1]->setDepartment(k);
			a[n - 1]->input();
		}
		else {
			a[n - 1] = new CSU();//tinh da hinh
			a[n - 1]->setDepartment(k);
			a[n - 1]->input();
		}
	}
	void searchStudent() {
		cout << "\t\t\t\t--------------------Find a student--------------------" << endl;
		cout << " Enter student code: ";
		long code;
		cin >> code;
		bool check = false;
		cout << "\t\t\t\t-------------Student information you find-------------" << endl;
		for (int i = 0; i < n; i++) {
			if (a[i]->getID() == code) {
				check = true;
				a[i]->output();
				break;
			}
		}
		if (check == false)cout << "\t\t\t\t*------------------------Student not found------------------------*" << endl;

	}
	void edit(int index) {
		int choose;
		string cho1;
		do {
			cout << "\t\t\t\t*------------------------EDIT------------------------*\n\t\t1)Department\n\t\t2)ID\n\t\t3)Name\n\t\t4)Address\n\t\t5)DayOfBirth\n\t\t6Point\n\t\t7)All of the above\n\t\t8)Exit. ";

			cout << "\nEnter select: "; cin >> cho1;
			choose = atoi(cho1.c_str());
			switch (choose) {
			case 1:
			{
				string k;
				cout << "Enter new department: "; cin >> k;
				for (int i = 0; i < k.length(); i++)
					k[i] = toupper(k[i]);

				if (k == "CMU") {
					cout << "Enter OOP point: ";
					double point;
					cin >> point;
					a[index] = new CMU(k, a[index]->getID(), a[index]->getFirstName(), a[index]->getLastName(), a[index]->getGender(), a[index]->getPhone(), a[index]->getAddress(), a[index]->getDOB(), a[index]->getMath(), a[index]->getPhysical(), point);

				}
				else if (k == "PSU") {
					cout << "Enter economics point: ";
					double point;
					cin >> point;
					a[index] = new PSU(k, a[index]->getID(), a[index]->getFirstName(), a[index]->getLastName(), a[index]->getGender(), a[index]->getPhone(), a[index]->getAddress(), a[index]->getDOB(), a[index]->getMath(), a[index]->getPhysical(), point);

				}
				else if (k == "CSU") {
					cout << "Enter art point: ";
					double point;
					cin >> point;
					a[index] = new CSU(k, a[index]->getID(), a[index]->getFirstName(), a[index]->getLastName(), a[index]->getGender(), a[index]->getPhone(), a[index]->getAddress(), a[index]->getDOB(), a[index]->getMath(), a[index]->getPhysical(), point);
				}
				break;
			}
			case 2:
			{
				cout << "Enter new ID: ";
				long id;
				cin >> id;
				a[index]->setID(id);
				break;
			}
			case 3:
			{
				string name;
				cin.ignore();
				cout << "Enter new name: "; getline(cin, name);
				int x = name.rfind(' ');// tim ky tu ' ' tu phai qua trai
				string fname = name.substr(x + 1, name.length());
				string lname = name.substr(0, x);
				a[index]->setFirstName(fname);
				a[index]->setLastName(lname);
				break;
			}
			case 4:
			{
				Address add;
				add.input();
				a[index]->setAddress(add);
				break;
			}
			case 5:
			{
				DateOfBirth dob;
				dob.input();
				a[index]->setDOB(dob);
				break;
			}
			case 6:
			{
				double math, physical, point;
				cout << "Enter math: "; cin >> math;
				cout << "Enter physical: "; cin >> physical;
				a[index]->setMath(math);
				a[index]->setPhysical(physical);
				if (typeid(*a[index]) == typeid(CMU)) {
					cout << "Enter OOP: "; cin >> point;
					a[index]->setOOP(point);
				}
				else if (typeid(*a[index]) == typeid(PSU)) {
					cout << "Enter economics: "; cin >> point;
					a[index]->setEconomics(point);
				}
				else {
					cout << "Enter art: "; cin >> point;
					a[index]->setArt(point);
				}
				break;
			}
			case 7:
			{

				string k;
				cout << "Enter department:";
				cin >> k;
				if (k == "CMU") {
					a[index] = new CMU();//tinh da hinh
					a[index]->setDepartment(k);
					a[index]->input();

				}
				else if (k == "PSU") {
					a[index] = new PSU();//tinh da hinh
					a[index]->setDepartment(k);
					a[index]->input();
				}
				else if (k == "CSU") {
					a[index] = new CSU();//tinh da hinh
					a[index]->setDepartment(k);
					a[index]->input();
				}
				break;

			}
			case 8:
			{
				choose = 100;
				break;
			}
			default:
			{
				cout << "Retype.";
				break;
			}
			}
			system("pause");
			system("cls");
		} while (choose != 100);
	}
	void editStudent() {
		cout << "\t\t\t-------------------------EDIT-----------------------" << endl;
		cout << "\t\t\tEnter the student id you want to edit: ";
		long code;
		string cho1;
		cin >> cho1;
		code = atoi(cho1.c_str());
		bool check = false;

		for (int i = 0; i < n; i++) {
			if (a[i]->getID() == code) {
				edit(i);
				check = true;
				break;
			}
		}
		if (check == false) {
			cout << "Invalid student code" << endl;
		}
		else cout << "Successful edit. " << endl;
	}
	void pointMax() {
		int index = 0;
		double max = a[0]->computeMediumScore();// da hinh
		for (int i = 1; i < n; i++) {
			if (max < a[i]->computeMediumScore()) {
				max = a[i]->computeMediumScore();
				index = i;
			}
		}
		cout << "\t\t\t\tThe student with the highest average." << endl;
		a[index]->output();
	}
	void ascending() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i]->computeMediumScore() > a[j]->computeMediumScore()) {

					Student* tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;

				}
			}
		}
		cout << "\n\n\n\n\t\t\t\t\t----------------Sort successful.----------------" << endl;
	}
	void descending() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i]->computeMediumScore() < a[j]->computeMediumScore()) {

					Student* tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;

				}
			}
		}
		cout << "\n\n\n\n\t\t\t\t\t----------------Sort successful.----------------" << endl;
	}
	void alphabetically() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i]->getFirstName() > a[j]->getFirstName()) {
					Student* tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;

				}
				else if (a[i]->getFirstName() == a[j]->getFirstName()) {
					if (a[i]->getLastName() > a[j]->getLastName()) {
						Student* tmp = a[i];
						a[i] = a[j];
						a[j] = tmp;
					}
				}
			}
		}
		cout << "\n\n\n\n\t\t\t\t\t----------------Sort successful.----------------" << endl;
	}
	void sort() {
		int choose;
		do {
			cout << "Enter (1) if sort ascending, (2) if sort descending, (3) sort alphabetically and (4) key to exit.: ";
			
			string cho1;
			cin >> cho1;
			choose = atoi(cho1.c_str());//ep bien cho1 sang kieu int
			switch (choose) {
			case 1:
				ascending();
				break;
			case 2:
				descending();
				break;
			case 3:
				alphabetically();
				break;
			case 4:
				break;
			default:
				cout << "\t\t----------------Illegal.Please re - enter.----------------" << endl;
				break;
			}
			
		
		
		} while (choose!=4);
	}
	void student2003() {
		int k = 0;
		cout << "--------------------Student list 2003.------------------------" << endl;
		for (int i = 0; i < n; i++) {

			if (a[i]->getDOB().getYear() == 2003) {
				cout << "--------------------Student " << i << ".------------------------" << endl;
				a[i]->output();
				k++;

			}
		}
		if (k == 0) cout << "------------------------Not found student.------------------------" << endl;

	}
	void findStudentByGrade() {
		double p;
		cout << "Enter the number of points to find:"; cin >> p;
		int choose;
	
		string cho1;
		do {
			cout << "Enter number (1) if find is greater than (0) if search is less than  (2) if find is equal and (3) if exit:"; cin >> cho1;
			bool kt = false;
			choose = atoi(cho1.c_str());
			if (choose == 2) {
				cout << "List of students with a score of:" << p << ":" << endl;

				for (int i = 0; i < n; i++) {
					if (a[i]->computeMediumScore() == p) {
						a[i]->output();
						kt = true;
						cout << "------------------------------------------------------" << endl;
					}
				}
				if (kt == false)cout << "\t\tNot found" << endl;
			}
			else if (choose == 1) {
				cout << "-------------List of students with scores greater than " << p << "----------------" << endl;
				for (int i = 0; i < n; i++) {
					if (a[i]->computeMediumScore() > p) {
						a[i]->output();
						kt = true;
						cout << "------------------------------------------------------" << endl;
					}
				}
				if (kt == false)cout << "\t\tNot found" << endl;
			}

			else if (choose == 0)
			{
				cout << "-------------List of students with scores less than " << p << "----------------" << endl;
				for (int i = 0; i < n; i++) {
					if (a[i]->computeMediumScore() < p) {
						a[i]->output();
						kt = true;
						cout << "------------------------------------------------------" << endl;
					}
				}
				if (kt == false) cout << "\t\tNot found" << endl;
			}
			else if (choose != 3)cout << "Syntax error" << endl;
		} while (choose != 3);
	}
	//chong toan tu >> (nhap): doi so dau tien la doi tuong istream thi dung ham friend
	friend istream& operator >> (istream& in, ArrayOfStudents& another) {
		another.input();
		return in;
	}
	//chong toan tu << (xuat): doi so dau tien la doi tuong ostream thi dung ham friend
	friend ostream& operator << (ostream& out, ArrayOfStudents& another) {
		another.output();
		return out;
	}


	void menu() {
		cout << "\t\t*--------------------Student Management--------------------*" << endl;
		cout << "\t\t*\t1.Import data from file.                           *" << endl;
		cout << "\t\t*\t2.Write data to file.                              *" << endl;
		cout << "\t\t*\t3.Input student list.                              *" << endl;
		cout << "\t\t*\t4.Display student list information.                *" << endl;
		cout << "\t\t*\t5.Remove a student.                                *" << endl;
		cout << "\t\t*\t6.Looking for a student.                           *" << endl;
		cout << "\t\t*\t7.Find the student with the highest average.       *" << endl;
		cout << "\t\t*\t8.Add a new student.                               *" << endl;
		cout << "\t\t*\t9.Edit student information.                        *" << endl;
		cout << "\t\t*\t10.Sort students list.                             *" << endl;
		cout << "\t\t*\t11.Student was born in 2003                        *" << endl;
		cout << "\t\t*\t12.Find students by grade                          *" << endl;
		cout << "\t\t*\t13.Exit.                                           *" << endl;

		cout << "\t\t************************************************************" << endl;
	}
	void studentManagement() {
		int choose;	
		string cho1;
		do {
			menu();
			cout << "Enter your select: ";
			cin >> cho1;
			choose = atoi(cho1.c_str());
			
			switch (choose) {
			case 1:
				inputFile();
				cout << "\t\t*------------Import data from file successfully.------------*" << endl;
				break;
			case 2:

				outputFile();
				cout << "\t\t*-------------Write data to file successfully.--------------*" << endl;
				break;
			case 3:
				system("cls");
				input();
				break;
			case 4:
				system("pause ");
				system("cls");
				output();
				break;
			case 5:
				system("cls");
				deleteStudent();

				break;
			case 6:
				searchStudent();
				break;
			case 7:
				system("cls");
				cout << "\t\t\t\t*------------------------POINT MAX------------------------*" << endl;
				pointMax();
				break;
			case 8:
				system("cls");
				addNewStudent();
				cout << "\n\n\n\n\t\t\t\t*----------------------Successful add----------------------* " << endl;
				break;
			case 9:
				system("cls");
				editStudent();
				break;
			case 10:
				system("cls");
				sort();
				break;
			case 11:
				system("cls");
				student2003();
				break;
			case 12:
				system("cls");
				findStudentByGrade();
				break;
			case 13:
				choose = 100;
				break;
			default:
				cout << "\t\t----------------Illegal. Please re-enter.----------------" << endl;
				break;
			}
			system("pause");
			system("cls");

		} while (choose != 100);
	}
};
class systemManagement {
private:
	vector<vector<string> > user;//mang hai chieu vector
	string userName, pass;


public:
	systemManagement() {
		inputFile();
	}
	void inputFile()
	{
		fstream fileUser;
		fileUser.open("USER.txt", ios::in);
		if (fileUser.is_open()) {
			while (!fileUser.eof()) {
				vector<string> colum;//mang mot chieu
				string tmp;
				getline(fileUser, tmp, ' ');
				colum.push_back(tmp);//push tmp vao colum[0]
				getline(fileUser, tmp, '\n');
				colum.push_back(tmp);//push tmp vao colum[1]
				user.push_back(colum);//push colum vao user[0][]
			}
		}
		fileUser.close();//dong file
	}
	void output() {
		for (int i = 0; i < user.size(); i++) {
			cout << user[i][0] << "\t" << user[i][1] << "\n";
		}
	}
	bool check() {
		for (int i = 0; i < user.size(); i++) {
			if (user[i][0] == userName && user[i][1] == pass) {
				return true;
			}
		}
		return false;
	}
	void load()
	{
		// 0 - black background,
		// A - Green Foreground
		system("color 0A");


		char a = 177, b = 219;

		cout << "\n\n\n\n";
		cout << "\n\n\n\n\t\t\t\t\t\t";
		cout << "Loading...\n\n";
		cout << "\t\t\t\t\t\t";


		for (int i = 0; i < 26; i++)
			cout << (char)a; //ep 177 sang char


		cout << "\r";
		cout << "\t\t\t\t\t\t";


		for (int i = 0; i < 26; i++) {
			cout << (char)b;//ep 219 sang char

			// Sleep for 200 miliseconds
			Sleep(200);
		}
	}
	void passSecurity(char s[]) {

		char ch = 0;
		memset(s, ch, 10);//sao chep 10 ki tu ch vao s
		fflush(stdin);//xoa bo nho dem
		int i = 0;
		while (ch != 13)//ch khác ky tu  enter

		{
			fflush(stdin);

			ch = _getch();//nhap mot phim bat ky va tra ve cho ch
			//cout << (int)ch << endl;
			if (ch <= 0) _getch();//Loai cac ky tu dieu khien
			else if (ch > 31 && ch < 127)//Các ky tu thoa man
			{
				cout << '*';
				s[i] = ch;
				i++;
			}
			else if (ch == 8&&i>0)//Xoa 1 ky tu
			{
				i--;
				cout << ch << ' ' << ch;//Xoá ky tu cuoi tren man hinh
			}
		}cout << "\n"; fflush(stdin);

	}
	void endl(int line)
	{
		for (int i = 0; i < line; i++)
			cout << "\n";
	}
	void tab(int tab)
	{
		for (int i = 0; i < tab; i++)
			cout << "\t";
	}
	void space(int space)
	{
		for (int i = 0; i < space; i++)
			cout << " ";
	}
	void prewellcome() {
		system("cls");
		string welcome1 = "WELCOME";
		string welcome2 = "TO";
		string welcome3 = "STUDENT";
		string welcome4 = "MANAGEMENT";
		endl(5); tab(5);
		for (int wlc = 0; wlc < welcome1.length(); wlc++) {
			cout << welcome1[wlc] << " ";
			Sleep(100);
		}
		endl(2); tab(5); space(5);
		for (int wlc2 = 0; wlc2 < welcome2.length(); wlc2++) {
			cout << welcome2[wlc2] << " ";
			Sleep(100);
		}
		endl(2); tab(5);
		for (int wlc3 = 0; wlc3 < welcome3.length(); wlc3++) {
			cout << welcome3[wlc3] << " ";
			Sleep(100);
		}
		endl(2); tab(4);  space(4);
		for (int wlc4 = 0; wlc4 < welcome4.length(); wlc4++) {
			cout << welcome4[wlc4] << " ";
			Sleep(100);
		}
		Sleep(1000);
	}

	void login() {
		do {
			system("cls");
			cout << "\t\t\t\t\t\t------------LOGIN------------" << "\n";
			cout << "\t\t\t\t\t\tUser name:";
			cin >> userName;
			cout << "\t\t\t\t\t\tPassword:";
			char pass1[20];
			passSecurity(pass1);
			pass = pass1;

			load();
			if (check()) {
				prewellcome();
			}
			
		} while (check() == false);
		system("cls");
		ArrayOfStudents a;
		a.studentManagement();
	}



};
int main() {
	systemManagement k;

	k.login();
	//k.output();
//ArrayOfStudents a;
//	a.studentManagement();
	//a.deleteStudent();
	//a.output();
	//a.addNewStudent();
	//a.output();
	//a.outputFile();
	//a.searchStudent();

}
