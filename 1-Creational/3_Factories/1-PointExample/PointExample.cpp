#include <cmath>
#include <iostream>

enum class PointType { cartesian, polar };

class Point {
 public:
  Point(float a, float b, PointType type = PointType::cartesian) {
    if (type == PointType::cartesian) {
      x = a;
      y = b;
    } else {
      x = a * cos(b);
      y = a * sin(b);
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << "x: " << point.x << " y: " << point.y;
  }

 private:
  float x, y;
};

int main() {
  Point p{1, 2};
  std::cout << p << std::endl;

  return 0;
}
