#include "class_a.h"
#include "class_b.h"
#include <iostream>

ClassA::ClassA() {
    std::cout << "ClassA ctor\n";
}

ClassA::~ClassA() {
    std::cout << "ClassA dtor\n";
}

void ClassA::bindB(const std::shared_ptr<ClassB>& b) {
    b_ = b;
}

void ClassA::hello() {
    std::cout << "Hello from ClassA\n";
    if (b_) {
        b_->hello();
    }
}
