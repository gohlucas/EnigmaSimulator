#pragma once
#include <string>
#include <unordered_map>

// Rotates based on order of position
// First rotor rotates every key press
// Subsequent rotor rotates every full revolution of Previous Rotor
class Rotor {
   
public:
    std::unordered_map<int, int> alphabetOrder;
    int notchPos = -1;
    int offset = 0;

    Rotor() = default;
    Rotor(std::string, int);
    bool Rotate(void);
    int forwardPass(int);
    int backwardPass(int);
    bool isValid(void);
    bool validateMapping(std::string);
    std::unordered_map<int, int> configureMapping(std::string);
};
