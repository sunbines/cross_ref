#pragma once

#include <memory>

// 前向声明
class ClassA;

class ClassB {
public:
    ClassB();
    ~ClassB();

    void bindA(const std::shared_ptr<ClassA>& a);
    void hello();

private:
    std::weak_ptr<ClassA> a_;
};
