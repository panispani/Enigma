#include "includes.hpp"

Plugboard::Plugboard() {
    char_wire.resize(ALPHABET_SIZE);
}

char Plugboard::map(char c) {
    return TOCHAR(char_wire[TOINT(c)]);
}

void Plugboard::init_plugboard() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char_wire[i] = i;
    }
}

void Plugboard::setup(string plugfile) {
    ifstream fin(plugfile.c_str());
    CHECKFILE(fin);
    int plugA;
    int plugB;
    init_plugboard();
    while (fin >> plugA) {
        fin >> plugB;
        char_wire[plugA] = plugB;
        char_wire[plugB] = plugA;
    }
}
