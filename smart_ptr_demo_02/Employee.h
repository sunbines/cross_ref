#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <memory>

// 前向声明
class Department;

class Employee {
public:
    Employee(const std::string& name);

    void setDepartment(std::shared_ptr<Department> dept);
    std::string getName() const;
    void printDepartmentName() const;

private:
    std::string name;
    std::weak_ptr<Department> department; // 避免循环引用
};

#endif // EMPLOYEE_H
