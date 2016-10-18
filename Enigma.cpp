#include "includes.hpp"

void Enigma::setup(list<string> rotorfiles, string plugfile) {
    plugboard.setup(plugfile);
    rotor_box.setup(rotorfiles);
}

void Enigma::operate() {
    input();
    encrypt();
    output();
}

void Enigma::encrypt() {
    char ch;
    while (in >> ch) {
        CHECKCHAR(ch);
        ch = plugboard.map(ch);
        ch = rotor_box.map(ch);
        ch = plugboard.map(ch);
        out << ch;
    }
}

void Enigma::input() {
    string word;
    cin >> skipws; //is this needed
    while (cin >> word) {
        in << word;
    }
}

void Enigma::output() {
    cout << out.str() << endl;
}
