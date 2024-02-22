#include "Employee.h"

Employee::Employee() {
    name = "default";
    lastName = "default";
    age = 18;
    workHours = 0;
    std::cout << "Employee created" << std::endl;
}

Employee::~Employee() {
    std::cout << "Employee deleted" << std::endl;
}

std::string Employee::GetName() {
    return name;
}

std::string Employee::GetLastName() {
    return lastName;
}

int Employee::GetAge() {
    return age;
}

int Employee::GetWorkHours() {
    return workHours;
}


void Employee::SetName(std::string new_name) {
    if (new_name == "") {
        std::cout << "Employee's name can't be empty" << std::endl;
    } else {
        name = new_name;
    }
}
void Employee::SetLastName(std::string new_lastName) {
    if (new_lastName == "") {
        std::cout << "Employee's last name can't be empty" << std::endl;
    } else {
        lastName = new_lastName;
    }
}
void Employee::SetAge(int new_age) {
    if (new_age < 18) {
        std::cout << "Age can't be less than 18" << std::endl;
    } else {
        age = new_age;
    }
}

void Employee::SetWorkHours(int new_workHours) {
    if (new_workHours < 0) {
        std::cout << "Work hours can't be less than 0" << std::endl;
    } else {
        workHours = new_workHours;
    }
}

int Employee::CalculateSalary() {
    return workHours * 500;
}


void Employee::Print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Work hours this month: " << workHours << std::endl;
    std::cout << "Salary: " << CalculateSalary() << std::endl;
}

void Employee::Fill() {
    std::string user_input;
	int user_int;

	std::cout << "Employee's name: ";
	getline(std::cin, user_input);

    while (user_input == "") {
        std::cout << "Employee's name can't be empty" << std::endl;
        getline(std::cin, user_input);
    }

	SetName(user_input);

    std::cout << "Employee's last name: ";
	getline(std::cin, user_input);

    while (user_input == "") {
        std::cout << "Employee's last name can't be empty" << std::endl;
        getline(std::cin, user_input);
    }

	SetLastName(user_input);

    std::cout << "Employee's age: ";
	getline(std::cin, user_input);

    while (user_input == "") {
        std::cout << "Can't be empty" << std::endl;
        getline(std::cin, user_input);
    }

    user_int = std::stoi(user_input);
    while (user_int < 18) {
        std::cout << "Age can't be less than 18" << std::endl;
        getline(std::cin, user_input);
        if (user_input != "") {
            user_int = std::stoi(user_input);
        }
    }

	SetAge(user_int);

    std::cout << "Employee's work hours this month: ";
	getline(std::cin, user_input);

    while (user_input == "") {
        std::cout << "Can't be empty" << std::endl;
        getline(std::cin, user_input);
    }

    user_int = std::stoi(user_input);
    while (user_int < 0) {
        std::cout << "Work hours can't be less than 0" << std::endl;
        getline(std::cin, user_input);
        if (user_input != "") {
            user_int = std::stoi(user_input);
        }
    }

	SetWorkHours(user_int);
}

void Employee::Load(std::vector<std::string> tokens) {
	int i = 0;

    SetName(tokens[i]);
    i++;
    SetLastName(tokens[i]);
    i++;
    SetAge(std::stoi(tokens[i]));
    i++;
    SetWorkHours(std::stoi(tokens[i]));
    i++;
}

std::string Employee::Convert() {
    std::string result = "";
    result += "<Employee>\n";
    result += name + '\n';
    result += lastName + '\n';
    result += std::to_string(age) + '\n';
    result += std::to_string(workHours) + '\n';
    result += "</Employee>\n";
    return result;
}


void Employee::Edit() {
	std::string user_input;
	int user_int;
	while (1) {
		std::cout << "Edit options" << std::endl
			<< "1 - Name" << std::endl
			<< "2 - Last name" << std::endl
			<< "3 - Age" << std::endl
			<< "4 - Work hours" << std::endl
			<< "0 - Back" << std::endl;
		getline(std::cin, user_input);
		user_int = std::stoi(user_input);;
		switch (user_int) {
		case 1:
			getline(std::cin, user_input);
			SetName(user_input);
			break;
		case 2:
			getline(std::cin, user_input);
			SetLastName(user_input);
			break;
		case 3:
			getline(std::cin, user_input);
            if (user_input == "") {
                std::cout << "Can't be empty" << std::endl;
            } else {
                user_int = std::stoi(user_input);
			    SetAge(user_int);
            }
			break;
		case 4:
			getline(std::cin, user_input);
            if (user_input == "") {
                std::cout << "Can't be empty" << std::endl;
            } else {
			    user_int = std::stoi(user_input);
			    SetWorkHours(user_int);
            }
			break;
		case 0:
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}
}