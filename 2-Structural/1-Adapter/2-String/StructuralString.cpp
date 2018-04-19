#include <boost/algorithm/string.hpp>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class String {
 public:
  String(const string& constString) : zeichenkette{constString} {}

  String to_lower() const {
    string str{zeichenkette};
    boost::to_lower(str);
    return {str};
  }

  vector<String> split(const string& delimeter = " ") const {
    vector<string> result;
    boost::split(result, zeichenkette, boost::is_any_of(delimeter),
                 boost::token_compress_on);
    return {result.begin(), result.end()};
  }

  friend std::ostream& operator<<(std::ostream& stream, const String& str) {
    stream << str.zeichenkette;
    return stream;
  }

 private:
  string zeichenkette;
};

int main() {
  String string{"Hello    World"};

  auto parts = string.to_lower().split();
  for (const auto& part : parts) cout << "<" << part << ">" << endl;

  return 0;
}
