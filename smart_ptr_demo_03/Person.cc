#include "Person.h"
#include "Company.h"
#include <iostream>

Person::Person(const std::string& name, int age) 
    : name_(name), age_(age) {
    std::cout << "Person " << name_ << " 被创建" << std::endl;
}

Person::~Person() {
    std::cout << "Person " << name_ << " 被销毁" << std::endl;
}

void Person::setCompany(std::shared_ptr<Company> comp) {
    company_ = comp;  // weak_ptr 赋值，不增加引用计数
}

void Person::showInfo() const {
    std::cout << "姓名: " << name_ << ", 年龄: " << age_;
    
    // 使用 weak_ptr 时需要先 lock() 转换为 shared_ptr
    if (auto comp = company_.lock()) {
        std::cout << ", 公司: " << comp->getName();
    } else {
        std::cout << ", 公司: 无";
    }
    std::cout << std::endl;
}