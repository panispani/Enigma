#include "includes.hpp"

Rotor_Box::Rotor_Box() {
    reflector = move(unique_ptr<Reflector>(new Reflector));
}

void Rotor_Box::add(unique_ptr<Rotor>& rotor) {
    rotors.push_back(move(rotor));
}

char Rotor_Box::map(char c) {
    for (auto it = rotors.begin();
            it != rotors.end();
            ++it) {
        c = (*it)->map(c);
    }
    c = reflector->map(c);
    for (auto it = rotors.rbegin();
            it != rotors.rend();
            ++it) {
        c = (*it)->map(c);
    }
    bool turn_next = true;
    for (auto it = rotors.begin();
            it != rotors.end() && turn_next;
            ++it) {
        turn_next = (*it)->turn_next();
    }
    return c;
}
