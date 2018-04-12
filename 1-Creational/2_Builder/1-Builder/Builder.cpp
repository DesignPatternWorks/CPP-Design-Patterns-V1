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
  HtmlBuilder& add_child(const string& child_name, const string& child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }

  // pointer based
  HtmlBuilder* add_child_2(const string& child_name, const string& child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return this;
  }

  string str() { return root.str(); }

  HtmlElement root;
};

int main() {
  // <p>hello</p>
  // handish: using out-of-the-box string concatenation
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << "Cout:" << endl;
  cout << output << endl;

  cout << "\nPrintf:" << endl;
  printf("<p>%s</p>\n", text);

  // <ul><li>hello</li><li>world</li></ul>
  // a bit more comfortable with string streams
  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "<ul>\n";
  for (auto w : words) oss << "  <li>" << w << "</li>\n";
  oss << "</ul>\n";
  cout << "\nOutput Stream:" << endl;
  printf("%s", oss.str().c_str());

  // using a dedicated HTML builder
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "hello").add_child("li", "world");
  cout << "\nBuilder:" << endl;
  cout << builder.str() << endl;

  return 0;

  // Throws exception. Don't know why.
  // auto builder2 = HtmlElement::build("ul")->add_child_2("li",
  // "hello")->add_child_2("li", "world"); cout << "\nBuilder (Pointer):" << endl; cout <<
  // builder2->str() << endl;
}
