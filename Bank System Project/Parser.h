#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser {
public:
	static vector<string> split(string& line) {
		vector<string> result;
		stringstream ss(line);
		string item;

		while (getline(ss, item, '-')) {
			result.push_back(item);
		}

		return result;
	}

	static Client ParseToClient(string& line) {
		vector<string> v = split(line);

		if (v.size() != 4) {
			cout << "Error: Client data is not correct. Line: " << line << endl;
			return Client();
		}

		int id = stoi(v[0]);
		string name = v[1];
		string password = v[2];
		double balance = stod(v[3]);

		return Client(id, name, password, balance);
	}

	static Employee ParseToEmployee(string& line) {
		vector<string> v = split(line);

		if (v.size() != 4) {
			cout << "Error: Employee data is not correct. Line: " << line << endl;
			return Employee();
		}

		int id = stoi(v[0]);
		string name = v[1];
		string password = v[2];
		double salary = stod(v[3]);

		return Employee(id, name, password, salary);
	}

	static Admin ParseToAdmin(string& line) {
		vector<string> v = split(line);

		if (v.size() != 4) {
			cout << "Error: Admin data is not correct. Line: " << line << endl;
			return Admin();
		}

		int id = stoi(v[0]);
		string name = v[1];
		string password = v[2];
		double salary = stod(v[3]);

		return Admin(id, name, password, salary);
	}
};
