#pragma once

#include <memory>

// 前向声明，避免头文件相互 include
class ClassB;

class ClassA : public std::enable_shared_from_this<ClassA> {
public:
  ClassA();
  ~ClassA();

  void bindB(const std::shared_ptr<ClassB>& b);
  void hello();

private:
  std::shared_ptr<ClassB> b_;
};
