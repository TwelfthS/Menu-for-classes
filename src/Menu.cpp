#include"Menu.h"

Menu::Menu() {
	Load();
}

Menu::~Menu() {
	std::cout << "Exit";
}

void Menu::Print() {
	std::cout << "List of employees: " << std::endl;
	for (int i = 0; i < Employees.size(); i++) {
		std::cout << i + 1 << ". ";
		Employees[i]->Print();
		std::cout << std::endl;
	}
}

void Menu::Add_employee() {
	Employee* new_employee = new Employee();
	new_employee->Fill();
	Employees.push_back(new_employee);
}

void Menu::Add_manager() {
	Manager* new_manager = new Manager();
	new_manager->Fill();
	Employees.push_back(new_manager);
};
void Menu::Add_developer() {
	Developer* new_developer = new Developer();
	new_developer->Fill();
	Employees.push_back(new_developer);
};
void Menu::AddingMenu() {
	std::string user_input;
	int user_int;
	while (1) {
		std::cout << "Type of Employee" << std::endl
			<< "1 - Employee" << std::endl
			<< "2 - Manager" << std::endl
			<< "3 - Developer" << std::endl
			<< "0 - Back to edit menu" << std::endl;
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);
		switch (user_int) {
		case 1:
			Add_employee();
			break;
		case 2:
			Add_manager();
			break;
		case 3:
			Add_developer();
			break;
		case 0:
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}
};

void Menu::Load() {
	std::string line;
	std::vector<std::string> tokens;
	std::fstream f;
	try {
		f.open("employees.txt");
	}
	catch (const std::exception& error) {
		std::cout << "File didn't open " << error.what();
		return;
	}
	while (getline(f, line)) {
		if (line == "<Employee>") {
			while (getline(f, line)) {
				if (line == "</Employee>") break;
				std::string s = line;
				tokens.push_back(s);
			}
			Employee* new_emp = new Employee();
			new_emp->Load(tokens);
			Employees.push_back(new_emp);
			tokens.clear();
		}

		else if (line == "<Manager>") {
			while (getline(f, line)) {
				if (line == "</Manager>") break;
				std::string s = line;
				tokens.push_back(s);
			}
			Manager* new_man = new Manager();
			new_man->Load(tokens);
			Employees.push_back(new_man);
			tokens.clear();
		}

		else if (line == "<Developer>") {
			while (getline(f, line)) {
				if (line == "</Developer>") break;
				std::string s = line;
				tokens.push_back(s);
			}
			Developer* new_dev = new Developer();
			new_dev->Load(tokens);
			Employees.push_back(new_dev);
			tokens.clear();
		}
	}
}

void Menu::Save() { // сохранение в файл
	std::string line;
	std::fstream f;
	try {
		f.open("employees.txt", std::ios::out | std::ios::trunc);
	}
	catch (const std::exception& error) {
		std::cout << "File didn't open " << error.what();
		return;
	}
	for (int i = 0; i < Employees.size(); i++) {
		f << Employees[i]->Convert();
	}
	std::cout << "Employees saved\n";
}

void Menu::Edit() {
	std::string user_input;
	int user_int;
	while (1) {
		std::cout << "Edit menu" << std::endl
			<< "1 - Add Employee" << std::endl
			<< "2 - Edit Employee" << std::endl
			<< "3 - Delete Employee" << std::endl
			<< "0 - Back to main menu" << std::endl;
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);
		switch (user_int) {
		case 1:
			AddingMenu();
			break;
		case 2:
			EditEmployee();
			break;
		case 3:
			DeleteEmployee();
			break;
		case 0:
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}
}

void Menu::EditEmployee() {
	Print();
	std::cout << "Which Employee do you want to edit? (0 - back to menu): ";
	std::string user_input;
	int user_int;
	while (1) {
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);
		if (user_int == 0) return;
		user_int--;

		if (user_int >= 0 && user_int < Employees.size()) {
			Employees[user_int]->Edit();
			break;
		}
		std::cout << "Incorrect input";
	}

}

void Menu::DeleteEmployee() {
	Print();
	std::cout << "Which Employee do you want to delete? (0 - back to menu): ";
	std::string user_input;
	int user_int;
	while (1) {
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);
		if (user_int == 0) return;
		user_int--;
		 
		if (user_int >= 0 && user_int < Employees.size()) {
			Employees.erase(Employees.begin() + user_int);
			break;
		}
		std::cout << "Incorrect input";
	}
}

void Menu::Sort() {

	std::string user_input;
	int user_int;
	while (1) {
		std::cout << "Sort Menu" << std::endl
			<< "1 - By name" << std::endl
			<< "2 - By age" << std::endl
			<< "3 - By salary" << std::endl
			<< "0 - Back to main menu" << std::endl;
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);
		switch (user_int) {
		case 1:
			SortName();
			break;
		case 2:
			SortAge();
			break;
		case 3:
			SortSalary();
		case 0:
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}
}

