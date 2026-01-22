#include "Department.h"
#include "Employee.h"
#include <iostream>

Department::Department(const std::string& name) : name(name) {}

void Department::addEmployee(std::shared_ptr<Employee> emp) {
    employees.push_back(emp);
    emp->setDepartment(std::shared_ptr<Department>(this, [](Department*){})); // 创建一个弱引用指针避免循环
}

std::string Department::getName() const {
    return name;
}

void Department::listEmployees() const {
    std::cout << "Department " << name << " has employees:" << std::endl;
    for (const auto& wemp : employees) {
        if (auto emp = wemp.lock()) {
            std::cout << " - " << emp->getName() << std::endl;
        }
    }
}
