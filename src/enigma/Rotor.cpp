#include "Rotor.h"
#include "Alphabet.h"
#include <algorithm>
#include <cctype>
#include <set>

// rotate -> forward pass -> backward pass

Rotor::Rotor(std::string alphabetStr, int notch) {
    bool isValid = validateMapping(alphabetStr);
    if (!isValid) {
        printf("Failure\n");
    }
    alphabetOrder = configureMapping(alphabetStr);
    notchPos = notch;
}

bool Rotor::validateMapping(std::string alphabets) {
    std::set<int> seen;

    int leng = alphabets.length();
    if (leng != 26) {
        return false;
    }

    std::transform(alphabets.begin(), alphabets.end(), alphabets.begin(),
        [](unsigned char c) { return std::toupper(c); });
    
    // ensure that no duplicate mappings A<->X and A<->B
    // (a rotor's wiring only needs to be a bijection - unlike the plugboard
    // and reflector, a rotor is allowed to wire a letter to itself; real
    // Enigma rotors, e.g. Rotor I's S->S, do this)
    for (int i = 0; i < 26; i++) {
        char x = alphabets.at(i);
        if (seen.contains(x)) {
            printf("Error, duplicate mappings found\n");
            return false;
        }
        seen.insert(x);
    }
    return true;
}

std::unordered_map<int, int> Rotor::configureMapping(std::string alphabets) {
    std::unordered_map<int, int> umap;
    std::transform(alphabets.begin(), alphabets.end(), alphabets.begin(),
        [](unsigned char c) { return std::toupper(c); });

    for (int i = 0; i < 26; i++) {
        char n = alphabets.at(i);
        int mappedChar = Alphabet::charToInt(n);
        umap.insert({i, mappedChar});
    }
    return umap;
}

bool Rotor::Rotate(void) {
    offset = (offset + 1) % 26;
    return offset == notchPos;
}

// returns output character in ASCII format
int Rotor::forwardPass(int character) {
    int inputSignal = (character + offset) % 26;
    int wired = alphabetOrder.at(inputSignal);
    return (wired - offset + 26) % 26;
}

int Rotor::backwardPass(int character) {
    int inputSignal = (character + offset) % 26;

    // find the backwards path to get the output: look up which input
    // position wires to inputSignal (i.e. invert the forward mapping)
    auto it = std::find_if(alphabetOrder.begin(), alphabetOrder.end()
    , [&](std::pair<int, int> element){ return element.second == inputSignal; });

    if (it == alphabetOrder.end()) {
        return - 1;
    }
    return (it->first - offset + 26) % 26;
}

bool Rotor::isValid() {
    return notchPos != -1;
}
