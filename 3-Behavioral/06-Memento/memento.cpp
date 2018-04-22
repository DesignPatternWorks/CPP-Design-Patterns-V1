#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Memento {
  int balance;

 public:
  Memento(const int balance) : balance(balance) {}
  friend class BankAccount;
  friend class BankAccount2;
};

class BankAccount {
  int balance = 0;

 public:
  explicit BankAccount(const int balance) : balance(balance) {}

  void restore(const Memento& m) { balance = m.balance; }

  Memento deposit(int amount) {
    balance += amount;
    return {balance};
  }

  friend std::ostream& operator<<(std::ostream& os, const BankAccount& obj) {
    return os << "balance: " << obj.balance;
  }
};

class BankAccount2 {
  int balance = 0;
  // Save all changes to balance in 'changes' vector.
  vector<shared_ptr<Memento>> changes;
  int current;

 public:
  explicit BankAccount2(const int balance) : balance(balance) {
    changes.emplace_back(make_shared<Memento>(balance));
    current = 0;
  }

  void restore(const shared_ptr<Memento>& m) {
    if (m) {
      balance = m->balance;
      changes.push_back(m);
      current = changes.size() - 1;
    }
  }

  shared_ptr<Memento> deposit(int amount) {
    balance += amount;
    auto m = make_shared<Memento>(balance);
    changes.push_back(m);
    ++current;
    return m;
  }

  shared_ptr<Memento> undo() {
    if (current > 0) {
      --current;
      auto m = changes[current];
      balance = m->balance;
    }
    return {};
  }

  shared_ptr<Memento> redo() {
    if (current + 1 < changes.size()) {
      ++current;
      auto m = changes[current];
      balance = m->balance;
      return m;
    }
    return {};
  }

  friend std::ostream& operator<<(std::ostream& os, const BankAccount2& obj) {
    return os << "balance: " << obj.balance;
  }
};

int main() {
  // Simple bank account with restore.
  BankAccount ba1{100};
  auto memento1 = ba1.deposit(50); // 150
  auto memento2 = ba1.deposit(25); // 175
  cout << ba1 << "\n";

  // restore to memento1
  ba1.restore(memento1);
  cout << ba1 << "\n";

  // restore to memento2
  ba1.restore(memento2);
  cout << ba1 << "\n---------------------\n";

  // More elaborate bank account with undo.
  BankAccount2 ba2{100};
  ba2.deposit(50);  // 150
  auto memento3 = ba2.deposit(25);  // 175
  cout << ba2 << "\n";

  ba2.undo();
  cout << "Undo:\t " << ba2 << "\n";
  ba2.undo();
  cout << "Undo:\t " << ba2 << "\n";
  ba2.redo();
  cout << "Redo:\t " << ba2 << "\n";
  // Restore still possible.
  ba2.restore(memento3);
  cout << "Restore: " << ba2 << "\n";

  return 0;
}
