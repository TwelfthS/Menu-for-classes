#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "Developer.h"
class Menu {
	private:
		std::vector<Employee*> Employees;
		void Print();
		void Add_employee();
		void Add_manager();
		void Add_developer();
		void AddingMenu();
		void Load();
		void Save();
		void Edit();
		void DeleteEmployee();
		void EditEmployee();
		void Sort();
		void SortName();
		void SortAge();
		void SortSalary();
		void Filter();
		void FilterAge();
		void FilterSalary(bool less_than);
	public:
		void MainMenu();
		Menu();
		~Menu();
};