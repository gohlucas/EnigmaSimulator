#include "Reflector.h"
#include "Alphabet.h"

Reflector::Reflector() {
    for (int i = 0; i < 26; i+=2) {
        insert(i, i + 1);
        insert(i + 1, i);
    }
    isInitialised = false;
}

bool Reflector::insert(int character, int mapping) {
    int charPair = getMapping(character);
    int mapPair = getMapping(mapping);
    
    alphabetMap.erase(character);
    alphabetMap.erase(charPair);

    alphabetMap.erase(mapping);
    alphabetMap.erase(mapPair);

    alphabetMap.insert({character, mapping});
    alphabetMap.insert({mapping, character});
    alphabetMap.insert({charPair, mapPair});
    alphabetMap.insert({mapPair, charPair});
    return true;
}

int Reflector::getMapping(int character) {
    auto search = alphabetMap.find(character);
    int res = (search == alphabetMap.end()) ? -1 : search->second;
    return res;    
}

bool Reflector::configureMapping(std::string alphabets) {
    bool isValid = validateMapping(alphabets);
    if (!isValid) {
        return false;
    }
    std::transform(alphabets.begin(), alphabets.end(), alphabets.begin(),
        [](unsigned char c) { return std::toupper(c); });

    for (int i = 0; i < 26; i++) {
        char n = alphabets.at(i);
        int mappedChar = Alphabet::charToInt(n);
  
        if (mappedChar > i) {
            Reflector::insert(i, mappedChar);
        }
    }
    isInitialised = true;
}

bool Reflector::validateMapping(std::string alphabets) {
    
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
        char x = alphabets.at(mappedChar);
        int other = Alphabet::charToInt(x);
        if (x != i) {
            return false;
        }
    }
}

bool Reflector::isValid() {
    return isInitialised;
}

