#pragma once
#include <iostream>
#include <string>
#include "Validation.h"

using namespace std;

class Person {
protected:
	string name, password;
	int id;

public:
	Person() : id(0), name("Unknown"), password("1234") {}

	Person(int id, string name, string password) :id(id), name(name), password(password) {}

	bool login(int id, string password) {
		if (this->password == password && this->id == id) {
			cout << "Logged in successfull" << "\n";
			return true;
		}
		else {
			cout << "Error: in password or id" << "\n";
			return false;
		}
	}

	void setName(string name) {
		if (Validation::isValidationName(name)) {
			this->name = name;
		}
		else {
			cout << "Invalid name. Must be alphabetic and 5-20 characters.\n";
		}
	}
	void setPassword(string password) {
		if (Validation::isValidationPassword(password)) {
			this->password = password;
		}
		else {
			cout << "Invalid password. Must be 8-20 characters.\n";
		}
	}
	void setId(int id) {
		this->id = id;
	}

	string getName() {
		return this->name;
	}
	string getPassword() {
		return this->password;
	}
	int getId() {
		return this->id;
	}

	virtual string toString() = 0;

	virtual void display() = 0;
};

