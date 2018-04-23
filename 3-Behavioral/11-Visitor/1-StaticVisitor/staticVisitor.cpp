#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "model.hpp"

using namespace std;

int main() {

  Paragraph p {"Here are some colors: "};
  ListItem red {"Red"};
  ListItem green {"Green"};
  ListItem blue {"Blue"};
  List colors {red, green, blue};

  vector<Element> document{&p, &colors};
  ostringstream oss;
  for_each(document.begin, document.end(), [&](const Element* e) {
      
    });

  return 0;
}
