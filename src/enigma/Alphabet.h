#pragma once

class Alphabet {
public:
    // Characters will always be valid when gui is up
    static int charToInt(char c) {
        return c - 'A';
    }
    static char intToChar(int i) {
        return i + 'A';
    }
};