#pragma once

#include <unordered_map>
#include <string>
#include <set>

// Abstract class for Plugboard and Reflector to represent Mapping of Alphabets
class AlphabetMappings {
public:
    std::unordered_map<int ,int> alphabetMap;

    virtual bool insert(int, int) = 0;
    virtual int getMapping(int) = 0;
    virtual bool configureMapping(std::string) = 0;
    virtual bool validateMapping(std::string) = 0;
    virtual ~AlphabetMappings() = default;
};
