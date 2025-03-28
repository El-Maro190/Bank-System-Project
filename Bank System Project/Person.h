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

	Person(int id, string name, string password) {
		if (Validation::isValidationName(name) && Validation::isValidationPassword(password))
		{
			this->id = id;
			this->name = name;
			this->password = password;
		}
		else {
			cout << "Invalid name or password" << "\n";
		}
	}

	bool login(int id, string password) {
		if (this->password == password && this->id == id) {
			cout << "Logged in successfully" << "\n";
			return true;
		}
		else {
			return false;
		}
	}

	void setName(string name) {
		this->name = name;
	}
	void setPassword(string password) {
		this->password = password;
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

