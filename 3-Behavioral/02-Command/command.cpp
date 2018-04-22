#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BankAccount {
  int balance = 0;
  int overdraft_limit = -500;

  void deposit(int amount) {
    balance += amount;
    cout << "deposited " << amount << ", balance now " << balance << "\n";
  }

  void withdraw(int amount) {
    if (balance - amount >= overdraft_limit) {
      balance -= amount;
      cout << "withdrew " << amount << ", balance now " << balance << "\n";
    }
  }
};

struct ICommand {
  virtual ~ICommand() = default;
  virtual void call() const = 0;
  virtual void undo() const = 0;
};

struct Command : ICommand {
  BankAccount& account;
  enum Action { deposit, withdraw } action;
  int amount;

  Command(BankAccount& account, const Action action, const int amount)
      : account(account), action(action), amount(amount) {}

  void call() const override {
    switch (action) {
      case deposit:
        account.deposit(amount);
        break;
      case withdraw:
        account.withdraw(amount);
        break;
      default:
        break;
    }
  }

  void undo() const override {
    switch (action) {
      case withdraw:
        account.deposit(amount);
        break;
      case deposit:
        account.withdraw(amount);
        break;
      default:
        break;
    }
  }
};

struct CommandList : vector<Command>, ICommand {
  CommandList(const ::std::initializer_list<value_type>& _Ilist)
      : vector<Command>(_Ilist) {}

  void call() const override {
    for (auto& cmd : *this) cmd.call();
  }

  void undo() const override {
    for_each(rbegin(), rend(), [](const Command& cmd) { cmd.undo(); });
  }
};

void printBalance(BankAccount& bankAccount) {
  cout << "Balance: " << bankAccount.balance << "\n\n";
}

int main() {
  BankAccount ba;
  // Composite command.
  CommandList commands{Command{ba, Command::deposit, 100},
                       Command{ba, Command::withdraw, 200}};
  printBalance(ba);

  commands.call();
  printBalance(ba);

  commands.undo();
  printBalance(ba);

  return 0;
}
