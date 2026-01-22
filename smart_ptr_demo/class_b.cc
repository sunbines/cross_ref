#include "class_b.h"
#include "class_a.h"
#include <iostream>

ClassB::ClassB() {
    std::cout << "ClassB ctor\n";
}

ClassB::~ClassB() {
    std::cout << "ClassB dtor\n";
}

void ClassB::bindA(const std::shared_ptr<ClassA>& a) {
    a_ = a;
}

void ClassB::hello() {
    std::cout << "Hello from ClassB\n";

    if (auto a = a_.lock()) {
        std::cout << "ClassB can access ClassA\n";
    } else {
        std::cout << "ClassA already destroyed\n";
    }
}
