#include <iostream>
#include <string>

using namespace std;

struct Creature {
  string name;
  int attack, defense;

  Creature(const string& name, const int attack, const int defense)
      : name(name), attack(attack), defense(defense) {}

  friend std::ostream& operator<<(std::ostream& os, const Creature& obj) {
    return os << "name: " << obj.name << " attack: " << obj.attack
              << " defense: " << obj.defense;
  }
};

class CreatureModifier {
  CreatureModifier* next = nullptr;

 protected:
  Creature& creature;

 public:
  explicit CreatureModifier(Creature& creature) : creature(creature) {}
  virtual ~CreatureModifier() = default;

  void add(CreatureModifier* cm) {
    if (next)
      next->add(cm);
    else
      next = cm;
  }

  virtual void handle() {
    if (next) next->handle();
  }
};

// 1. Double the creature's attack
// 2. Increase defense by 1 unless power > 2
// 3. No bonuses can be applied to this creature.

class NoBonusModifier : public CreatureModifier {
 public:
  explicit NoBonusModifier(Creature& creature) : CreatureModifier(creature) {}

  // Don't do anything and stop the chain of responsibility,
  void handle() override {}
};

class DoubleAttackModifier : public CreatureModifier {
 public:
  explicit DoubleAttackModifier(Creature& creature) : CreatureModifier(creature) {}

  void handle() override {
    creature.attack *= 2;
    CreatureModifier::handle();
  }
};

class IncreaseDefenseModifier : public CreatureModifier {
 public:
  explicit IncreaseDefenseModifier(Creature& creature) : CreatureModifier(creature) {}

  void handle() override {
    if (creature.attack <= 2) creature.defense++;
    CreatureModifier::handle();
  }
};

int main() {
  Creature goblin{"Goblin", 1, 1};
  CreatureModifier root{goblin};
  DoubleAttackModifier r1{goblin};
  DoubleAttackModifier r1_2{goblin};
  IncreaseDefenseModifier r2{goblin};
  // Uncomment the following lines to stop chain of responsibility instantly
  // NoBonusModifier no{goblin};
  // root.add(&no);

  root.add(&r1);
  root.add(&r1_2);
  root.add(&r2);

  // Start chain of responsibility.
  root.handle();

  cout << goblin << endl;

  return 0;
}
