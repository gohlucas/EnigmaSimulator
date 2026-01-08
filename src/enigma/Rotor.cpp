#include "Rotor.h"
#include "Alphabet.h"
#include <set>

// rotate -> forward pass -> backward pass

Rotor::Rotor(std::string alphabetStr, int notch) {
    bool isValid = validateMapping(alphabetStr);
    if (!isValid) {
        printf("Failure\n");
    }
    alphabetOrder = configureMapping(alphabetStr);
}

bool Rotor::validateMapping(std::string alphabets) {
    std::set<int> seen;

    int leng = alphabets.length();
    if (leng != 26) {
        return false;
    }

    std::transform(alphabets.begin(), alphabets.end(), alphabets.begin(),
        [](unsigned char c) { return std::toupper(c); });
    
    for (int i = 0; i < 26; i++) {
        char n = alphabets.at(i);
        int mappedChar = Alphabet::charToInt(n);
        if (i == mappedChar) {
            return false;
        }
        auto search = seen.find(mappedChar);
        if (search != seen.end()) {
            return false;
        }
        seen.insert(mappedChar);
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
        umap.insert(i, mappedChar);
    }
    return umap;
}

bool Rotor::Rotate(void) {
    offset = (offset + 1) % 26;
    return offset == notchPos;
}

int Rotor::forwardPass(int character) {
    int inputSignal = (character + offset) % 26;
    return alphabetOrder.at(inputSignal);
}

int Rotor::backwardPass(int character) {
    int inputSignal = (character + offset) % 26;

    // find the backwards path to get the output
    auto it = std::find_if(alphabetOrder.begin(), alphabetOrder.end()
    , [&](std::pair<int, int> element){ return element.first == inputSignal; });

    if (it == alphabetOrder.end()) {
        return - 1;
    }
    return it->second;
}

bool Rotor::isValid() {
    return notchPos != -1;
}
