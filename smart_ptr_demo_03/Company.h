#ifndef COMPANY_H
#define COMPANY_H

#include <memory>
#include <string>
#include <vector>

class Person;  // 前向声明

class Company {
public:
    Company(const std::string& name);
    ~Company();
    
    void addEmployee(std::shared_ptr<Person> person);
    void showEmployees() const;
    std::string getName() const { return name_; }
    
private:
    std::string name_;
    std::vector<std::shared_ptr<Person>> employees_;  // 公司拥有员工
};

#endif  // COMPANY_H