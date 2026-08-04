#include "EnigmaMachine.h"
#include "Alphabet.h"
#include <iostream>
#include <string>

// Leaves room for setting individually next time
void EnigmaMachine::setRotor(Rotor r1, Rotor r2, Rotor r3) {
    rotors.setRotor(r1, 1);
    rotors.setRotor(r2, 2);
    rotors.setRotor(r3, 3);
}

void EnigmaMachine::setReflector(Reflector r) {
    reflector = r;
}

void EnigmaMachine::setPlugboard(Plugboard p) {
    plugboard = p;
}

void EnigmaMachine::run() {
    if (!(rotors.isValid() && reflector.isValid() && plugboard.isValid())) {
        printf("Error, configuration not initialised\n");
    }
    char input;
    char output;
    std::string inputStr;
    std::string outputStr;
    std::cout << "Type characters and press enter to stop:\n";

    while(std::cin.get(input)) {
        if (input == '\n') {
            break;
        }
        inputStr += input;
        output = Alphabet::intToChar(encrypt(input));
        outputStr += output;
    }
    printf("Here was the user provided input: %s", inputStr.c_str());
    printf("Here is the generated output: %s", outputStr.c_str());
}

void EnigmaMachine::initialise(EnigmaConfig e) {
    this->rotors = e.getRotors();
    this->reflector = e.getReflector();
    this->plugboard = e.getPlugboard();
}

int EnigmaMachine::encrypt(char c) {
    // Rotors step once per keypress, before the signal passes through them
    this->rotors.rotate();

    int input = Alphabet::charToInt(c);
    int plugboard1 = this->plugboard.getMapping(input);
    int rotorsForward = this->rotors.forwardEncrypt(plugboard1);
    int reflector = this->reflector.getMapping(rotorsForward);
    int rotorsBackward = this->rotors.backwardEncrypt(reflector);
    int plugboard2 = this->plugboard.getMapping(rotorsBackward);
    return plugboard2;
}

void EnigmaMachine::createConfig(std::string plugboard, std::string reflector, std::string rotor1, std::string rotor2, std::string rotor3) {
    Plugboard p = Plugboard();
    p.configureMapping(plugboard);

    Reflector r = Reflector();
    r.configureMapping(reflector);

    Rotor r1 = Rotor(rotor1, 0);

    Rotor r2 = Rotor(rotor2, 0);

    Rotor r3 = Rotor(rotor3, 0);

    EnigmaConfig e = EnigmaConfig(p, r, r1, r2, r3);
    this->e = e;
    // Load the freshly built config so the machine is immediately usable
    this->initialise(this->e);
}

void EnigmaMachine::userInit() {
    std::string plugboardConfig, reflectorConfig, rotorConfig1, rotorConfig2, rotorConfig3;

    std::cout << "Follow the instructions below to initialise the machine before" << '\n';
    std::cout << "usage, else the program will crash. Each configuration requires 26 characters." << '\n';
    std::cout << "These configurations have to be entered in alphabetical order" << '\n';
    std::cout << "For example, \"XQZ\" means that A->X, B->Q and C->Z" << '\n';
    
    std::cout << "Enter plugboard configuration: "; 
    std::getline(std::cin, plugboardConfig);

    std::cout << "Enter reflector configuration: "; 
    std::getline(std::cin, reflectorConfig);

    std::cout << "Enter rotor 1 configuration: "; 
    std::getline(std::cin, rotorConfig1);

    std::cout << "Enter rotor 2 configuration: "; 
    std::getline(std::cin, rotorConfig2);

    std::cout << "Enter rotor 3 configuration: "; 
    std::getline(std::cin, rotorConfig3);

    EnigmaMachine::createConfig(plugboardConfig, reflectorConfig, rotorConfig1, rotorConfig2, rotorConfig3);

    std::cout << "Validating initialisation..." << '\n';
    std::cout << "Initialisation complete." << '\n';
}