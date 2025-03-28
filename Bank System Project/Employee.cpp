#include "Employee.h"
#include "FileManager.h"

void Employee::addClient(Client client) {
	FileManager::addClient(client);
	cout << "Client added successfully" << endl;
}

Client* Employee::searchClient(int id) {
	return FileManager::getClient(id);
}

void Employee::listClients() {
	FileManager::getAllClients();
}

void Employee::editClient(int id, string name, string password, double balance) {
	Client* client = searchClient(id);
	if (!client) {
		cout << "Client not found.\n";
		return;
	}

	bool isValid = true;

	if (Validation::isValidationName(name) && isValid) {
		client->setName(name);
	}
	else {
		cout << "Invalid name. Must be alphabetic and 5-20 characters.\n";
		isValid = false;
	}
	if (Validation::isValidationPassword(password)&&isValid) {
		client->setPassword(password);
	}
	else {
		cout << "Invalid password. Must be 8-20 characters.\n";
		isValid = false;
	}
	if (Validation::isValidationbalance(balance)&&isValid) {
		client->setBalance(balance);
	}
	else {
		cout << "Invalid balance. Must be at least 1500.\n";
		isValid = false;
	}

	if (isValid) {
		FileManager::updatePerson(client);
		cout << "Client data has been successfully modified" << "\n";
	}
	else {
		cout << "Client data has not been modified" << "\n";
	}
}
