#ifndef PERSON_H
#define PERSON_H

#include <memory>
#include <string>

class Company;  // 前向声明

class Person {
public:
    Person(const std::string& name, int age);
    ~Person();
    
    void setCompany(std::shared_ptr<Company> comp);
    void showInfo() const;
    std::string getName() const { return name_; }
    int getAge() const { return age_; }
    
private:
    std::string name_;
    int age_;
    std::weak_ptr<Company> company_;  // 使用 weak_ptr 避免循环引用
};

#endif  // PERSON_H