#include "Plugboard.h"
#include "Alphabet.h"
#include <algorithm>
#include <cassert>
#include <cctype>

Plugboard::Plugboard() {
    // Populate directly rather than via insert(): insert() asserts that
    // both characters already have a mapping, which isn't true yet while
    // the map is still empty during construction.
    for (int i = 0; i < 26; i++) {
        alphabetMap[i] = i;
    }
    isInitialised = false;
}

// Remove existing mapping and create a new link between the 2 characters to simulate connecting a cable across
bool Plugboard::insert(int character, int mapping) {
    int charPair = getMapping(character);
    assert(charPair != -1);
    int mapPair = getMapping(mapping);
    assert(mapPair != -1);
    
    // This condition covers
    // (character<->mapping exists already) which contains (character = mapping and character<->character)
    if (charPair == mapping && mapPair == character) {
        return true;
    }
    // remove existing mappings
    alphabetMap.erase(character);
    alphabetMap.erase(mapping);
    alphabetMap.erase(charPair);
    alphabetMap.erase(mapPair);

    // Insert the new pairing first: unordered_map::insert() is a no-op if
    // the key already exists, so the new pairing must go in before the
    // old-partner restoration below, otherwise it can be silently blocked
    // whenever a letter's old partner was itself (the common unplugged case).
    alphabetMap.insert({character, mapping});
    alphabetMap.insert({mapping, character});

    alphabetMap.insert({charPair, charPair});
    alphabetMap.insert({mapPair, mapPair});

    return true;
}

int Plugboard::getMapping(int character) {
    auto search = alphabetMap.find(character);
    int res = (search == alphabetMap.end()) ? -1 : search->second;
    return res;    
}

bool Plugboard::configureMapping(std::string alphabets) {
    bool isValid = validateMapping(alphabets);
    if (!isValid) {
        return false;
    }

    std::transform(alphabets.begin(), alphabets.end(), alphabets.begin(),
        [](unsigned char c) { return std::toupper(c); });

    for (int i = 0; i < 26; i++) {
        char n = alphabets.at(i);
        int mappedChar = Alphabet::charToInt(n);
        if (i == mappedChar) {
            continue;
        }
        char x = alphabets.at(mappedChar);
        int other = Alphabet::charToInt(x);
    
        if (mappedChar > i) {
            Plugboard::insert(i, mappedChar);
        }
    }

    isInitialised = true;
    return true;
}

// takes string of 26 unique alphabets and creates the mappings
bool Plugboard::validateMapping(std::string alphabets) {
    int leng = alphabets.length();
    if (leng != 26) {
        printf("Error, string does not contain exactly 26 mappings\n");
        return false;
    }

    std::set<char> seen;

    std::transform(alphabets.begin(), alphabets.end(), alphabets.begin(),
        [](unsigned char c) { return std::toupper(c); });
    
    for (int i = 0; i < 26; i++) {
        char x = alphabets.at(i);
        if (seen.contains(x)) {
            printf("Error, duplicate mappings found\n");
            return false;
        }
        seen.insert(x);
    }
    
    for (int i = 0; i < 26; i++) {
        char n = alphabets.at(i);
        int mappedChar = Alphabet::charToInt(n);
        if (i == mappedChar) {
            continue;
        }
        char x = alphabets.at(mappedChar);
        int other = Alphabet::charToInt(x);
        if (other != i) {
            return false;
        }
    }
    return true;
}

bool Plugboard::isValid() {
    return isInitialised;
}

