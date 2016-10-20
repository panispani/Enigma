#include "includes.hpp"

Rotor::Rotor():times_rotated(0) {
    wire_to.resize(ALPHABET_SIZE);
    wire_from.resize(ALPHABET_SIZE);
    rev_map = true;
}

char Rotor::map(char c) {
    rev_map = !rev_map;
    if (rev_map) {
        return TOCHAR(ROTATE(wire_from[ROTATE(TOINT(c), times_rotated)], -times_rotated));
    }
    return TOCHAR(ROTATE(wire_to[ROTATE(TOINT(c), times_rotated)], -times_rotated));
}

bool Rotor::turn_next() {
    times_rotated = (times_rotated + 1) % ALPHABET_SIZE;
    return times_rotated == 0;
}

void Rotor::connect(int from, int to) {
    wire_to[to] = from;
    wire_from[from] = to;
}

/*void Rotor::setup(string rotorfile) {
    ifstream fin(rotorfile.c_str());
    CHECKFILE(fin);
    int pos;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fin >> pos;
        wire_to[i] = pos;
        wire_from[pos] = i;
    }
}*/
