#include <iostream>
#include <string>

using namespace std;

#include <boost/signals2.hpp>

using namespace boost::signals2;

// Using Command Query Separation (CQS)
struct Query {
  string creature_name;
  enum Argument { attack, defense } argument;
  int result;

  Query(const string& creature_name, const Argument argument, const int result)
      : creature_name(creature_name), argument(argument), result(result) {}
};

// Game acts as a central event broker/bus using Boost Signals2.
// Event bus is actually the mediator design pattern.
struct Game {
  signal<void(Query&)> queries;
};

struct Creature {
  Game& game;
  int attack, defense;

 public:
  string name;

  Creature(Game& game, const int attack, const int defense, const string& name)
      : game(game), attack(attack), defense(defense), name(name) {}

  int GetAttack() const {
    Query q{name, Query::Argument::attack, attack};
    // Put the query on the event bus.
    game.queries(q);
    // The result of the query is in 'q.result'.
    // In between these calls every subscriber can modify the result.
    // This is exactly what the CreatureModifiers will do.
    return q.result;
  }

  friend std::ostream& operator<<(std::ostream& os, const Creature& obj) {
    return os << "attack: " << obj.GetAttack() << " defense: " << obj.defense
              << " name: " << obj.name;
  }
};

class CreatureModifier {
  Game& game;
  Creature& creature;

 public:
  CreatureModifier(Game& game, Creature& creature) : game(game), creature(creature) {}

  virtual ~CreatureModifier() = default;
};

class DoubleAttackModifier : public CreatureModifier {
  connection conn;

 public:
  DoubleAttackModifier(Game& game, Creature& creature)
      : CreatureModifier(game, creature) {
    // Whenever anybody puts a Query on the bus the lambda is executed.
    conn = game.queries.connect([&](Query& q) {
      if (q.creature_name == creature.name && q.argument == Query::Argument::attack) {
        q.result *= 2;
      }
    });
  }

  // We disconnect from the event bus when object goes out of scope.
  virtual ~DoubleAttackModifier() { conn.disconnect(); }
};

int main() {
  Game game;
  Creature goblin{game, 2 /* attack */, 2 /* defense */, "Strong Goblin"};

  cout << goblin << endl;

  {
    // Goblin only temporarily changed.
    DoubleAttackModifier dam{game, goblin};
    cout << goblin << endl;
  }

  cout << goblin << endl;

  return 0;
}
