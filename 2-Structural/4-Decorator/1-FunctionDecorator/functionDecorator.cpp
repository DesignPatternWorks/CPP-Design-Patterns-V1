#include <iostream>
#include <string>

using namespace std;

#include <boost/algorithm/string.hpp>

struct Logger {
  // function with no args returning void
  function<void()> func;
  string name;

  Logger(const function<void()> &func, const string &name) : func{func}, name{name} {}

  void operator()() const {
    cout << "Entering " << name << endl;
    func();
    cout << "Exiting " << name << endl;
  }
};

template <typename Func>
struct Logger2 {
  // We want to have a more general function.
  // return value is not restricted to void anymore.
  Func func;
  string name;

  Logger2(const Func &func, const string &name) : func{func}, name{name} {}

  void operator()() const {
    cout << "Entering " << name << endl;
    func();
    cout << "Exiting " << name << endl;
  }
};

template <typename Func>
auto make_logger2(Func func, const string &name) {
  return Logger2<Func>{func, name}();  // () = call now
}

// need partial specialization for this to work
template <typename>
struct Logger3;

// return type and argument list
template <typename R, typename... Args>
struct Logger3<R(Args...)> {
  Logger3(function<R(Args...)> func, const string &name) : func{func}, name{name} {}

  R operator()(Args... args) {
    cout << "Entering " << name << endl;
    R result = func(args...);
    cout << "Exiting " << name << endl;
    return result;
  }

  function<R(Args...)> func;
  string name;
};

template <typename R, typename... Args>
auto make_logger3(R (*func)(Args...), const string &name) {
  return Logger3<R(Args...)>(std::function<R(Args...)>(func), name);
}

double add(double a, double b) {
  cout << a << "+" << b << "=" << (a + b) << endl;
  return a + b;
}

int main() {
  // logger is a decorator
  Logger logger{[](){cout << "Hello" << endl; }, "HelloFunc"};
  logger();

  // Template argument not deduced from lambda. Need a helper function.
  // Logger2<T?> logger1{[](){cout << "Hello" << endl; }, "HelloFunc"};
  make_logger2([]() { cout << "Hello" << endl; }, "HelloFunction");

  // add_logger behaves like the original add function.
  auto add_logger = make_logger3(add, "Add");
  auto result = add_logger(2, 3);

  return 0;
}
