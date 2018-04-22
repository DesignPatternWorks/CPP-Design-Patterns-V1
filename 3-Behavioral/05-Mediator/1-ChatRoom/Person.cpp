#include "Person.h"
#include "ChatRoom.h"

Person::Person(const string& name) : name(name) {}

void Person::say(const string& message) const { room->broadcast(name, message); }

void Person::receive(const string& origin, const string& message) {
  string s{origin + ": \"" + message + "\""};
  cout << "[" << name << "'s chat session] " << s << "\n";
  chat_log.emplace_back(s);
}

void Person::pm(const string& who, const string& message) {
  room->message(name, who, message);
}
