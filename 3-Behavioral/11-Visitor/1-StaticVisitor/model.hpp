#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Element {
  virtual ~Element() = default;
  virtual void printHTML(ostringstream& oss) const = 0;
  // If you want extend it to e.g. markdown printing you need a separate method,
  // Violates the Open-Closed Principle:
  // virtual void printMarkdown(ostringstream& oss) const = 0;
};

struct TextElement : Element {
  string text;
  explicit TextElement(const string& text) : text(text) {}
};

struct Paragraph : TextElement {
  explicit Paragraph(const string& text) : TextElement(text) {}
  void printHTML(ostringstream& oss) const override {
    oss << "<p>" << text << "</p>\n";
  }
};

struct ListItem : TextElement{
  explicit ListItem(const string& text) : TextElement(text){}
  void printHTML(ostringstream& oss) const override {
    oss << "<li>" << text << "</li>\n";
  }
};

struct List : vector<ListItem>, Element {
  List(const initializer_list<value_type>& _Ilist) : vector<ListItem>(_Ilist) {}

  void printHTML(ostringstream& oss) const override {
    oss << "<ul>\n";
    for (auto& li : *this)
      li.printHTML(oss);
    oss << "</ul>\n";
  }
};
