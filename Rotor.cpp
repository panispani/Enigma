#include "includes.hpp"

Rotor::Rotor():times_rotated(0) {
    wire_to.resize(ALPHABET_SIZE);
    wire_from.resize(ALPHABET_SIZE);
    rev_map = false;
}

char Rotor::map(char c) {
    int pos = ROTATE(TOINT(c), times_rotated);
    int match;
    if (rev_map) {
        match = wire_from[pos];
    } else {
        match = wire_to[pos];
    }
    rev_map = !rev_map;
    return TOCHAR(ROTATE(match, -times_rotated));
}

bool Rotor::turn_next() {
    times_rotated = (times_rotated + 1) % ALPHABET_SIZE;
    return times_rotated == 0;
}

void Rotor::connect(int from, int to) {
    wire_to[to] = from;
    wire_from[from] = to;
}
