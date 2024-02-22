#include "Manager.h"

Manager::Manager() {
    std::cout << "Manager created" << std::endl;
}

Manager::~Manager() { // деструктор
    projects.clear();
    std::cout << "Manager deleted" << std::endl;
}

std::vector<std::string> Manager::GetProjects() {
    return projects;
}

void Manager::AddProject(std::string new_project) {
    projects.push_back(new_project);
}

int Manager::CalculateSalary() {
    return workHours * 600;
}

void Manager::Print() {
    Employee::Print();
    if(projects.empty())
		std::cout << "No projects" << std::endl;
	else {
		std::cout << "projects:" << std::endl;
		for (int i = 0; i < projects.size(); i++) {
			std::cout << " " << projects[i] << std::endl;
		}
	}
}

void Manager::Fill() {
    std::string user_input;
	int user_int;
    Employee::Fill();

    std::cout << "Manager's projects (pass empty string to stop): ";
    while (true) {
        getline(std::cin, user_input);
        if (user_input != "") {
            AddProject(user_input);
        } else {
            break;
        }
    }
}

void Manager::Load(std::vector<std::string> tokens) {
	int user_int;
	int i = 0;

    SetName(tokens[i]);
    i++;
    SetLastName(tokens[i]);
    i++;
    SetAge(std::stoi(tokens[i]));
    i++;
    SetWorkHours(std::stoi(tokens[i]));
    i += 2;
    while (tokens[i] != "</Projects>" && i < tokens.size()) {
        AddProject(tokens[i]);
        i++;
    }
}

std::string Manager::Convert() {
    std::string result = "";
    result += "<Manager>\n";
    result += name + '\n';
    result += lastName + '\n';
    result += std::to_string(age) + '\n';
    result += std::to_string(workHours) + '\n';
    result += "<Projects>\n";
    for (int i = 0; i < projects.size(); i++) {
        result += projects[i] + '\n';
    }
    result += "</Projects>\n";
    result += "</Manager>\n";
    return result;
}

void Manager::Edit() {
	std::string user_input;
	int user_int;
	while (1) {
		std::cout << "Edit options" << std::endl
			<< "1 - Name" << std::endl
			<< "2 - Last name" << std::endl
			<< "3 - Age" << std::endl
			<< "4 - Work hours" << std::endl
            << "5 - Add projects" << std::endl
            << "6 - Clear projects" << std::endl
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
        case 5:
            std::cout << "New project: ";
            getline(std::cin, user_input);
            AddProject(user_input);
            break;
        case 6:
            projects.clear();
            break;
		case 0:
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}
}