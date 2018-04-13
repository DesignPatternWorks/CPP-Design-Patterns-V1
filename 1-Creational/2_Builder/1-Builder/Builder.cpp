#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct HtmlBuilder;

struct HtmlElement {
  string name;
  string text;
  vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement() {}
  HtmlElement(const string& name, const string& text) : name(name), text(text) {}

  string str(int indent = 0) const {
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0) oss << string(indent_size * (indent + 1), ' ') << text << endl;

    for (const auto& e : elements) oss << e.str(indent + 1);

    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  static unique_ptr<HtmlBuilder> build(string root_name) {
    return make_unique<HtmlBuilder>(root_name);
  }
};

struct HtmlBuilder {
  explicit HtmlBuilder(const string& root_name) { root.name = root_name; }

  // void to start with
  void add_child(const string& child_name, const string& child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
  }

  string str() { return root.str(); }

  HtmlElement root;
};

int main() {
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "hello");
  builder.add_child("li", "world");
  cout << builder.str() << endl;

  return 0;
}
