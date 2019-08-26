#include <iostream>
using namespace std;

class Person{
private:
	string name;
	int age;
public:
	Person() : name(""), age(0) {
		cout<<"Inside person default constructor"<<endl;
	}
	Person(string perName, int perAge) {
		cout<<"Inside constructor"<<endl;
		name = perName;
		age = perAge;
	}
	Person(const Person& Per) {
		cout<<"Inside copy constructor"<<endl;
		name = Per.name;
		age = Per.age;
	}
	string getName() {
		return name;
	}
	void setName(string namePerson) {
		name = namePerson;
	}
	void setAge(int agePerson) {
		age = agePerson;
	}
	int getAge() {
		return age;
	}
	virtual void printObj() {
		cout<<"Base Person Name: "<<name<<" Person age: "<<age<<endl;
	}

	virtual ~Person() {

	}
};

class Employee : public Person {
private:
    string title;
    string dept;
public:
    Employee(string name, int age, string tit, string dep) {
        setName(name);
        setAge(age);
    	title = tit;
    	dept = dep;
    }

    void printObj() {
    	cout<<"Person Name: "<<getName()<<" Person age: "<<getAge()<<" Emp title: "<<title<<" Emp dept: "<<dept<<endl;
    }

};

void print(Person P) {
	P.printObj();
}

void printRef(Person& P) {
	P.printObj();
}

int main() {
	Person p1("Krsna", 20);
	cout<<"Name: "<<p1.getName()<<" age: "<<p1.getAge()<<endl;
	//To show copy constructor is invoked
	print(p1);
	//copy constructor shouldn't be invoked
	printRef(p1);

    Employee emp("Krsna", 20, "Supreme-God", "Supreme-Control");
    //References prevent object-slicing
    print(emp);
    printRef(emp);

	return 0;
}
