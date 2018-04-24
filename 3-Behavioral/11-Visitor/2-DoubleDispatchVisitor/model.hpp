#pragma once

#include <string>
#include <vector>
#include "visitor.hpp"

using namespace std;

// struct Visitor;

struct Element {
  virtual ~Element() = default;
  virtual void accept(Visitor& v) const = 0;
};

// In-between abstract class. 'accept()' not implemented.
struct TextElement : Element {
  string text;

  explicit TextElement(const string& text) : text(text) {}
};

struct Paragraph : TextElement {
  explicit Paragraph(const string& text) : TextElement(text) {}

  void accept(Visitor& v) const override { v.visit(*this); }
};

struct ListItem : TextElement {
  explicit ListItem(const string& text) : TextElement(text) {}

  void accept(Visitor& v) const override { v.visit(*this); }
};

struct List : vector<ListItem>, Element {
  List(const initializer_list<value_type>& _Ilist) : vector<ListItem>(_Ilist) {}

  void accept(Visitor& v) const override { v.visit(*this); }
};
