#ifndef ROTOR_H
#define ROTOR_H
#include <unordered_map>

// do array then offset, when enter the char converted to index then will switch to that number
// then offset for curr rotor and then pass to next rotor, once curr offset hits 26 then modulo 
// back to 0 and next rotor offset ++
class Rotor {
   
public:
    std::unordered_map<int, int> alphabetOrder;
    int notchPos = -1;
    int offset = 0;

    Rotor(std::unordered_map<int, int>, int);
    bool Rotate(void);
    int forwardPass(int);
    int backwardPass(int);
    bool isInitialised(void);
};
#endif