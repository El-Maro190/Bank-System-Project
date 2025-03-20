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
		client->deposit(amount);
	}

	static void withdraw(Client* client) {
		cout << "Enter the amount you want to withdraw: ";
		double amount;
		cin >> amount;
		client->withdraw(amount);
	}

	static void transfer(Client* client) {
		cout << "Enter the amount you want to transfer: ";
		double num;
		cin >> num;
		cout << "Enter the id of the recipient: ";
		int id;
		cin >> id;
		Client* recipient = FileManager::getClient(id);
		client->transferTo(num, *recipient);
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

	static bool clientOptions() {
		int c;
		Client* client = nullptr;
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

