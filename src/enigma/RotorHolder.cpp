// Holds the 3 rotors and passes signal to subsequent rotor to rotate once the previous rotor spun 1 full revolution
#include "Rotor.h"

class RotorHolder {
private:
    Rotor Rotor1;
    Rotor Rotor2;
    Rotor Rotor3;
public:
    void setRotor(Rotor& rotor, int position){
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
    }
    void rotate() {
        bool hasReceivedSignalFrom1 = Rotor1.Rotate();
        bool hasReceivedSignalFrom2 = false;
        if (hasReceivedSignalFrom1) {
            hasReceivedSignalFrom2 = Rotor2.Rotate();
        }
        if (hasReceivedSignalFrom2) {
            Rotor3.Rotate();
        }
    }

};