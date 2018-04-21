#include <iostream>
#include <memory>
#include <sstream>
#include <string>

using namespace std;

struct BankAccount {
  virtual ~BankAccount() = default;
  virtual void deposit(int amount) = 0;
  virtual void withdraw(int amount) = 0;
};

struct CurrentAccount : BankAccount  // checking
{
  explicit CurrentAccount(const int balance) : balance(balance) {}

  void deposit(int amount) override { balance += amount; }

  void withdraw(int amount) override {
    if (amount <= balance) balance -= amount;
  }

  friend ostream& operator<<(ostream& os, const CurrentAccount& obj) {
    return os << "balance: " << obj.balance;
  }

 private:
  int balance;
};

int main() {
  BankAccount* a = new CurrentAccount(1000);
  a->deposit(1500);
  delete a;

  auto b = make_shared<CurrentAccount>(1000);

  BankAccount* actual = b.get();  // pointer's own operations on a.
  b->deposit(150);                // underlying object's operations are on ->
                                  // note this expression is identical to what's above
  cout << *b << endl;
  // no delete

  return 0;
}
