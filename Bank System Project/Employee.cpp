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
	if (client) {
		client->setName(name);
		client->setPassword(password);
		client->setBalance(balance);
		cout << "Client data has been successfully modified" << "\n";
	}
	else {
		cout << "Client not found" << "\n";
		return;
	}
}
