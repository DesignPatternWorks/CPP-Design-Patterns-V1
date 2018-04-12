// Interface Segregation Principle
// Many client-specific interfaces are better than one general-purpose interface.

// => No client should be forced to depend on methods it does not use.

#include <iostream>
#include <string>
#include <vector>

struct Document {
  std::string content;
  explicit Document(std::string content) : content(content){};
};

// counter example!
// Do not use one huge general-purpose interface!
// I define an interface that should be implemented by the peripheral manufacturer.
struct IMachineHuge {
  virtual void print(std::vector<Document> docs) = 0;
  virtual void scan(std::vector<Document> docs) = 0;
  virtual void fax(std::vector<Document> docs) = 0;
};

// Peripheral manufacturer implements a specific interface.
// Multi Functional Peripheral (MFP)
struct MFP : IMachineHuge {
  void print(std::vector<Document> docs) override;
  void scan(std::vector<Document> docs) override;
  void fax(std::vector<Document> docs) override;
};

// Instead use many smaller interfaces.
struct IPrinter {
  virtual void print(std::vector<Document> docs) = 0;
};

struct IScanner {
  virtual void scan(std::vector<Document> docs) = 0;
};

struct Printer : IPrinter {
  void print(std::vector<Document> docs) override {
    for (auto& doc : docs) {
      std::cout << "Print:\t" << doc.content << std::endl;
    }
  };
};

struct Scanner : IScanner {
  void scan(std::vector<Document> docs) override {
    for (auto& doc : docs) {
      std::cout << "Scan:\t" << doc.content << std::endl;
    }
  };
};

// Now the peripheral manufacturer can implement the interfaces he actually provides and
// uses. We use multiple inheritance to create a bigger interface from the small ones.
struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine {
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter& printer, IScanner& scanner) : printer{printer}, scanner{scanner} {}

  void print(std::vector<Document> docs) override { printer.print(docs); }
  void scan(std::vector<Document> docs) override { scanner.scan(docs); }
};

int main() {
  Printer printer;
  Scanner scanner;
  Machine machine(printer, scanner);
  std::vector<Document> documents{Document(std::string("Hello")),
                                  Document(std::string("Hello"))};
  machine.print(documents);
  machine.scan(documents);

  return 0;
}
