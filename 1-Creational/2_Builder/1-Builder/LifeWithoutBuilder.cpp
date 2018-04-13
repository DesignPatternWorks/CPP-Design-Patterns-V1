#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // 1. Using out-of-the-box string concatenation
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << "1. cout:" << endl;
  cout << output << endl;

  // 2. Using printf:
  cout << "\n2. Printf:" << endl;
  printf("<p>%s</p>\n", text);

  // 3. Using string streams
  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "<ul>\n";
  for (auto w : words) oss << "  <li>" << w << "</li>\n";
  oss << "</ul>\n";
  cout << "\n3. Output Stream:" << endl;
  printf("%s", oss.str().c_str());

   return 0;
}
