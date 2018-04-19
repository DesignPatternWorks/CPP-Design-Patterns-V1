#include "Person.h"
#include <string>


int main() {
  Person john(std::string("John"));
  // greet method is implemented in class PersonImpl not in class Person
  john.greet();

  return 0;
}
