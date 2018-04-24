#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include "model.hpp"

using namespace std;

struct HTMLVisitor : Visitor {
  void visit(const Paragraph& paragraph) override {
    oss << "<p>" << paragraph.text << "</p>\n";
  }

  void visit(const ListItem& listItem) override {
    oss << "<li>" << listItem.text << "</li>\n";
  }

  void visit(const List& list) override {
    oss << "<ul>\n";
    for (auto& elem : list) elem.accept(*this);
    oss << "</ul>\n";
  }

  string str() const override { return oss.str(); }

 private:
  ostringstream oss;
};

// If you want to have a markdown visitor you can do so easyily
// without touching other classes:

struct MarkdownVisitor : Visitor {
  void visit(const Paragraph& paragraph) override {
    oss << "*" << paragraph.text << "*\n";
  }

  void visit(const ListItem& listItem) override {
    oss << "_" << listItem.text << "_\n";
  }

  void visit(const List& list) override {
    oss << "**\n";
    for (auto& elem : list) elem.accept(*this);
    oss << "**\n";
  }

  string str() const override { return oss.str(); }

private:
  ostringstream oss;
};

int main() {
  Paragraph p{"Here are some colors: "};
  ListItem red{"Red"};
  ListItem green{"Green"};
  ListItem blue{"Blue"};
  List colors{red, green, blue};

  vector<Element*> document{&p, &colors};
  HTMLVisitor htmlVisitor;
  ostringstream oss;
  for_each(document.begin(), document.end(), [&](const Element* e) {
    // we call 'accept()' which in turn calls 'visit()'' with the proper class:
    // Paragraph, ListItem or List.
    e->accept(htmlVisitor);
  });
  cout << "HTML:\n" << htmlVisitor.str();

  MarkdownVisitor markdownVisitor;
  oss.clear();
  for_each(document.begin(), document.end(), [&](const Element* e) {
      // we call 'accept()' which in turn calls 'visit()'' with the proper class:
      // Paragraph, ListItem or List.
      e->accept(markdownVisitor);
    });
  cout << "\nMarkdown:\n" << markdownVisitor.str();

  return 0;
}
