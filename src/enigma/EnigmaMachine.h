#pragma once

#include "Rotor.h"
#include "RotorHolder.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "EnigmaConfig.h"

// Machine simulation to combine the various components
class EnigmaMachine {
    private:
        RotorHolder rotors;
        Reflector reflector;
        Plugboard plugboard;
    public:
        void setRotor(Rotor, Rotor, Rotor);
        void setReflector(Reflector);
        void setPlugboard(Plugboard);
        void run(void);
        void initialise(EnigmaConfig);
        int encrypt(char);
        void userInit(void);
};