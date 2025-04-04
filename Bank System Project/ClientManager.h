#pragma once
#include "FileManager.h"

class ClientManager
{
public:
	static void printClientMenu() {
		cout << "Please select an option from the following:" << endl;
		cout << "1. View Account" << endl;
		cout << "2. Deposit" << endl;
		cout << "3. Withdraw" << endl;
		cout << "4. Transfer" << endl;
		cout << "5. Change Password" << endl;
		cout << "6. Logout" << endl;
	}

	static void deposit(Client* client) {
		cout << "Enter the amount you want to deposit: ";
		double amount;
		cin >> amount;
		if (client->deposit(amount))
		{
			FileManager::depositToClient(client->getId(), amount);
			cout << "Amount deposited successfully" << "\n";
		}
		else {
			cout << "Invalid amount" << "\n";

		}
	}

	static void withdraw(Client* client) {
		cout << "Enter the amount you want to withdraw: ";
		double amount;
		cin >> amount;
		if (client->withdraw(amount))
		{
			FileManager::withdrawFromClient(client->getId(), amount);
			cout << "Amount withdrawn successfully" << "\n";
		}
		else {
			cout << "Invalid amount" << "\n";
		}
	}

	static void transfer(Client* client) {
		cout << "Enter the id of the recipient: ";
		int id;
		cin >> id;
		cout << "Enter the amount you want to transfer: ";
		double num;
		cin >> num;
		Client* recipient = FileManager::getClient(id);
		if (recipient != nullptr && client->transferTo(num, recipient))
		{
			FileManager::transferToClient(client->getId(), num, recipient);
			cout << "Amount transferred successfully" << "\n";
		}
		else {
			cout << "Invalid amount or recipient" << "\n";
		}
	}

	static void updatePassword(Person* person) {
		string password;
		cout << "Enter new password: ";
		cin >> password;
		person->setPassword(password);
		FileManager::updatePassword(person);
	}

	static Client* login(int id, string password) {
		Client* client = FileManager::getClient(id);
		if (client != nullptr && client->login(id, password)) {
			return client;
		}
		else {
			cout << "Error: in password or id" << "\n";
			return nullptr;
		}
	}

	static void Register(Client* client) {
		if (client != nullptr) {
			FileManager::addClient(*client);
			cout << "Client registered successfully" << endl;
		}
		else {
			cout << "Error: Client not registered" << endl;
		}
	}

	static bool clientOptions(Client* client) {
		int c;
		do {
			printClientMenu();
			cin >> c;
			switch (c) {
			case 1:
				client->display();
				break;
			case 2:
				deposit(client);
				break;
			case 3:
				withdraw(client);
				break;
			case 4:
				transfer(client);
				break;
			case 5:
				updatePassword(client);
				break;
			case 6:
				return false;
			default:
				cout << "Invalid option: " << c << endl;
				break;
			}
		} while (true);
		return true;
	}
};

