#include "Person.h"

class Person::PersonImpl {
 public:
  void greet(Person *person) { printf("Hello, my name is %s!\n", person->name.c_str()); }
};

Person::Person(std::string name) : pImpl(new PersonImpl), name(name){};
void Person::greet() { pImpl->greet(this); };