void Menu::SortName() {

	std::vector<Employee*> Sorted;
	if (Employees.empty()) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}

	Sorted.push_back(Employees[0]);
	int j = 0;
	for (int i = 1; i < Employees.size(); i++) {

		for (j = 0; j < Sorted.size(); j++) {

			if (Employees[i]->GetName() < Sorted[j]->GetName())
				break;
		}

		if (j >= Sorted.size())
			Sorted.push_back(Employees[i]);
		else
			Sorted.insert(Sorted.begin() + j, Employees[i]);
	}

	std::cout << "List of sorted Employees: " << std::endl;
	for (int i = 0; i < Sorted.size(); i++) {
		std::cout << i + 1 << ". ";
		Sorted[i]->Print();
		std::cout << std::endl;
	}
}

void Menu::SortAge() {

	std::vector<Employee*> Sorted;
	if (Employees.empty()) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}

	Sorted.push_back(Employees[0]);
	int j = 0;
	for (int i = 1; i < Employees.size(); i++) {
		
		for (j = 0; j < Sorted.size(); j++) {

			if (Employees[i]->GetAge() < Sorted[j]->GetAge())
				break;
		}

		if (j >= Sorted.size())
			Sorted.push_back(Employees[i]);
		else
			Sorted.insert(Sorted.begin() + j, Employees[i]);
	}

	std::cout << "List of sorted Employees: " << std::endl;
	for (int i = 0; i < Sorted.size(); i++) {
		std::cout << i + 1 << ". ";
		Sorted[i]->Print();
		std::cout << std::endl;
	}
}

void Menu::SortSalary() {

	std::vector<Employee*> Sorted;
	if (Employees.empty()) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}

	Sorted.push_back(Employees[0]);
	int j = 0;
	for (int i = 1; i < Employees.size(); i++) {
		
		for (j = 0; j < Sorted.size(); j++) {

			if (Employees[i]->CalculateSalary() < Sorted[j]->CalculateSalary())
				break;
		}

		if (j >= Sorted.size())
			Sorted.push_back(Employees[i]);
		else
			Sorted.insert(Sorted.begin() + j, Employees[i]);
	}

	std::cout << "List of sorted Employees: " << std::endl;
	for (int i = 0; i < Sorted.size(); i++) {
		std::cout << i + 1 << ". ";
		Sorted[i]->Print();
		std::cout << std::endl;
	}
}

void Menu::Filter() {

	std::string user_input;
	int user_int;
	while (1) {
		std::cout << "Filtr Menu" << std::endl
			<< "1 - By age" << std::endl
			<< "2 - By salary (less than)" << std::endl // те у кого зарплата меньше или равна заданной
			<< "3 - By salary (more than)" << std::endl // те у кого больше или равна
			<< "0 - Back to main menu" << std::endl;
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);
		switch (user_int) {
		case 1:
			FilterAge();
			break;
		case 2:
			FilterSalary(true);
			break;
		case 3:
			FilterSalary(false);
			break;
		case 0:
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}
}

void Menu::FilterAge() {

	std::string user_input;
	int cast_int;
	int i;

	std::vector<Employee*> Filtered;
	if (Employees.empty()) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}

	std::cout << "Input age: ";
	getline(std::cin, user_input);

	cast_int = std::stoi(user_input);

	if (cast_int < 18) {

		std::cout << "Error: age can't be less than 18" << std::endl;
	}

	else {
		for (i = 0; i < Employees.size(); i++) {
			if (Employees[i]->GetAge() <= cast_int)
				Filtered.push_back(Employees[i]);
		}
	}

	std::cout << "List of filtred Employees: " << std::endl;
	for (int i = 0; i < Filtered.size(); i++) {
		std::cout << i + 1 << ". ";
		Filtered[i]->Print();
		std::cout << std::endl;
	}
}

void Menu::FilterSalary(bool less_than) {

	std::string user_input;
	int cast_int;
	int i;

	std::vector<Employee*> Filtered;
	if (Employees.empty()) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}

	std::cout << "Input salary: ";
	getline(std::cin, user_input);

	cast_int = std::stoi(user_input);

	if (cast_int < 0) {

		std::cout << "Error: salary can't be less than 0" << std::endl;
	}

	else {
		for (i = 0; i < Employees.size(); i++) {
			if (less_than) {
				if (Employees[i]->CalculateSalary() <= cast_int) Filtered.push_back(Employees[i]);
			} else {
				if (Employees[i]->CalculateSalary() >= cast_int) Filtered.push_back(Employees[i]);
			}
		}
	}

	std::cout << "List of filtred Employees: " << std::endl;
	for (int i = 0; i < Filtered.size(); i++) {
		std::cout << i + 1 << ". ";
		Filtered[i]->Print();
		std::cout << std::endl;
	}
}


void Menu::MainMenu() {
	std::string user_input;
	int user_int;

	while (1) {
		std::cout << "Main menu" << std::endl
			<< "1 - Print all" << std::endl
			<< "2 - Sort" << std::endl
			<< "3 - Save" << std::endl
			<< "4 - Load" << std::endl
			<< "5 - Filter" << std::endl
			<< "6 - Edit" << std::endl
			<< "0 - Exit" << std::endl;
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);
		switch (user_int) {
		case 1: 
			Print();
			break;
		case 2:
			Sort();
			break;
		case 3:
			Save();
			break;
		case 4:
			Load();
			break;
		case 5:
			Filter();
			break;
		case 6:
			Edit();
			break;
		case 0: 
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}

	
};