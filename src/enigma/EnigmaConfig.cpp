#include "EnigmaConfig.h"

EnigmaConfig::EnigmaConfig(Plugboard& p, Reflector& r, Rotor& r1, Rotor& r2, Rotor& r3) {
    EnigmaConfig::setPlugboard(p);
    EnigmaConfig::setReflector(r);
    EnigmaConfig::setRotor(r1, r2, r3);
}

void EnigmaConfig::setRotor(Rotor& r1, Rotor& r2, Rotor& r3) {
    rotors.setRotor(r1, 1);
    rotors.setRotor(r2, 2);
    rotors.setRotor(r3, 3);
}

void EnigmaConfig::setReflector(Reflector& r) {
    this->reflector = r;
}

void EnigmaConfig::setPlugboard(Plugboard& p) {
    this->plugboard = p;
}

RotorHolder EnigmaConfig::getRotors() {
    return this->rotors;
}

Reflector EnigmaConfig::getReflector() {
    return this->reflector;
}

Plugboard EnigmaConfig::getPlugboard() {
    return this->plugboard;
}