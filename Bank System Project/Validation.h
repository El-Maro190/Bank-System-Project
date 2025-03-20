#pragma once
#include <iostream>
#include <string>

using namespace std;

class Validation {
private:
	string name, password;
	double balance, salary;
public:
	static bool isValidationName(string name) {
		return name.length() >= 5 && name.length() <= 20;
	}
	static bool isValidationPassword(string password) {
		return password.length() >= 8 && password.length() <= 20;
	}
	static bool  isValidationbalance(double balance) {
		return balance >= 1500;
	}
	static bool  isValidationSalary(double salary) {
		return salary >= 5000;
	}
};


