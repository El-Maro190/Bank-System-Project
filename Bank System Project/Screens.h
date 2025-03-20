#pragma once
#include "FileManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

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
		cout << "Please select an option from the following:" << endl;
		cout << "1. Admin" << endl;
		cout << "2. Employee" << endl;
		cout << "3. Client" << endl;
		cout << "4. Back" << endl;
	}

	static void registerScreen() {
		cout << "Please select an option from the following:" << endl;
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

	static void exit() {
		cout << "Thank you for using Summit Financial Bank." << endl;
	}

	static void loginOptions() {
		int c;
		do
		{
			loginScreen();
			cin >> c;
			switch (c) {
			//case 1:
			//	AdminManager::login();
			//	break;
			//case 2:
			//	EmployeeManager::login();
			//	break;
			//case 3:
			//	ClientManager::login();
			//	break;
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
			//case 1:
			//	AdminManager::registerAdmin();
			//	break;
			//case 2:
			//	EmployeeManager::registerEmployee();
			//	break;
			//case 3:
			//	ClientManager::registerClient();
			//	break;
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
				exit();
				break;
			default:
				invalid(c);
				break;
			}
		} while (c != 3);
	}
};

