#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Client.h"

using namespace std;

class Employee :public Person {
protected:
	double salary;

public:
	Employee() : Person(), salary(0.0) {}
	Employee(int id, string name, string password, double salary) :
		Person(id, name, password), salary(salary) {
	}

	void setSalary(double salary) {
		if (Validation::isValidationSalary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Invalid salary. Must be at least 5000.\n";
		}
	}
	double getSalary() {
		return this->salary;
	}

	void addClient(Client client);

	Client* searchClient(int id);

	void listClients();

	void editClient(int id, string name, string password, double balance);

	string toString() {
		return to_string(id) + "-" + name + "-" + password + "-" + to_string(salary);
	}

	void display() {
		cout << "Id = " << id << "\n";
		cout << "Name = " << name << "\n";
		cout << "Password = " << password << "\n";
		cout << "Salary = " << salary << "\n";
	}
};

