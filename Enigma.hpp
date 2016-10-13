#ifndef __ENIGMA_HPP
#define __ENIGMA_HPP

class Enigma {
    Plugboard plugboard;
    Rotor_Box rotor_box;
    stringstream in;
    stringstream out;
    void input();
    void encrypt();
    void output();
public:
    Enigma(list<string> rotorlist, string plugboard);
    void setup();
    void operate();
};

#endif
