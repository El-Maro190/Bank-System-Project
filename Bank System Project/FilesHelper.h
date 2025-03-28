#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

class FilesHelper {
public:
	static void saveLast(string fileName, int id) {
		ofstream file(fileName);
		if (!file) {
			cout << "Error: Unable to open file " << fileName << endl;
			return;
		}
		file << id;
		file.close();
	}

	static int getLast(string fileName) {
		ifstream file(fileName);
		if (!file) {
			cout << "Error: Unable to open file " << fileName << endl;
			return 0;
		}
		int lastID = 0;
		file >> lastID;
		file.close();
		return lastID;
	}

	static void saveClient(Client c) {
		ofstream file("ClientData.txt", ios::app);
		if (!file) {
			cout << "Error: Unable to open ClientData.txt\n";
			return;
		}
		file << c.toString() << endl;
		file.close();
	}

	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		ofstream file(fileName, ios::app);
		if (!file) {
			cout << "Error: Unable to open " << fileName << endl;
			return;
		}
		file << e.toString() << endl;
		file.close();
	}

	static vector<Client> getClients() {
		vector<Client> clients;
		ifstream file("ClientData.txt");

		if (!file) {
			cout << "Error: Unable to open ClientData.txt\n";
			return clients;
		}

		string line;
		while (getline(file, line)) {
			Client client = Parser::ParseToClient(line);
				clients.push_back(client);
		}
		file.close();
		return clients;
	}

	static vector<Employee> getEmployees() {
		vector<Employee> employees;
		ifstream file("EmployeeData.txt");

		if (!file) {
			cout << "Error: Unable to open EmployeeData.txt\n";
			return employees;
		}

		string line;
		while (getline(file, line)) {
			Employee employee = Parser::ParseToEmployee(line);
				employees.push_back(employee);
		}
		file.close();
		return employees;
	}

	static vector<Admin> getAdmins() {
		vector<Admin> admins;
		ifstream file("AdminData.txt");

		if (!file) {
			cout << "Error: Unable to open AdminData.txt\n";
			return admins;
		}

		string line;
		while (getline(file, line)) {
			Admin admin = Parser::ParseToAdmin(line);
			admins.push_back(admin);
		}
		file.close();
		return admins;
	}

	static void clearFile(string fileName, string lastIdFile) {
		ofstream file(fileName, ios::trunc);
		if (!file) {
			cout << "Error: Unable to clear file " << fileName << endl;
			return;
		}
		file.close();

		ofstream idFile(lastIdFile, ios::trunc);
		if (!idFile) {
			cout << "Error: Unable to clear file " << lastIdFile << endl;
			return;
		}
		idFile.close();
	}
};
