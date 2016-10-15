#include "includes.hpp"

Rotor::Rotor():times_rotated(0) {
    char_wire.resize(26);
}

char Rotor::map(char c) {
    return char_wire[(c - 'A' + times_rotated) % 26];
}

bool Rotor::turn_next() {
    times_rotated = (times_rotated + 1) % 26;
    return times_rotated == 26;
}

// magic numbers
void Rotor::setup(string rotorfile) {
    ifstream fin(rotorfile.c_str());
    int pos;
    for (int i = 0; i < 26; i++) {
        cin >> pos;
        char_wire[i] = pos;
    }
}
