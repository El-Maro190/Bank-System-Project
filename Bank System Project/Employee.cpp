#include "Employee.h"
#include "FileManager.h"

void Employee::addClient(Client client) {
	FileManager::addClient(client);
	cout << "Client added successfully" << endl;
}

Client* Employee::searchClient(int id) {
	vector <Client> clients = FilesHelper::getClients();
	for (size_t i = 0; i < clients.size(); i++) {
		if (clients[i].getId() == id) {
			return new Client(clients[i]);
		}
	}
	return nullptr;
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
