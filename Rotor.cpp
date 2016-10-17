#include "includes.hpp"

Rotor::Rotor():times_rotated(0) {
    char_wire.resize(ALPHABET_SIZE);
    wire_char.resize(ALPHABET_SIZE);
    rev_map = true;
}

char Rotor::map(char c) {
    rev_map = !rev_map;
    if (rev_map) {
        return TOCHAR(ROTATE(wire_char[ROTATE(TOINT(c), times_rotated)], -times_rotated));
    }
    return TOCHAR(ROTATE(char_wire[ROTATE(TOINT(c), times_rotated)], -times_rotated));
}

bool Rotor::turn_next() {
    times_rotated = (times_rotated + 1) % ALPHABET_SIZE;
    return times_rotated == 0;
}

// magic numbers
void Rotor::setup(string rotorfile) {
    ifstream fin(rotorfile.c_str());
    CHECKFILE(fin);
    int pos;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fin >> pos;
        char_wire[i] = pos;
        wire_char[pos] = i;
    }
}
