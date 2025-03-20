#pragma once
#include "FilesHelper.h"
#include "DataSourceInterface.h"
class FileManager :DataSourceInterface
{
public:
	static void addClient(Client c) {
		FilesHelper::saveClient(c);
		FilesHelper::saveLast("ClientLastID.txt", c.getId());
	}
	static void addEmployee(Employee e) {
		FilesHelper::saveEmployee("EmployeeData.txt", "EmployeeLastID.txt", e);
		FilesHelper::saveLast("EmployeeLastID.txt", e.getId());
	}
	static void addAdmin(Admin a) {
		FilesHelper::saveEmployee("AdminData.txt", "AdminLastID.txt", a);
		FilesHelper::saveLast("AdminLastID.txt", a.getId());
	}

	static void getAllClients() {
		vector<Client>* clients = FilesHelper::getClients();
		if (clients->empty()) {
			cout << "No clients found." << endl;
			return;
		}
		for (int i = 0; i < clients->size(); i++)
		{
			cout << "Client " << clients->at(i).getId() << endl;
			clients->at(i).display();
			cout << endl;
		}
	}
	static void getAllEmployees() {
		vector<Employee>* employees = FilesHelper::getEmployees();
		if (employees->empty()) {
			cout << "No employees found." << endl;
			return;
		}
		for (int i = 0; i < employees->size(); i++) {
			cout << "Employee " << employees->at(i).getId() << endl;
			employees->at(i).display();
			cout << endl;
		}
	}
	static void getAllAdmins() {
		vector<Admin>* admins = FilesHelper::getAdmins();
		if (admins->empty()) {
			cout << "No admins found." << endl;
			return;
		}
		for (int i = 0; i < admins->size(); i++) {
			cout << "Admin " << admins->at(i).getId() << endl;
			admins->at(i).display();
			cout << endl;
		}
	}

	static Client* getClient(int id) {
		vector<Client>* clients = FilesHelper::getClients();
		for (int i = 0; i < clients->size(); i++) {
			if (clients->at(i).getId() == id) {
				return &clients->at(i);
			}
		}
		return nullptr;
	}
	static Employee* getEmployee(int id) {
		vector<Employee>* employees = FilesHelper::getEmployees();
		for (int i = 0; i < employees->size(); i++)
		{
			if (employees->at(i).getId() == id) {
				return &employees->at(i);
			}
		}
		return nullptr;
	}
	static Admin* getAdmin(int id) {
		vector<Admin>* admins = FilesHelper::getAdmins();
		for (int i = 0; i < admins->size(); i++) {
			if (admins->at(i).getId() == id) {
				return &admins->at(i);
			}
		}
		return nullptr;
	}

	static void updatePassword(Person* person) {
		if (Client* client = dynamic_cast<Client*>(person)) {
			updateClientPassword(client->getId(), client->getPassword());
		}
		else if (Admin* admin = dynamic_cast<Admin*>(person)) {
			updateAdminPassword(admin->getId(), admin->getPassword());
		}
		else if (Employee* employee = dynamic_cast<Employee*>(person)) {
			updateEmployeePassword(employee->getId(), employee->getPassword());
		}
	}

    static void updateClientPassword(int clientId, string newPassword) {
        vector<Client>* clients = FilesHelper::getClients();
        for (int i = 0; i < clients->size(); i++) {
            if (clients->at(i).getId() == clientId) {
                clients->at(i).setPassword(newPassword);
                break;
            }
        }
        ofstream file("ClientData.txt", ios::trunc);
        for (int i = 0; i < clients->size(); i++) {
            file << clients->at(i).toString() << endl;
        }
        file.close();
    }
    static void updateEmployeePassword(int employeeId, string newPassword) {
        vector<Employee>* employees = FilesHelper::getEmployees();
        for (int i = 0; i < employees->size(); i++) {
            if (employees->at(i).getId() == employeeId) {
                employees->at(i).setPassword(newPassword);
                break;
            }
        }
        ofstream file("EmployeeData.txt", ios::trunc);
        for (int i = 0; i < employees->size(); i++) {
            file << employees->at(i).toString() << endl;
        }
        file.close();
    }
    static void updateAdminPassword(int adminId, string newPassword) {
        vector<Admin>* admins = FilesHelper::getAdmins();
        for (int i = 0; i < admins->size(); i++) {
            if (admins->at(i).getId() == adminId) {
                admins->at(i).setPassword(newPassword);
                break;
            }
        }
        ofstream file("AdminData.txt", ios::trunc);
        for (int i = 0; i < admins->size(); i++) {
            file << admins->at(i).toString() << endl;
        }
        file.close();
    }

	static void removeAllClients() {
		FilesHelper::clearFile("ClientData.txt", "ClientLastID.txt");
	}
	static void removeAllEmployees() {
		FilesHelper::clearFile("EmployeeData.txt", "EmployeeLastID.txt");
	}
	static void removeAllAdmins() {
		FilesHelper::clearFile("AdminData.txt", "AdminLastID.txt");
	}
};

