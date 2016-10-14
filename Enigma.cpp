#include "includes.hpp"

// move to setup
Enigma::Enigma(list<string> rotorfiles, string plugfile) {
    cout << -1 << endl;
    plugboard.setup(plugfile);
    cout << 0 << endl;
    rotor_box.setup(rotorfiles);
    cout << 0.0 << endl;
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
