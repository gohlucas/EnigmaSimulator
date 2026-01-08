#pragma once

#include <unordered_map>
#include <string>

// Abstract class for Plugboard and Reflector to represent Mapping of Alphabets
class AlphabetMappings {
public:
    std::unordered_map<int ,int> alphabetMap;

    virtual bool insert(int, int);
    virtual int getMapping(int);
    virtual bool configureMapping(std::string);
    virtual bool validateMapping(std::string);
    virtual ~AlphabetMappings() = default;
};
