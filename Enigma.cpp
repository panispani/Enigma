#include "includes.hpp"

// move to setup
Enigma::Enigma(list<string> rotorfiles, string plugfile) {
    plugboard.setup(plugfile);
    rotor_box.setup(rotorfiles);
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
        ch = rotor_box.map(ch);
        out << ch;
    }
}

void Enigma::input() {
    string word;
    while (cin >> word) {
        // cosider reading whitespace or in << word << " ";
        in << word;
    }
}

void Enigma::output() {
    cout << out.str() << endl;
}
