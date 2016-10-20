#include "includes.hpp"

Enigma::Enigma() {
    plugboard = move(unique_ptr<Plugboard>(new Plugboard));
    rotorbox = move(unique_ptr<Rotor_Box>(new Rotor_Box));
}
void Enigma::setup(list<string> rotorfiles, string plugfile) {
    plugboard->setup(plugfile);
    rotorbox->setup(rotorfiles);
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
        ch = plugboard->map(ch);
        ch = rotorbox->map(ch);
        ch = plugboard->map(ch);
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
