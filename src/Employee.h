#pragma once
#include <string>
#include <iostream>
#include <vector>

class Employee {
    friend class Menu;
    protected:
        std::string name;
        std::string lastName;
        int age;
        int workHours;

        virtual void Edit();
    public:
        // constructors
        Employee();
        ~Employee();
        // getters
        std::string GetName();
        std::string GetLastName();
        int GetAge();
        int GetWorkHours();
        
        // setters
        void SetName(std::string new_name);
        void SetLastName(std::string new_lastName);
        void SetAge(int new_age);
        void SetWorkHours(int new_workHours);

        virtual int CalculateSalary();

        virtual void Print();
        virtual void Fill();
        virtual void Load(std::vector<std::string> tokens);
        virtual std::string Convert();
        
};