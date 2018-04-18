#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType { cartesian, polar };

class Point {
 public:
  friend std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << "x: " << point.x << " y: " << point.y;
  }

  static Point NewCartesian(double x, double y) { return {x, y}; }
  static Point NewPolar(double r, double theta) { return {r * cos(theta), r * sin(theta)}; }

 private:
  Point(const double x, const double y) : x{x}, y{y} {}
  double x, y;
};

int main() {
  auto p = Point::NewPolar(5, M_PI_4);
  std::cout << p << std::endl;

  return 0;
}
