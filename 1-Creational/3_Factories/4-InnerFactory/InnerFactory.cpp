#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class Point {
 private:
  double x, y;

  // Use a factory as constructor is private!
  Point(double x, double y) : x(x), y(y) {}

  friend std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << "x: " << point.x << " y: " << point.y;
  }

  struct PointFactory {
    static Point NewCartesian(double x, double y) { return {x, y}; }
    static Point NewPolar(double r, double theta) {
      return {r * cos(theta), r * sin(theta)};
    }
  };

 public:
  static PointFactory Factory;
};

int main() {
  auto cartesianPoint = Point::Factory.NewCartesian(2, 3);
  std::cout << cartesianPoint << std::endl;

  return 0;
}
