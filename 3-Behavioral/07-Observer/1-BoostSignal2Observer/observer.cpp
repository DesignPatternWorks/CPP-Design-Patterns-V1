#include <iostream>
#include <mutex>
#include <string>
#include <vector>

using namespace std;

#include <boost/any.hpp>
#include <boost/signals2.hpp>

using namespace boost;

template <typename T>
struct INotifyPropertyChanged {
  virtual ~INotifyPropertyChanged() = default;
  signals2::signal<void(T&, const string&)> PropertyChanged;
};

struct Person : INotifyPropertyChanged<Person> {
  explicit Person(const int age) : age(age) {}

  virtual int GetAge() const { return age; }

  virtual void SetAge(const int age) {
    if (this->age == age) return;

    this->age = age;
    PropertyChanged(*this, "age");
  }

 private:
  int age;
};

int main() {
  Person p{123};
  p.PropertyChanged.connect([](Person&, const string& property_name) {
    cout << property_name << " has been changed "
         << "\n";
  });
  p.SetAge(20);

  return 0;
}
