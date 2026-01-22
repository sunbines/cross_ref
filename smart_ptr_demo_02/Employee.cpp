#include "Employee.h"
#include "Department.h"
#include <iostream>

Employee::Employee(const std::string& name) : name(name) {}

void Employee::setDepartment(std::shared_ptr<Department> dept) {
    department = dept;
}

std::string Employee::getName() const {
    return name;
}

void Employee::printDepartmentName() const {
    if (auto dept = department.lock()) {
        std::cout << "Employee " << name << " is in department " << dept->getName() << std::endl;
    } else {
        std::cout << "Employee " << name << " has no department." << std::endl;
    }
}
