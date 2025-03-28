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
		for (int i = 0; i < employees.size(); i++) {
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
		for (int i = 0; i < admins.size(); i++) {
			cout << "Admin " << admins[i].getId() << endl;
			admins[i].display();
			cout << endl;
		}
	}

	static Client* getClient(int id) {
		vector<Client> clients = FilesHelper::getClients();
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].getId() == id) {
				Client* client = new Client(clients[i]);
				return client;
			}
		}
		return nullptr;
	}
	static Employee* getEmployee(int id) {
		vector<Employee> employees = FilesHelper::getEmployees();
		for (int i = 0; i < employees.size(); i++)
		{
			if (employees[i].getId() == id) {
				Employee* employee = new Employee(employees[i]);
				return employee;
			}
		}
		return nullptr;
	}
    static Admin* getAdmin(int id) {
        vector<Admin> admins = FilesHelper::getAdmins();
        for (int i = 0; i < admins.size(); i++) {
            if (admins[i].getId() == id) {
                Admin* admin = new Admin(admins[i]);
                return admin;
            }
        }
        return nullptr;
    }

	static void updatePassword(Person* person) {
		if (!person) {
			cout << "Error: Null person reference.\n";
			return;
		}
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
        vector<Client> clients = FilesHelper::getClients();
        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == clientId) {
                clients[i].setPassword(newPassword);
                break;
            }
        }
        ofstream file("ClientData.txt", ios::trunc);
        for (int i = 0; i < clients.size(); i++) {
            file << clients[i].toString() << endl;
        }
        file.close();
    }
    static void updateEmployeePassword(int employeeId, string newPassword) {
		vector<Employee> employees = FilesHelper::getEmployees();
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i].getId() == employeeId) {
				employees[i].setPassword(newPassword);
				break;
			}
		}
		ofstream file("EmployeeData.txt", ios::trunc);
		for (int i = 0; i < employees.size(); i++) {
			file << employees[i].toString() << endl;
		}
		file.close();
    }
    static void updateAdminPassword(int adminId, string newPassword) {
        vector<Admin> admins = FilesHelper::getAdmins();
        for (int i = 0; i < admins.size(); i++) {
			if (admins[i].getId() == adminId) {
                admins[i].setPassword(newPassword);
                break;
            }
        }
        ofstream file("AdminData.txt", ios::trunc);
        for (int i = 0; i < admins.size(); i++) {
            file << admins[i].toString() << endl;
        }
        file.close();
    }

	static void updatePerson(Person* person) {
		if (!person) {
			cout << "Error: Null person reference.\n";
			return;
		}
		if (Client* client = dynamic_cast<Client*>(person)) {
			updateClient(client->getId(), client->getName(), client->getPassword(), client->getBalance());
		}
		else if (Admin* admin = dynamic_cast<Admin*>(person)) {
			updateAdmin(admin->getId(), admin->getName(), admin->getPassword());
		}
		else if (Employee* employee = dynamic_cast<Employee*>(person)) {
			updateEmployee(employee->getId(), employee->getName(), employee->getPassword(), employee->getSalary());
		}
	}

	static void updateClient(int clientId, string newName, string newPassword, double newBalance) {
		vector<Client> clients = FilesHelper::getClients();
		for (int i = 0; i < clients.size(); i++) {
			if (clients[i].getId() == clientId) {
				clients[i].setName(newName);
				clients[i].setPassword(newPassword);
				clients[i].setBalance(newBalance);
				break;
			}
		}
		ofstream file("ClientData.txt", ios::trunc);
		for (int i = 0; i < clients.size(); i++) {
			file << clients[i].toString() << endl;
		}
		file.close();
	}
	static void updateEmployee(int employeeId, string newName, string newPassword, double newSalary) {
		vector<Employee> employees = FilesHelper::getEmployees();
		for (int i = 0; i < employees.size(); i++) {
			if (employees[i].getId() == employeeId) {
				employees[i].setName(newName);
				employees[i].setPassword(newPassword);
				employees[i].setSalary(newSalary);
				break;
			}
		}
		ofstream file("EmployeeData.txt", ios::trunc);
		for (int i = 0; i < employees.size(); i++) {
			file << employees[i].toString() << endl;
		}
		file.close();
	}
	static void updateAdmin(int adminId, string newName, string newPassword) {
		vector<Admin> admins = FilesHelper::getAdmins();
		for (int i = 0; i < admins.size(); i++) {
			if (admins[i].getId() == adminId) {
				admins[i].setName(newName);
				admins[i].setPassword(newPassword);
				break;
			}
		}
		ofstream file("AdminData.txt", ios::trunc);
		for (int i = 0; i < admins.size(); i++) {
			file << admins[i].toString() << endl;
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

