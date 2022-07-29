#pragma once

#include <string>

struct Person {
  std::string name;
  Person(std::string _name) : name{ _name } {};
};

inline std::ostream& operator<<(std::ostream& os, Person& p) {
  return os << "Person(name:" << p.name << ");";
}
