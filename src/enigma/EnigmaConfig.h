#pragma once

#include "Rotor.h"
#include "RotorHolder.h"
#include "Reflector.h"
#include "Plugboard.h"
#include <vector>

// Stores configuration which Machine can revert to
class EnigmaConfig {
    private:
        RotorHolder rotors;
        Reflector reflector;
        Plugboard plugboard;

    public:
        EnigmaConfig() = default;
        EnigmaConfig(Plugboard&, Reflector&, Rotor&, Rotor&, Rotor&);
        void setRotor(Rotor&, Rotor&, Rotor&);
        void setReflector(Reflector&);
        void setPlugboard(Plugboard&);
        RotorHolder getRotors(void);
        Reflector getReflector(void);
        Plugboard getPlugboard(void);
};