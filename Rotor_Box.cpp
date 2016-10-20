#include "includes.hpp"

void Rotor_Box::add(Rotor rotor) {
    rotors.push_back(rotor);
}

char Rotor_Box::map(char c) {
    for (list<Rotor>::iterator it = rotors.begin();
            it != rotors.end();
            ++it) {
        c = it->map(c);
    }
    c = reflector.map(c);
    for (list<Rotor>::reverse_iterator it = rotors.rbegin();
            it != rotors.rend();
            ++it) {
        c = it->map(c);
    }
    bool turn_next = true;
    for (list<Rotor>::iterator it = rotors.begin();
            it != rotors.end() && turn_next;
            ++it) {
        turn_next = it->turn_next();
    }
    return c;
}
