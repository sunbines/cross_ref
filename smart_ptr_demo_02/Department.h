#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include <memory>

// 前向声明
class Employee;

class Department {
public:
    Department(const std::string& name);

    void addEmployee(std::shared_ptr<Employee> emp);
    std::string getName() const;
    void listEmployees() const;

private:
    std::string name;
    std::vector<std::weak_ptr<Employee>> employees; // 避免循环引用
};

#endif // DEPARTMENT_H
