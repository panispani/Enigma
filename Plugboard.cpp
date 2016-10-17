#include "includes.hpp"

Plugboard::Plugboard() {
    char_wire.resize(ALPHABET_SIZE);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char_wire[i] = i;
    }
}

char Plugboard::map(char c) {
    return TOCHAR(char_wire[TOINT(c)]);
}

void Plugboard::setup(string plugfile) {
    ifstream fin(plugfile.c_str());
    CHECKFILE(fin);
    int plugA;
    int plugB;
    while (fin >> plugA) {
        fin >> plugB;
        char_wire[plugA] = plugB;
        char_wire[plugB] = plugA;
    }
}
