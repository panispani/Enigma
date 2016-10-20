#ifndef __ENIGMA_HPP
#define __ENIGMA_HPP

class Enigma {
    unique_ptr<Plugboard> plugboard;
    unique_ptr<Rotor_Box> rotorbox;
    unique_ptr<IOmodule> iomodule;
public:
    Enigma();
    void setup(int argc, char **argv);
    void operate();
};

#endif
