#pragma once

#include <memory>
#include <string>

class Person {
 public:
  Person(std::string name);
  void greet();

 private:
  std::string name;
  // Pointer to an implementation (PIMPL)
  class PersonImpl;   // forward declaration of the implementation class
  PersonImpl* pImpl;
};
