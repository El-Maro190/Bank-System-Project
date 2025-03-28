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
		cin.ignore();
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter password: ";
		getline(cin, password);
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
        Client* client = employee->searchClient(id);
        if (client != nullptr) {
            client->display();
        } else {
            cout << "Client not found" << endl;
        }
    }

	static void editClientInfo(Employee* employee) {
		int id;
		string name;
		string password;
		double balance;
		cout << "Enter the id of the client: ";
		cin >> id;
		cin.ignore();
		cout << "Enter the new name: ";
		getline(cin, name);
		cout << "Enter the new password: ";
		getline(cin, password);
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

	static void Register(Employee* employee) {
		if (employee != nullptr) {
			FileManager::addEmployee(*employee);
			cout << "Employee registered successfully" << endl;
		}
		else {
			cout << "Error: Employee not registered" << endl;
		}
	}

	static bool employeeOptions(Employee* employee) {
		int c;
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
