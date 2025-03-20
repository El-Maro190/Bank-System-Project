#include "Admin.h"
#include "FileManager.h"

void Admin::addEmployee(Employee employee) {
	FileManager::addEmployee(employee);
	cout << "Employee added successfully" << endl;
}

Employee* Admin::searchEmployee(int id) {
	vector <Employee> employees = FilesHelper::getEmployees();
	for (size_t i = 0; i < employees.size(); i++) {
		if (employees[i].getId() == id) {
			return new Employee(employees[i]);
		}
	}
	return nullptr;
}

void Admin::listEmployees() {
	FileManager::getAllEmployees();
}

void Admin::editEmployee(int id, string name, string password, double salary) {
	Employee* employee = searchEmployee(id);
	if (employee) {
		employee->setName(name);
		employee->setPassword(password);
		employee->setSalary(salary);
		cout << "Employee data has been successfully modified" << "\n";
	}
	else {
		cout << "Employee not found" << "\n";
		return;
	}
}