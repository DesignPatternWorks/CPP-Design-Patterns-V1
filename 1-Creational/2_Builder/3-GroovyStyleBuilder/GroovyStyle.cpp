#include <boost/any.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace html {
struct Tag {
  std::string name;
  std::string text;
  std::vector<Tag> children;
  std::vector<std::pair<std::string, std::string>> attributes;

  friend std::ostream& operator<<(std::ostream& os, const Tag& tag) {
    os << "<" << tag.name;

    for (const auto& att : tag.attributes)
      os << " " << att.first << "=\"" << att.second << "\"";

    if (tag.children.size() == 0 && tag.text.length() == 0) {
      os << "/>" << std::endl;
    } else {
      os << ">" << std::endl;

      if (tag.text.length()) os << tag.text << std::endl;

      for (const auto& child : tag.children) os << child;

      os << "</" << tag.name << ">" << std::endl;
    }

    return os;
  }

 protected:
  Tag(const std::string& name, const std::string& text) : name{name}, text{text} {}
  Tag(const std::string& name, const std::vector<Tag>& children)
      : name{name}, children{children} {}
};

struct P : Tag {
  explicit P(const std::string& text) : Tag{"p", text} {}
  // We can feed the initializer list (initializer_list<Tag>)into a vector (Tag::children
  // is a vector<Tag>).
  explicit P(std::initializer_list<Tag> children) : Tag("p", children) {}
};

struct IMG : Tag {
  explicit IMG(const std::string& url) : Tag{"img", ""} {
    attributes.emplace_back(make_pair("src", url));
  }
};
}  // namespace html

using namespace html;

int main() {

  std::cout << P{IMG{"http://pokemon.com/pikachu.png"},
                 P{IMG{"http://pokemon.com/pikachu.jpg"}}}
            << std::endl;

  return 0;
}
