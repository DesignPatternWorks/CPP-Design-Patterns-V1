#pragma once

#include "Person.h"

struct ChatRoom {
  vector<Person> people;

  class PersonReference {
    vector<Person>& people;
    unsigned int index;

   public:
    PersonReference(vector<Person>& persons, const unsigned index)
        : people(persons), index(index) {}

    Person* operator->() const;
  };

  void broadcast(const string& origin, const string& message);
  PersonReference join(Person&& p);
  void message(const string& origin, const string& who, const string& message);
};
