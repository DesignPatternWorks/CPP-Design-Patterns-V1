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
  static HtmlBuilder build(string root_name);
  static unique_ptr<HtmlBuilder> create(string root_name);
};

struct HtmlBuilder {
  explicit HtmlBuilder(const string& root_name) { root.name = root_name; }

  // void to start with
  HtmlBuilder& add_child(const string& child_name, const string& child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }

  // pointer based
  // I have the suspicion that his method is causing problems!
  HtmlBuilder* add_child_2(const string& child_name, const string& child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return this;
  }

  string str() { return root.str(); }

  operator HtmlElement() { return root; }

  HtmlElement root;
};

HtmlBuilder HtmlElement::build(string root_name) { return HtmlBuilder{root_name}; }

unique_ptr<HtmlBuilder> HtmlElement::create(string root_name) {
  return make_unique<HtmlBuilder>(root_name);
}

int main() {
  // add_child returns an HtmlBuilder.
  // Due to conversion operator HtmlElement() in HtmlBuilder this will be converted to an
  // HtmlElement!
  HtmlElement htmlElement1 =
      HtmlElement::build("ul").add_child("li", "hello").add_child("li", "world");
  cout << htmlElement1.str() << endl;

  return 0;

  // Crashes.
  // HtmlBuilder* htmlElement2 = HtmlElement::create("ul")->add_child_2("li",
  // "hello")->add_child_2("li", "world"); cout << htmlElement2->str() << endl;
}
