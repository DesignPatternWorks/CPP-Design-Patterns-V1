#pragma once
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilder {
  // This is the object we are building up.
  Person p;

 protected:
  // This is a reference to the object we are building up (defined in the private
  // section). This will be seen and used by the subclasses.
  Person& person;

  explicit PersonBuilder(Person& person) : person{person} {}

 public:
  PersonBuilder() : person{p} {}

  operator Person() { return std::move(person); }

  // builder facets

  PersonAddressBuilder lives();
  PersonJobBuilder works();
};
