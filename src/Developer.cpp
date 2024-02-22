#include "Developer.h"

Developer::Developer() {
    std::cout << "Developer created" << std::endl;
}
Developer::~Developer() {
    skills.clear();
    std::cout << "Developer deleted" << std::endl;
}

std::vector<std::string> Developer::GetSkills() {
    return skills;
}

int Developer::CalculateSalary() {
    return workHours * 900;
}

void Developer::AddSkill(std::string new_skill) {
    skills.push_back(new_skill);
}


void Developer::Print() {
    Employee::Print();

    if(skills.empty())
		std::cout << "No skills" << std::endl;
	else {
		std::cout << "skills:" << std::endl;
		for (int i = 0; i < skills.size(); i++) {
			std::cout << " " << skills[i] << std::endl;
		}
	}
}

void Developer::Fill() {
    std::string user_input;
	int user_int;
    Employee::Fill();

    std::cout << "Developer's skills (pass empty string to stop): ";
    while (true) {
        getline(std::cin, user_input);
        if (user_input != "") {
            AddSkill(user_input);
        } else {
            break;
        }
    }
}

void Developer::Load(std::vector<std::string> tokens) {
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
    while (tokens[i] != "</Skills>" && i < tokens.size()) {
        AddSkill(tokens[i]);
        i++;
    }
}

std::string Developer::Convert() {
    std::string result = "";
    result += "<Developer>\n";
    result += name + '\n';
    result += lastName + '\n';
    result += std::to_string(age) + '\n';
    result += std::to_string(workHours) + '\n';
    result += "<Skills>\n";
    for (int i = 0; i < skills.size(); i++) {
        result += skills[i] + '\n';
    }
    result += "</Skills>\n";
    result += "</Developer>\n";
    return result;
}

void Developer::Edit() {
	std::string user_input;
	int user_int;
	while (1) {
		std::cout << "Edit options" << std::endl
			<< "1 - Name" << std::endl
			<< "2 - Last name" << std::endl
			<< "3 - Age" << std::endl
			<< "4 - Work hours" << std::endl
            << "5 - Add skills" << std::endl
            << "6 - Clear skills" << std::endl
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
            std::cout << "New skill: ";
            getline(std::cin, user_input);
            AddSkill(user_input);
            break;
        case 6:
            skills.clear();
            break;
		case 0:
			return;
		default:
			std::cout << "Incorrect input" << std::endl;
		}
	}
}