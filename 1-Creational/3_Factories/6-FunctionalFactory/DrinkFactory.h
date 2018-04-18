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

class DrinkWithVolumeFactory {
  map<string, function<unique_ptr<HotDrink>()>> factories;

 public:
  DrinkWithVolumeFactory() {
    factories["tea"] = [] {
      auto tea = make_unique<Tea>();
      tea->prepare(100);
      return tea;
    };
    factories["coffee"] = [] {
      auto coffee = make_unique<Coffee>();
      coffee->prepare(100);
      return coffee;
    };
  }

  unique_ptr<HotDrink> make_drink(const string& name) { return factories[name](); }
};
