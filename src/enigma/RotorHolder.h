// Holds the 3 rotors and passes signal to subsequent rotor to rotate once the previous rotor spun 1 full revolution
#include "Rotor.h"

// Holds the 3 Rotors and signals subsequent rotors to rotate
class RotorHolder {
private:
// need a function to set the rotor ring setting
    Rotor Rotor1;
    Rotor Rotor2;
    Rotor Rotor3;
    bool isInitialised = false;
public:
    void setRotor(Rotor&, int);
    void rotate(void);
    int forwardEncrypt(int);
    int backwardEncrypt(int);
    bool isValid(void);
};