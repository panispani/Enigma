#include "includes.hpp"

Rotor::Rotor() {}

char Rotor::map(char c) {
    return char_wire[(c - 'A' + times_rotated) % 26];
}

// no need to be bool
bool Rotor::turn_next() {
    int index = 0;
    while (times_rotated[index] == 26) {
    }
    return false;
}

