#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include "model.hpp"

using namespace std;

int main() {
  Paragraph p{"Here are some colors: "};
  ListItem red{"Red"};
  ListItem green{"Green"};
  ListItem blue{"Blue"};
  List colors{red, green, blue};

  vector<Element*>  document{&p, &colors};
  ostringstream oss;
  for_each(document.begin(), document.end(), [&](const Element* e) {
      // oss acts like a visitor
      e->printHTML(oss);
  });
  cout << oss.str();

  return 0;
}
