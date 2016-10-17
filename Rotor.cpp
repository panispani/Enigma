#include "includes.hpp"

Rotor::Rotor():times_rotated(0) {
    char_wire.resize(26);
    wire_char.resize(26);
}

char Rotor::rmap(char c) {
    return (wire_char[(c - 'A' + times_rotated + 26) % 26] - times_rotated + 26) % 26 + 'A';
}

char Rotor::map(char c) {
    return (char_wire[(c - 'A' + times_rotated) % 26] - times_rotated +26) % 26 + 'A';
}

bool Rotor::turn_next() {
    times_rotated = (times_rotated + 1) % 26;
    return times_rotated == 0;
}

// magic numbers
void Rotor::setup(string rotorfile) {
    ifstream fin(rotorfile.c_str());
    int pos;
    for (int i = 0; i < 26; i++) {
        fin >> pos;
        char_wire[i] = pos;
        wire_char[pos] = i;
    }
}
