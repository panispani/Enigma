#ifndef __ENIGMA_HPP
#define __ENIGMA_HPP

class Enigma {
    unique_ptr<Plugboard> plugboard;
    unique_ptr<Rotor_Box> rotorbox;
    stringstream in;
    stringstream out;
    void input();
    void encrypt();
    void output();
public:
    Enigma();
    void setup(list<string> rotorfiles, string plugfile);
    void operate();
};

#endif
