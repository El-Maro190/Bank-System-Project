#include "Admin.h"
#include "FileManager.h"

void Admin::addEmployee(Employee employee) {
	FileManager::addEmployee(employee);
	cout << "Employee added successfully" << endl;
}

Employee* Admin::searchEmployee(int id) {
	return FileManager::getEmployee(id);
}

void Admin::listEmployees() {
	FileManager::getAllEmployees();
}

void Admin::editEmployee(int id, string name, string password, double salary) {
	Employee* employee = searchEmployee(id);
	if (!employee) {
		cout << "Employee not found.\n";
		return;
	}
	bool isValid = true;
	if (Validation::isValidationName(name) && isValid) {
		employee->setName(name);
	}
	else {
		cout << "Invalid name. Must be alphabetic and 5-20 characters.\n";
		isValid = false;
	}
	if (Validation::isValidationPassword(password) && isValid) {
		employee->setPassword(password);
	}
	else {
		cout << "Invalid password. Must be 8-20 characters.\n";
		isValid = false;
	}
	if (Validation::isValidationSalary(salary) && isValid) {
		employee->setSalary(salary);
	}
	else {
		cout << "Invalid salary. Must be at least 1500.\n";
		isValid = false;
	}
	if (isValid) {
		FileManager::updatePerson(employee);
		cout << "Employee data has been successfully modified" << "\n";
	}
	else {
		cout << "Employee data has not been modified" << "\n";
	}
}