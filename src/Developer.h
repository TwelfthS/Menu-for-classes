#pragma once

#include "Employee.h"

class Developer : public Employee {
    private:
        std::vector<std::string> skills;
        void Edit();
    public:
        Developer();
        ~Developer();

        std::vector<std::string> GetSkills();
        void AddSkill(std::string new_skill);

        int CalculateSalary();

        void Print();
        void Fill();
        void Load(std::vector<std::string> tokens);
        std::string Convert();
};