#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "FileManager.h"
#include "Screens.h"
#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include "Parser.h"
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"

using namespace std;

int main() {
	Screens::runApp();
}