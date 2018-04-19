#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

struct Shape {
  virtual string str() const = 0;
};

struct Circle : Shape {
  float radius;

  explicit Circle(const float radius) : radius{radius} {}

  void resize(float factor) { radius *= factor; }

  string str() const override {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : Shape {
  float side;

  explicit Square(const float side) : side{side} {}

  string str() const override {
    ostringstream oss;
    oss << "A square of with side " << side;
    return oss.str();
  }
};

// Mixin Inheritance

template <typename T>
struct ColoredShape : T {
  // We are decorating T which must be a Shape by inheritance.
  static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");

  string color;

  template <typename... Args>
  explicit ColoredShape(const string &color, Args... args) : color{color}, T{args...} {}

  string str() const override {
    ostringstream oss;
    oss << T::str() << " has the color " << color;
    return oss.str();
  }
};

template <typename T>
struct TransparentShape : T {
  static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape");

  double transparency;

  template <typename... Args>
  TransparentShape(const double transparency, Args... args)
      : transparency{transparency}, T{args...} {}

  string str() const override {
    ostringstream oss;
    oss << T::str() << " has " << transparency * 100.0 << "% transparency";
    return oss.str();
  }
};

int main() {
  // Now we can provide transparency and radius in the constructor.
  // Default constructors are not needed any more.
  TransparentShape<Square> half_hidden_square{0.5, 15.f};
  cout << half_hidden_square.str() << endl;

  return 0;
}
