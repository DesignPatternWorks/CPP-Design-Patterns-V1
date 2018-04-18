#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct Address {
  string street;
  string city;
  int suite;

  friend std::ostream& operator<<(std::ostream& os, const Address& obj) {
    return os << "street:\t" << obj.street << "\ncity:\t" << obj.city
              << "\nsuite:\t" << obj.suite << "\n------------------" ;
  }
};

struct Employee {
  string name;
  Address* work_address;

  Employee(const string& name, Address* const work_address)
      : name{name}, work_address{new Address{*work_address}} {}

  ~Employee() { delete work_address; }

  Employee(const Employee& other)
      : name{other.name}, work_address(new Address{*other.work_address}) {}

  friend std::ostream& operator<<(std::ostream& os, const Employee& obj) {
    return os << "name:\t" << obj.name << "\naddress:\n" << *obj.work_address;
  }
};

struct EmployeeFactory {
  // Prototypes!
  static Employee main, aux;

  static unique_ptr<Employee> NewMainOfficeEmployee(string name, int suite) {
    return NewEmployee(name, suite, main);
  }

  static unique_ptr<Employee> NewAuxOfficeEmployee(string name, int suite) {
    return NewEmployee(name, suite, aux);
  }

 private:
  static unique_ptr<Employee> NewEmployee(string name, int suite, Employee& proto) {
    auto result = make_unique<Employee>(proto);
    result->name = name;
    result->work_address->suite = suite;
    return result;
  }
};

// Here are the prototypes!
Employee EmployeeFactory::main{"", new Address{"123 East Dr", "London", 0}};
Employee EmployeeFactory::aux{"", new Address{"123B East Dr", "London", 0}};

int main() {
  auto john = EmployeeFactory::NewMainOfficeEmployee("John", 100);
  auto jane = EmployeeFactory::NewAuxOfficeEmployee("Jane", 123);

  cout << *john << endl << *jane << endl;

  return 0;
}
