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
  typedef std::vector<Product> Items;
  static Items by_color(Items items, Color color) {
    Items result;
    for (auto& item : items)
      if (item.color == color) result.push_back(item);
    return result;
  }

  static Items by_size(Items items, Size Size) {
    Items result;
    for (auto& i : items)
      if (i.size == Size) result.push_back(i);
    return result;
  }

  static Items by_color_and_size(Items items, Color color, Size size) {
    Items result;
    for (auto& item : items)
      if (item.color == color && item.size == size) result.push_back(item);
    return result;
  }
};

// Better: Specification pattern. Not an official GoF pattern but extensively used.
// Reminds of generative programming (GP).
template <typename T>
struct ISpecification {
  virtual bool is_satisfied(T item) = 0;
};

// ColorSpecification is a product specification
struct ColorSpecification : ISpecification<Product> {
  Color color;

  explicit ColorSpecification(const Color color) : color{color} {}

  bool is_satisfied(Product item) override { return item.color == color; }
};

// SizeSpecification is a product specification
struct SizeSpecification : ISpecification<Product> {
  Size size;

  explicit SizeSpecification(const Size size) : size{size} {}

  bool is_satisfied(Product item) override { return item.size == size; }
};

template <typename T>
struct IFilter {
  typedef std::vector<T> Items;
  virtual Items filter(Items items, ISpecification<T>& spec) = 0;
};

// BetterFilter is a product filter
struct BetterFilter : IFilter<Product> {
  typedef std::vector<Product> Items;
  Items filter(Items items, ISpecification<Product>& spec) override {
    Items result;
    for (auto& productItem : items)
      if (spec.is_satisfied(productItem)) result.push_back(productItem);
    return result;
  }
};

template <typename T>
struct AndSpecification : ISpecification<T> {
  ISpecification<T>& first;
  ISpecification<T>& second;

  AndSpecification(ISpecification<T>& first, ISpecification<T>& second) : first{first}, second{second} {}

  bool is_satisfied(T item) override { return first.is_satisfied(item) && second.is_satisfied(item); }
};

int main() {
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  std::vector<Product> all{apple, tree, house};

  BetterFilter bf;
  ColorSpecification green(Color::Green);

  auto green_things = bf.filter(all, green);
  for (auto& productItem : green_things) std::cout << productItem.name << " is green" << std::endl;

  SizeSpecification big(Size::Large);
  // green_and_big is a product specification
  AndSpecification<Product> green_and_big{big, green};

  auto green_big_things = bf.filter(all, green_and_big);
  for (auto& productItem : green_big_things) std::cout << productItem.name << " is green and big" << std::endl;

  return 0;
}
