#ifndef __ENIGMA_HPP
#define __ENIGMA_HPP

class Enigma {
    Plugboard plugboard;
    Rotor_Box rotor_box;
    void input();
    void encrypt();
    void output();
public:
    Enigma();
    void setup();
    void operate();
};

#endif
