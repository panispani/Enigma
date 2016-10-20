#include "includes.hpp"

Plugboard::Plugboard() {
    char_wire.resize(ALPHABET_SIZE);
}

char Plugboard::map(char c) {
    return TOCHAR(char_wire[TOINT(c)]);
}

void Plugboard::reset() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char_wire[i] = i;
    }
}

void Plugboard::connect(int from, int to) {
    char_wire[from] = to;
    char_wire[to] = from;
}
