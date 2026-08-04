#pragma once

#include "Rotor.h"
#include "RotorHolder.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "EnigmaConfig.h"
#include <string>

// Machine simulation to combine the various components
class EnigmaMachine {
    private:
        RotorHolder rotors;
        Reflector reflector;
        Plugboard plugboard;
        EnigmaConfig e;
    public:
        void setRotor(Rotor, Rotor, Rotor);
        void setReflector(Reflector);
        void setPlugboard(Plugboard);
        void run(void);
        void initialise(EnigmaConfig);
        int encrypt(char);
        void userInit(void);
        void createConfig(std::string, std::string, std::string, std::string, std::string);
};