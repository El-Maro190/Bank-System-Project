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
		vector<Client> clients = FilesHelper::getClients();
		if (clients.empty()) {
			cout << "No clients found." << endl;
			return;
		}
		for (int i = 0; i < clients.size(); i++)
		{
			cout << "Client " << clients[i].getId() << endl;
			clients[i].display();
			cout << endl;
		}
	}
	static void getAllEmployees() {
		vector<Employee> employees = FilesHelper::getEmployees();
		if (employees.empty()) {
			cout << "No employees found." << endl;
			return;
		}
		for (int i = 0; i < employees.size(); i++)
		{
			cout << "Employee " << employees[i].getId() << endl;
			employees[i].display();
			cout << endl;
		}
	}
	static void getAllAdmins() {
		vector<Admin> admins = FilesHelper::getAdmins();
		if (admins.empty()) {
			cout << "No admins found." << endl;
			return;
		}
		for (int i = 0; i < admins.size(); i++)
		{
			cout << "Admin " << admins[i].getId() << endl;
			admins[i].display();
			cout << endl;
		}
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

