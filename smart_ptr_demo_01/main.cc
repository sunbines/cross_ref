#include "class_a.h"
#include "class_b.h"
#include <memory>

int main() {
    auto a = std::make_shared<ClassA>();
    auto b = std::make_shared<ClassB>();

    a->bindB(b);
    b->bindA(a);

    a->hello();

    return 0;
}
