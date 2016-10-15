#include "includes.hpp"

Plugboard::Plugboard() {
    char_wire.resize(26);
    for (int i = 0; i < 26; i++) {
        char_wire[i] = i;
    }
}

// erase
void Plugboard::connect(int i, int j) {}

char Plugboard::map(char c) {
    return char_wire[c - 'A'] + 'A';
}

// correct arguments
void Plugboard::setup(string plugfile) {
    ifstream fin(plugfile.c_str());
    int plugA;
    int plugB;
    while (fin >> plugA) {
        fin >> plugB;
        char_wire[plugA] = plugB;
        char_wire[plugB] = plugA;
    }
}
