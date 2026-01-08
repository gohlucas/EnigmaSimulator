#include "RotorHolder.h"
#include "Rotor.h"

void RotorHolder::setRotor(Rotor& rotor, int position){
    switch(position) {
        case 1:
            Rotor1 = rotor;
            break;
        case 2:
            Rotor2 = rotor;
            break;
        case 3:
            Rotor3 = rotor;
            break;
        default:
            printf("Error\n");
            break;
    }
    if (Rotor1.isValid() && Rotor2.isValid() && Rotor3.isValid()) {
        isInitialised = true;
    }
}
void RotorHolder::rotate() {
    bool hasReceivedSignalFrom1 = Rotor1.Rotate();
    bool hasReceivedSignalFrom2 = false;
    if (hasReceivedSignalFrom1) {
        hasReceivedSignalFrom2 = Rotor2.Rotate();
    }
    if (hasReceivedSignalFrom2) {
        Rotor3.Rotate();
    }
}

int RotorHolder::forwardEncrypt(int character) {
    int firstRotorForward = Rotor1.forwardPass(character);
    int SecondRotorForward = Rotor2.forwardPass(firstRotorForward);
    int thirdRotorForward = Rotor3.forwardPass(SecondRotorForward);
    return thirdRotorForward;
}

int RotorHolder::backwardEncrypt(int character) {
    int thirdRotorBackward = Rotor3.backwardPass(character);
    int SecondRotorBackward = Rotor2.backwardPass(thirdRotorBackward);
    int firstRotorBackward = Rotor1.backwardPass(SecondRotorBackward);
    return firstRotorBackward;
}
