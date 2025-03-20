#pragma once
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;
class Admin :public Employee {
public:
	Admin() : Employee() {}
	Admin(int id, string name, string password, double salary) :
		Employee(id, name, password, salary) {
	}

	void addEmployee(Employee employee);

	Employee* searchEmployee(int id);

	void listEmployees();

	void editEmployee(int id, string name, string password, double salary);

	void display() {
		Employee::display();
	}
};

