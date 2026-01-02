#include "Rotor.h"
// rotate -> forward pass -> backward pass

Rotor::Rotor(std::unordered_map<int, int> alphabetArr, int notch) 
: alphabetOrder(alphabetArr), notchPos(notch) {}

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

bool Rotor::isInitialised() {
    return notchPos != -1;
}
