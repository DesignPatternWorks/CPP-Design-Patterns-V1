#pragma once
#include <functional>
#include <map>
#include <string>
#include "CoffeeFactory.h"
#include "HotDrinkFactory.h"
#include "TeaFactory.h"

using namespace std;

struct HotDrink;

class DrinkFactory {
  map<string, unique_ptr<HotDrinkFactory>> factories;

 public:
  DrinkFactory() {
    factories["coffee"] = make_unique<CoffeeFactory>();
    factories["tea"] = make_unique<TeaFactory>();
  }

  unique_ptr<HotDrink> make_drink(const string& name) {
    auto drink = factories[name]->make();
    drink->prepare(200);  // oops!
    return drink;
  }
};
