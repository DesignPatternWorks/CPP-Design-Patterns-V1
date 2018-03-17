#include <iostream>
#include <string>
#include <vector>

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product {
  std::string name;
  Color color;
  Size size;
};

// Not scalable
struct ProductFilter {
  typedef std::vector<Product*> Items;
  static Items by_color(Items items, Color color) {
    Items result;
    for (auto& i : items)
      if (i->color == color) result.push_back(i);
    return result;
  }

  static Items by_size(Items items, Size Size) {
    Items result;
    for (auto& i : items)
      if (i->size == Size) result.push_back(i);
    return result;
  }

  static Items by_color_and_size(Items items, Color color, Size size) {
    Items result;
    for (auto& i : items)
      if (i->color == color && i->size == size) result.push_back(i);
    return result;
  }
};

// Better: Specification pattern
template <typename T>
struct ISpecification {
  virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct IFilter {
  virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& spec) = 0;
};

struct BetterFilter : IFilter<Product> {
  typedef std::vector<Product*> Items;
  std::vector<Product*> filter(std::vector<Product*> items, ISpecification<Product>& spec) override {
    Items result;
    for (auto& p : items)
      if (spec.is_satisfied(p)) result.push_back(p);
    return result;
  }
};

struct ColorSpecification : ISpecification<Product> {
  Color color;

  explicit ColorSpecification(const Color color) : color{color} {}

  bool is_satisfied(Product* item) override { return item->color == color; }
};

struct SizeSpecification : ISpecification<Product> {
  Size size;

  explicit SizeSpecification(const Size size) : size{size} {}

  bool is_satisfied(Product* item) override { return item->size == size; }
};

template <typename T>
struct AndSpecification : ISpecification<T> {
  ISpecification<T>& first;
  ISpecification<T>& second;

  AndSpecification(ISpecification<T>& first, ISpecification<T>& second) : first{first}, second{second} {}

  bool is_satisfied(T* item) override { return first.is_satisfied(item) && second.is_satisfied(item); }
};

int main() {
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  std::vector<Product*> all{&apple, &tree, &house};

  BetterFilter bf;
  ColorSpecification green(Color::Green);

  auto green_things = bf.filter(all, green);
  for (auto& x : green_things) std::cout << x->name << " is green" << std::endl;

  SizeSpecification big(Size::Large);
  AndSpecification<Product> green_and_big{big, green};

  auto green_big_things = bf.filter(all, green_and_big);
  for (auto& x : green_big_things) std::cout << x->name << " is green and big" << std::endl;

  return 0;
}
