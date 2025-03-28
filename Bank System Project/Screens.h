#pragma once
#include "FileManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

using namespace std;

class Screens
{
public:
	static void bankName() {
		cout << "Welcome to Summit Financial Bank" << endl;
	}

	static void welcome() {
		cout << "Please select an option from the following:" << endl;
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Exit" << endl;
	}

	static void loginScreen() {
		cout << "Please select an option from the following to login as:" << endl;
		cout << "1. Admin" << endl;
		cout << "2. Employee" << endl;
		cout << "3. Client" << endl;
		cout << "4. Back" << endl;
	}

	static void registerScreen() {
		cout << "Please select an option from the following to register as:" << endl;
		cout << "1. Admin" << endl;
		cout << "2. Employee" << endl;
		cout << "3. Client" << endl;
		cout << "4. Back" << endl;
	}

	static void invalid(int c) {
		cout << "Invalid option: " << c << endl;
	}

	static void logout() {
		cout << "You have been logged out." << endl;
	}

	static void quit() {
		cout << "Thank you for using Summit Financial Bank." << endl;
		exit(0);
	}

	static void invalidLogin() {
		cout << "Error: incorrect password or id" << "\n";
	}

	static void invalidRegister() {
		cout << "Error: invalid password or id" << "\n";
	}

	static void loginAdmin() {
		cout << "Enter your id: ";
		int id;
		cin >> id;
		cin.ignore();

		cout << "Enter your password: ";
		string password;
		getline(cin, password);

		Admin* admin = AdminManager::login(id, password);
		if (admin != nullptr) {
			AdminManager::AdminOptions(admin);
		}
		else {
			invalidLogin();
		}
	}
	static void loginEmployee() {
		cout << "Enter your id: ";
		int id;
		cin >> id;
		cin.ignore();
		cout << "Enter your password: ";
		string password;
		getline(cin, password);
		Employee* employee = EmployeeManager::login(id, password);
		if (employee != nullptr) {
			EmployeeManager::employeeOptions(employee);
		}
		else {
			invalidLogin();
		}
	}
	static void loginClient() {
		cout << "Enter your id: ";
		int id;
		cin >> id;
		cin.ignore();
		cout << "Enter your password: ";
		string password;
		getline(cin, password);
		Client* client = ClientManager::login(id, password);
		if (client != nullptr) {
			ClientManager::clientOptions(client);
		}
		else {
			invalidLogin();
		}
	}

	static void registerAdmin() {
		int id;
		id = FilesHelper::getLast("AdminLastID.txt") + 1;
		cin.ignore();
		cout << "Enter your name: ";
		string name;
		getline(cin, name);
		cout << "Enter your password: ";
		string password;
		getline(cin, password);
		cout << "Enter your salary: ";
		double salary;
		cin >> salary;
		Admin* admin = new Admin(id, name, password, salary);
		AdminManager::Register(admin);
	}
	static void registerEmployee() {
		int id;
		id = FilesHelper::getLast("EmployeeLastID.txt") + 1;
		cin.ignore();
		cout << "Enter your name: ";
		string name;
		getline(cin, name);
		cout << "Enter your password: ";
		string password;
		getline(cin, password);
		cout << "Enter your salary: ";
		double salary;
		cin >> salary;
		Employee* employee = new Employee(id, name, password, salary);
		EmployeeManager::Register(employee);
	}
	static void registerClient() {
		int id;
		id = FilesHelper::getLast("ClientLastID.txt") + 1;
		cin.ignore();
		cout << "Enter your name: ";
		string name;
		getline(cin, name);
		cout << "Enter your password: ";
		string password;
		getline(cin, password);
		cout << "Enter your balance: ";
		double balance;
		cin >> balance;
		Client* client = new Client(id, name, password, balance);
		ClientManager::Register(client);
	}

	static void loginOptions() {
		int c;
		do
		{
			loginScreen();
			cin >> c;
			switch (c) {
			case 1:
				loginAdmin();
				break;
			case 2:
				loginEmployee();
				break;
			case 3:
				loginClient();
				break;
			case 4:
				runApp();
				break;
			default:
				invalid(c);
				break;
			}

		} while (c != 4);
	}

	static void registerOptions() {
		int c;
		do
		{
			registerScreen();
			cin >> c;
			switch (c) {
			case 1:
				registerAdmin();
				runApp();
				break;
			case 2:
				registerEmployee();
				runApp();
				break;
			case 3:
				registerClient();
				runApp();
				break;
			case 4:
				runApp();
				break;
			default:
				invalid(c);
				break;
			}
		} while (c != 4);
	}

	static void runApp() {
		int c;
		do {
			bankName();
			welcome();
			cin >> c;
			switch (c) {
			case 1:
				loginOptions();
				break;
			case 2:
				registerOptions();
				break;
			case 3:
				quit();
				return;
				break;
			default:
				invalid(c);
				break;
			}
		} while (c != 3);
	}
};

