#pragma once
#include <vector>
#include "Employee.h"

class Manager : public Employee {
    private:
        std::vector<std::string> projects;
        void Edit();
    public:
        Manager();
        ~Manager();

        std::vector<std::string> GetProjects();

        void AddProject(std::string new_project);

        int CalculateSalary();

        void Print();
        void Fill();
        void Load(std::vector<std::string> tokens);
        std::string Convert();
};