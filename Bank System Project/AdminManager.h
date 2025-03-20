#pragma once
#include "FileManager.h"
#include "EmployeeManager.h"

class AdminManager
{
public:
	static void printAdminMenu() {
		cout << "Please select an option from the following:" << endl;
		cout << "1. View Account" << endl;
		cout << "2. Add Client" << endl;
		cout << "3. List All Clients" << endl;
		cout << "4. Search For Client" << endl;
		cout << "5. Edit Client Info" << endl;
		cout << "6. Add Employee" << endl;
		cout << "7. List All Employees" << endl;
		cout << "8. Search For Employee" << endl;
		cout << "9. Edit Employee Info" << endl;
		cout << "10. Change Password" << endl;
		cout << "11. Logout" << endl;
	}

	static void newEmployee(Admin* admin) {
		int id;
		string name;
		string password;
		double salary;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter password: ";
		cin >> password;
		cout << "Enter salary: ";
		cin >> salary;
		Employee employee(id, name, password, salary);
		admin->addEmployee(employee);
	}

	static void listAllEmployees(Admin* admin) {
		admin->listEmployees();
	}

	static void searchForEmployee(Admin* admin) {
		int id;
		cout << "Enter the id of the employee: ";
		cin >> id;
		admin->searchEmployee(id);
	}

	static void editEmployeeInfo(Admin* admin) {
		int id;
		string name;
		string password;
		double salary;
		cout << "Enter the id of the employee: ";
		cin >> id;
		cout << "Enter the new name: ";
		cin >> name;
		cout << "Enter the new password: ";
		cin >> password;
		cout << "Enter the new salary: ";
		cin >> salary;
		admin->editEmployee(id, name, password, salary);
	}

	static void updatePassword(Person* person) {
		string password;
		cout << "Enter new password: ";
		cin >> password;
		person->setPassword(password);
		FileManager::updatePassword(person);
	}

	static Admin* login(int id, string password) {
		Admin* admin = FileManager::getAdmin(id);
		if (admin != nullptr && admin->login(id, password)) {
			return admin;
		}
		else {
			cout << "Error: in password or id" << "\n";
			return nullptr;
		}
	}

	static bool AdminOptions() {
		int c;
		Admin* admin = nullptr;
		do {
			printAdminMenu();
			cin >> c;
			switch (c) {
			case 1:
				admin->display();
				break;
			case 2:
				EmployeeManager::newClient(admin);
				break;
			case 3:
				EmployeeManager::listAllClients(admin);
				break;
			case 4:
				EmployeeManager::searchForClient(admin);
				break;
			case 5:
				EmployeeManager::editClientInfo(admin);
				break;
			case 6:
				newEmployee(admin);
				break;
			case 7:
				listAllEmployees(admin);
				break;
			case 8:
				searchForEmployee(admin);
				break;
			case 9:
				editEmployeeInfo(admin);
				break;
			case 10:
				updatePassword(admin);
				break;
			case 11:
				return false;
			default:
				cout << "Invalid option: " << c << endl;
				break;
			}
		} while (c != 3);
		return true;
	}
};

