// Dependencies should be abstract rather than concrete.
// Use interfaces instead of concrete types/classes.

// Introduction: https://boost-experimental.github.io/di/index.html
// Tutorial:     https://boost-experimental.github.io/di/tutorial/index.html

#include <iostream>
#include <memory>
#include "di.hpp"

struct ILogger {
  virtual void Log(const std::string& s) = 0;
};

struct ConsoleLogger : ILogger {
  void Log(const std::string& s) override { std::cout << "LOG: " << s.c_str() << std::endl; }
};

struct Engine {
  float volume = 5;
  int horse_power = 400;

  Engine(){};

  friend std::ostream& operator<<(std::ostream& os, const Engine& obj) {
    return os << "volume: " << obj.volume << " horse_power: " << obj.horse_power;
  }
};

struct Car {
  std::shared_ptr<Engine> engine;
  std::shared_ptr<ILogger> logger;

  Car(const std::shared_ptr<Engine>& engine, const std::shared_ptr<ILogger>& i_logger) : engine{engine}, logger{i_logger} {
    logger->Log("Created a car");
  }

  friend std::ostream& operator<<(std::ostream& os, const Car& obj) { return os << "car with engine: " << *obj.engine; }
};

int main() {
  // without DI
  std::cout << "without DI\n";
  auto e1 = std::make_shared<Engine>();
  auto logger1 = std::make_shared<ConsoleLogger>();
  auto c1 = std::make_shared<Car>(e1, logger1);
  std::cout << *c1 << std::endl;

  // with DI
  std::cout << "with DI\n";
  using namespace boost;
  // whenever an ILogger is needed a ConsoleLogger instance will be created
  auto injector = di::make_injector(di::bind<ILogger>().to<ConsoleLogger>());
  // engine created with default constructor
  auto c = injector.create<std::shared_ptr<Car>>();

  std::cout << *c << std::endl;

  return 0;
}
