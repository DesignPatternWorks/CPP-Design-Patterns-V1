// Open-closed Principle
// entities should be open for extension, but closed for modification

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

typedef std::vector<Product> ProductList;

// This is how not to do it.
// To add new criteria you have to go into this class again and change and also test it.
// Violates the Open-closed Principle.
struct ProductFilter {
  static ProductList by_color(ProductList items, Color color) {
    ProductList result;
    for (auto& item : items)
      if (item.color == color) result.push_back(item);
    return result;
  }

  static ProductList by_size(ProductList items, Size Size) {
    ProductList result;
    for (auto& i : items)
      if (i.size == Size) result.push_back(i);
    return result;
  }

  // Not scalable !!!
  // We'd need all combinations of possible filter criteria.
  static ProductList by_color_and_size(ProductList items, Color color, Size size) {
    ProductList result;
    for (auto& item : items)
      if (item.color == color && item.size == size) result.push_back(item);
    return result;
  }
};

// Better: Generalize with interfaces
// Specification pattern. Not a GoF pattern but extensively used.
// Reminds of generative programming (GP).
// it's an interface = class with virtual functions
// generic specification
template <typename T>
struct ISpecification {
  virtual bool is_satisfied(T item) = 0;
};

// we can combine specifications
template <typename T>
struct AndSpecification : ISpecification<T> {
  ISpecification<T>& first;
  ISpecification<T>& second;

  AndSpecification(ISpecification<T>& first, ISpecification<T>& second) : first{first}, second{second} {}

  bool is_satisfied(T item) override { return first.is_satisfied(item) && second.is_satisfied(item); }
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

// another interface that uses the specification interface
// generic filter
template <typename T>
struct IFilter {
  // try to pass spec by value and you end up in OO hell!
  virtual ProductList filter(ProductList& items, ISpecification<T>& spec) = 0;
};

// BetterFilter is a product filter
struct BetterFilter : IFilter<Product> {
  ProductList filter(ProductList& items, ISpecification<Product>& spec) override {
    ProductList result;
    for (auto& productItem : items)
      if (spec.is_satisfied(productItem)) result.push_back(productItem);
    return result;
  }
};

int main() {
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  ProductList all{apple, tree, house};

  BetterFilter bf;
  ColorSpecification green(Color::Green);

  auto green_things = bf.filter(all, green);
  for (auto& product : green_things) std::cout << product.name << " is green" << std::endl;

  SizeSpecification big(Size::Large);
  // green_and_big is a product specification
  AndSpecification<Product> green_and_big{big, green};

  auto green_big_things = bf.filter(all, green_and_big);
  for (auto& product : green_big_things) std::cout << product.name << " is green and big" << std::endl;

  return 0;
}
