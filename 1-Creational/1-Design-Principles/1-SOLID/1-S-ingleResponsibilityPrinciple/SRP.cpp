#include <fstream>
#include <string>
#include <vector>

struct Journal {
  std::string title;
  std::vector<std::string> entries;

  explicit Journal(const std::string& title) : title{title} {}

  void add(const std::string& entry) { entries.push_back(entry); }
};

// Do not put save method in Journal class but use a specialized class for saving stuff
struct PersistenceManager {
  static void save(const Journal& j, const std::string& filename) {
    std::ofstream ofs(filename);
    for (auto& s : j.entries) ofs << s << std::endl;
  }
};

int main() {
  Journal journal("My Journal");
  journal.add("First Entry");
  journal.add("Second Entry");
  journal.add("Third Entry");

  PersistenceManager().save(journal, "journal.txt");

  return 0;
}
