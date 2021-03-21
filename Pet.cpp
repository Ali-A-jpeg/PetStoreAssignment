// Pet.cpp
// 2a-Lab-06-Pets
//
#include <iostream>
#include <sstream>
#include <vector>
#include "Pet.h"
using namespace std;
// This is a way to properly initialize (out-of-line) a static variable.
size_t Pet::_population = 0;
Pet::Pet(string name, long id, int num_limbs) {
  _name = name;
  _id = id;
  _num_limbs = num_limbs;
  _population += 1;
}
Pet::~Pet() {
  _population -= 1;
}
string Pet::get_name() const { return _name; }

long Pet::get_id() const {
  return _id;
}
int Pet::get_num_limbs() const {
  return _num_limbs;
}
bool Pet::set_name(string name) {
  if (name == "") {
    return false;
  }
  else {
    _name = name;
    return true;
  }
}
bool Pet::set_id(long id) {
  if (id <= 0) {
    return false;
  }
  else {
    _id = id;
    return true;
  }
}
bool Pet::set_num_limbs(int num_limbs) {
  if (num_limbs < 0) {
    return false;
  }
  else {
    _num_limbs = num_limbs;
    return true;
  }
}
string Pet::to_string() const {
  return ("(Name: " + (get_name()) + ", ID: " + std::to_string(get_id()) + ", Limb Count: " + std::to_string(get_num_limbs()) + ")");
}
// Fill in the supplied pets vector with n pets whose
// properties are chosen randomly.
// Don't mess with this method more than necessary.
void Pet::get_n_pets(size_t n, std::vector<Pet>& pets, int name_len) {
  long prev_id = 0;
  for (size_t i = 0; i < n; i++) {
    long id = prev_id + 1 + rand() % 10;
    Pet pet;
    pets.push_back(pet);
    pets[i].set_id(id);
    pets[i].set_num_limbs(rand() % 9);
    pets[i].set_name(Pet::make_a_name(name_len));
    prev_id = id;
  }
}
// ---------------------------------------------------------------------
string Pet::make_a_name(int len) {
  if (len == 0) {
    return "";
  }
  string vowels = "aeiou";
  string consonants = "bcdfghjklmnpqrstvwxyz";
  string name = "";
  int letter;
  if (rand() % 2 == 0) {
    name += consonants[rand() % consonants.length()];
    letter = 0;
  }
  else {
    name += vowels[rand() % vowels.length()];
    letter = 1;
  }
  for (int i = 0; i < len-1; i++) {
    if (letter == 0) {
      name += vowels[rand() % vowels.length()];
      letter = 1;
    }
    else {
      name += consonants[rand() % consonants.length()];
      letter = 0;
    }
  }
  return name;
}
// Optional EC points
// Global helpers
bool operator==(const Pet& pet1, const Pet& pet2) {
  // TODO - Your code here
  return ((pet1.get_name() == pet2.get_name()) && (pet1.get_num_limbs() == pet2.get_num_limbs()) && (pet1.get_id() == pet2.get_id()));
}
bool operator!=(const Pet& pet1, const Pet& pet2) {
  // TODO - Your code here
  return !(pet1 == pet2);
}
ostream& operator<<(ostream& os, const Pet& pet) {
  // TODO - Your code here
  os << pet.to_string();
  return os;
}
