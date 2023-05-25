using namespace std;
#include <iostream>

class Person {

protected:
	string name;
	int year_of_birth;    

public:
	Person(const string& name, int year_of_birth): 
			name(name), year_of_birth(year_of_birth){}
	
	virtual void print(ostream& os) const{
		os << "\nName: " << name << "\nYear of birth: " << year_of_birth << "\n";
	}
};

class Worker : public Person {

protected:
	double salary;

public:
	Worker(const string& name, int  year_of_birth, double salary):
		Person(std::move(name),std::move(year_of_birth)), salary(salary){}

	void print(ostream& os) const{
		Person::print(os);
		os << "Salary: " << salary << endl;
	}

	double get_salary() const{
		return salary;
	}
};

class Manager : public Worker {
	string dept;

public:
	Manager(const string& name, int year_of_birth, double salary, const string& dept):
		Worker(std::move(name), std::move(year_of_birth),std::move(salary)), dept(dept){}
	
	void print(ostream& os) const{
		Worker::print(os);
		os << "Dept: " << dept << endl;

	}
	
	string get_dept() const{
		return dept;
	}
};

ostream& operator<<(ostream& os, const Person& person) {
	person.print(os);
	return os;
}

int main() {
	Person p1{"Adrew", 1980};
	Worker w1{"Conrad", 1991, 89000};
	Manager m1{"Sarah", 1979, 130000, "IT"};


	p1.print(cout);
	w1.print(cout);
	m1.print(cout);


	double w1salary = w1.get_salary();
	cout<<"\nWorker 1 salary = "<< w1salary;

	string m1dept = m1.get_dept();
	cout<<"\nManager departament = " << m1dept;


	cout<<p1;
	cout<<w1;
	cout<<m1;

}