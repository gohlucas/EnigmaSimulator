#pragma once

#include "AlphabetMappings.h"

// Maps incoming signal to a paired output and sends it back through the rotor 
// Consists of 13 two way pairings
class Reflector: public AlphabetMappings {
private:
    std::unordered_map<int ,int> alphabetMap;
    bool isInitialised;
public:
    // Initialises 13 two way pairings
    Reflector();
    // Insert individual mappings of alphabets X->A etc
    bool insert(int, int);
    // Retrieve individual mapping for encryption
    int getMapping(int);
    // Initialise mappings based on user input
    bool configureMapping(std::string);
    // Confirm if the mapping is valid before configuring
    bool validateMapping(std::string);
    // Confirm if initialised properly
    bool isValid(void);
};