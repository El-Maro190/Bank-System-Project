#pragma once
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Client :public Person {
private:
	double balance;

public:
	Client() : Person(), balance(0.0) {}
	Client(int id, string name, string password, double balance) :
		Person(id, name, password), balance(balance) {
	}

	void setBalance(double balance) {
		if (Validation::isValidationbalance(balance)) {
			this->balance = balance;
		}
		else {
			cout << "Invalid balance. Must be at least 1500.\n";
		}
	}

	double getBalance() {
		return this->balance;
	}

	void deposit(double amount) {
		balance += amount;
	}
	void withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
		}
		else {
			cout << "Amount exceeded balance" << "\n";
		}
	}
	void transferTo(double amount, Client& recipient) {
		if (amount <= balance) {
			balance -= amount;
			recipient.deposit(amount);
		}
		else {
			cout << "Amount exceeded balance" << "\n";
		}
	}
	void checkBalance() {
		cout << "Check Balance = " << balance << "\n";
	}

	string toString() {
		return to_string(id) + "-" + name + "-" + password + "-" + to_string(balance);
	}

	void display() {
		cout << "Id = " << id << "\n";
		cout << "Name = " << name << "\n";
		cout << "Password = " << password << "\n";
		cout << "Balance = " << balance << "\n";
	}
};

