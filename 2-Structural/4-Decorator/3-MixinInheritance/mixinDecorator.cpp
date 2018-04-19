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

  Circle() {}

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

  Square() {}

  explicit Square(const float side) : side{side} {}

  string str() const override {
    ostringstream oss;
    oss << "A square of with side " << side;
    return oss.str();
  }
};

// Mixin Inheritance

template <typename T> struct ColoredShape : T {
  // We are decorating T which must be a Shape by inheritance.
  static_assert(is_base_of<Shape, T>::value,
                "Template argument must be a Shape");

  string color;

  // need this
  ColoredShape() {}

  explicit ColoredShape(const string &color)
      : color{color} // you cannot call base class ctor here
                     // b/c you have no idea what it is
  {}

  string str() const override {
    ostringstream oss;
    oss << T::str() << " has the color " << color;
    return oss.str();
  }
};

template <typename T> struct TransparentShape : T {
  static_assert(is_base_of<Shape, T>::value,
                "Template argument must be a Shape");

  double transparency;

  TransparentShape(){}

  explicit TransparentShape(const double transparency): transparency{transparency} {}

  string str() const override {
    ostringstream oss;
    oss << T::str() << " has "
        << transparency * 100.0 << "% transparency";
    return oss.str();
  }
};

int main() {
  // Won't work without a default constructors. Here for Circle.
  ColoredShape<Circle> green_circle{"green"};
  green_circle.radius = 5;
  cout << green_circle.str() << endl;

  TransparentShape<ColoredShape<Square>> blue_invisible_square{0.5};
  blue_invisible_square.color = "blue";
  blue_invisible_square.side = 10;
  cout << blue_invisible_square.str() << endl;

  return 0;
}
