#include "includes.hpp"

// move to setup
Enigma::Enigma(list<string> rotorlist, string plugsetup) {
    plugboard.setup(plugsetup);
    rotor_box.setup(rotorlist);
}

void Enigma::setup() {
}

void Enigma::operate() {
    input();
    encrypt();
    output();
}

void Enigma::encrypt() {
    char ch;
    while (in >> ch) {
        ch = plugboard.map(ch);
        out << rotor_box.map(ch);
    }
}

void Enigma::input() {
    string word;
    while (cin >> word) {
        in << word;
    }
}

void Enigma::output() {
    cout << out.str();
}
