#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class SingletonDatabase {
  std::map<std::string, int> capitals;

  // 1. Constructor is private!
  SingletonDatabase() {
    std::cout << "Initializing database" << std::endl;

    std::ifstream ifs("capitals.txt");

    std::string city, str_population;
    while (getline(ifs, city)) {
      getline(ifs, str_population);
      int population = boost::lexical_cast<int>(str_population);
      capitals[city] = population;
    }
  }

 public:
  // 2. Copy constructor and assignment do not exist for singleton database!
  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator=(SingletonDatabase const&) = delete;

  // 3. Only way to get access to singleton database via public static function!
  static SingletonDatabase& get() {
    // Database is static too!
    static SingletonDatabase db;
    return db;
  }

  int get_population(const std::string& name) { return capitals[name]; }
};

int main() {
  // Cannot do something like this because copy constructor does not exist!
  // auto singletonDB = SingletonDatabase::get();

  std::cout << SingletonDatabase::get().get_population("Tokyo") << "\n";

  // We will always get the same instance of the singleton database!
  assert(&SingletonDatabase::get() == &SingletonDatabase::get());

  return 0;
}
