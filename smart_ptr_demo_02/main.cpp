#include "Employee.h"
#include "Department.h"
#include <memory>

int main() {
    auto dept = std::make_shared<Department>("Engineering");
    auto emp1 = std::make_shared<Employee>("Alice");
    auto emp2 = std::make_shared<Employee>("Bob");

    dept->addEmployee(emp1);
    dept->addEmployee(emp2);

    emp1->printDepartmentName();
    emp2->printDepartmentName();

    dept->listEmployees();

    return 0;
}
