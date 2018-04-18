#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class Point {
 private:
  friend std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << "x: " << point.x << " y: " << point.y;
  }

  friend class PointFactory;

  // Use a factory as constructor is private!
  Point(double x, double y) : x(x), y(y) {}
  double x, y;
};

class PointFactory {
 public:
  static Point NewCartesian(double x, double y) { return Point{x, y}; }

  static Point NewPolar(double r, double theta) {
    return Point{r * cos(theta), r * sin(theta)};
  }
};

int main() {
  auto cartesianPoint = PointFactory::NewCartesian(1.1, 2.2);
  auto polarPoint = PointFactory::NewPolar(2.0, M_PI_4);

  std::cout << cartesianPoint << std::endl;
  std::cout << polarPoint << std::endl;

  return 0;
}
