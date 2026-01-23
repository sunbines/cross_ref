#include "Company.h"
#include "Person.h"
#include <iostream>

Company::Company(const std::string& name) : name_(name) {
    std::cout << "Company " << name_ << " 被创建" << std::endl;
}

Company::~Company() {
    std::cout << "Company " << name_ << " 被销毁" << std::endl;
}

void Company::addEmployee(std::shared_ptr<Person> person) {
    employees_.push_back(person);
    person->setCompany(shared_from_this());  // 需要继承 enable_shared_from_this
}

void Company::showEmployees() const {
    std::cout << "\n" << name_ << " 的员工列表:" << std::endl;
    for (const auto& emp : employees_) {
        std::cout << "  - " << emp->getName() 
                  << " (年龄: " << emp->getAge() << ")" << std::endl;
    }
}