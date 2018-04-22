#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <boost/signals2.hpp>

using namespace boost::signals2;

struct Event {
  virtual ~Event() = default;
  virtual void print() const = 0;
};

struct Player;

struct PlayerScored : Event {
  string player_name;
  int goals_scored_so_far;

  PlayerScored(const string& player_name, const int goals_scored_so_far)
      : player_name(player_name), goals_scored_so_far(goals_scored_so_far) {}

  void print() const override;
};

void PlayerScored::print() const {
  cout << player_name << " has scored! (their " << goals_scored_so_far << " goal)"
       << "\n";
}

struct Game  // event bus / broker
{
  signal<void(Event*)> events;  // observer
};

struct Player {
  string name;
  int goals_scored = 0;
  Game& game;

  Player(const string& name, Game& game) : name(name), game(game) {}

  void score() {
    goals_scored++;
    PlayerScored ps{name, goals_scored};
    game.events(&ps);
  }
};

struct Coach {
  Game& game;

  explicit Coach(Game& game) : game(game) {
    game.events.connect([](Event* e) {
      PlayerScored* ps = dynamic_cast<PlayerScored*>(e);
      if (ps && ps->goals_scored_so_far < 3) {
        cout << "coach says: well done, " << ps->player_name << "\n";
      }
    });
  }
};

int main() {
  // Using Boost Signal2.
  Game game;
  Player player{"Dmitri", game};
  Coach coach{game};

  player.score();
  player.score();
  player.score();

  return 0;
}
