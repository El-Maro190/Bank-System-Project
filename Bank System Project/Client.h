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
		Person(id, name, password) {
		if (Validation::isValidationbalance(balance))
		{
			this->balance = balance;
		}
		else {
			cout << "Invalid balance" << "\n";
		}
	}

	void setBalance(double balance) {
		this->balance = balance;
	}

	double getBalance() {
		return this->balance;
	}

	bool deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			return true;
		}
		else {
			return false;
		}
	}
	bool withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			return true;
		}
		else {
			return false;
		}
	}
	bool transferTo(double amount, Client* recipient) {
		if (recipient == nullptr) {
			cout << "Error: Recipient does not exist.\n";
			return false;
		}
		if (amount > 0 && amount <= balance) {
			if (withdraw(amount)) {
				if (recipient->deposit(amount))
				{
					return true;
				}
				else {
					deposit(amount);
					return false;
				}
			}
		}
		return false;
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

