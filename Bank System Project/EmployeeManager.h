#pragma once
#include "FileManager.h"

class EmployeeManager
{
public:
	static void printEmployeeMenu() {
		cout << "Please select an option from the following:" << endl;
		cout << "1. View Account" << endl;
		cout << "2. Add Client" << endl;
		cout << "3. List All Clients" << endl;
		cout << "4. Search For Client" << endl;
		cout << "5. Edit Client Info" << endl;
		cout << "6. Change Password" << endl;
		cout << "7. Logout" << endl;
	}

	static void newClient(Employee* employee) {
		int id;
		string name;
		string password;
		double balance;
		cout << "Enter id: ";
		cin >> id;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter password: ";
		cin >> password;
		cout << "Enter balance: ";
		cin >> balance;
		Client client(id, name, password, balance);
		employee->addClient(client);
	}

	static void listAllClients(Employee* employee) {
		employee->listClients();
	}

	static void searchForClient(Employee* employee) {
		int id;
		cout << "Enter the id of the client: ";
		cin >> id;
		employee->searchClient(id);
	}

	static void editClientInfo(Employee* employee) {
		int id;
		string name;
		string password;
		double balance;
		cout << "Enter the id of the client: ";
		cin >> id;
		cout << "Enter the new name: ";
		cin >> name;
		cout << "Enter the new password: ";
		cin >> password;
		cout << "Enter the new balance: ";
		cin >> balance;
		employee->editClient(id, name, password, balance);
	}

	static void updatePassword(Person* person) {
		string password;
		cout << "Enter new password: ";
		cin >> password;
		person->setPassword(password);
		FileManager::updatePassword(person);
	}

	static Employee* login(int id, string password) {
		Employee* employee = FileManager::getEmployee(id);
		if (employee != nullptr && employee->login(id, password)) {
			return employee;
		}
		else {
			cout << "Error: in password or id" << "\n";
			return nullptr;
		}
	}

	static bool employeeOptions() {
		int c;
		Employee* employee = nullptr;
		do {
			printEmployeeMenu();
			cin >> c;
			switch (c) {
			case 1:
				employee->display();
				break;
			case 2:
				newClient(employee);
				break;
			case 3:
				listAllClients(employee);
				break;
			case 4:
				searchForClient(employee);
				break;
			case 5:
				editClientInfo(employee);
				break;
			case 6:
				updatePassword(employee);
				break;
			case 7:
				return false;
			default:
				cout << "Invalid option: " << c << endl;
				break;
			}
		} while (true);
		return true;
	}
};
