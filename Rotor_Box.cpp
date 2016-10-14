#include "includes.hpp"

Rotor_Box::Rotor_Box() {}

// argument correction
void Rotor_Box::setup(list<string> rotorfiles) {
    for (string rotorfile: rotorfiles) {
        Rotor rotor;
        rotor.setup(rotorfile);
        rotors.push_back(rotor);
    }
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
    // turn_next

    return c;
}
