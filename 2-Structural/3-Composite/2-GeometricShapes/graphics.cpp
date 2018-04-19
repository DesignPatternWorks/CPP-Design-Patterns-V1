#include <iostream>
#include <memory>
#include <vector>

struct GraphicObject {
  virtual void draw() = 0;
};

struct Circle : GraphicObject {
  void draw() override { std::cout << "Circle" << std::endl; }
};

struct Rectangle : GraphicObject {
  void draw() override { std::cout << "Rectangle" << std::endl; }
};

struct Group : GraphicObject {
  std::string name;

  explicit Group(const std::string &name) : name{name} {}

  void draw() override {
    std::cout << "Group " << name.c_str() << " contains:" << std::endl;
    for (auto &&o : objects) o->draw();
  }

  std::vector<GraphicObject *> objects;
};

int main() {
  Group root("root");
  Circle c1;
  root.objects.push_back(&c1);

  Group subgroup("sub");
  Circle c2;
  Rectangle r1;
  subgroup.objects.push_back(&c2);
  subgroup.objects.push_back(&r1);

  root.objects.push_back(&subgroup);

  root.draw();

  return 0;
}
