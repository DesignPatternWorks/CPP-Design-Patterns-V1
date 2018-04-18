#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/serialization.hpp>

struct Address {
  string street, city;
  int suite;

  friend ostream& operator<<(ostream& os, const Address& obj) {
    return os << "street:\t" << obj.street << "\ncity:\t" << obj.city
              << "\nsuite:\t" << obj.suite << "\n-------------------------";
  }

 private:
  friend class boost::serialization::access;

  template <class Ar>
  void serialize(Ar& ar, const unsigned int version) {
    ar& street;
    ar& city;
    ar& suite;
  }
};

struct Employee {
  string name;
  Address* address;

  friend ostream& operator<<(ostream& os, const Employee& obj) {
    return os << "name:\t" << obj.name << "\naddress:\n" << *obj.address;
  }

 private:
  friend class boost::serialization::access;

  template <class Archive>
  void serialize(Archive& archive, const unsigned int version) {
    archive& name;
    archive& address;
  }
};

int main() {
  Employee john;
  john.name = "John Doe";
  john.address = new Address{"123 East Dr", "London", 123};

  // Boost Serialization does a deep copy out-of-the box!
  auto clone = [](Employee c) {
    // Write employee to an archive
    ostringstream oss;
    boost::archive::text_oarchive oa(oss);
    oa << c;

    string s = oss.str();

    // Read it back in. Deep copy automatically done!
    Employee result;
    istringstream iss(s);
    boost::archive::text_iarchive ia(iss);
    ia >> result;
    return result;
  };

  Employee jane = clone(john);
  jane.name = "Jane";
  jane.address->street = "123B West Dr";

  cout << john << endl << jane << endl;

  return 0;
}
