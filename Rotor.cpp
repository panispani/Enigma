#include "includes.hpp"

Rotor::Rotor() {}

char Rotor::map(char c) {
    return char_wire[(c - 'A' + times_rotated[c - 'A']) % 26];
}

bool Rotor::turn_next() {
    int index = 0;
    while (times_rotated[index] == 26) {
    }
    return false;
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
