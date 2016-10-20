#ifndef __ENIGMA_HPP
#define __ENIGMA_HPP

class Enigma {
    unique_ptr<Plugboard> plugboard;
    unique_ptr<Rotor_Box> rotorbox;
    unique_ptr<IOmodule> iomodule;
public:
    Enigma();
    /*
     * Setup the IOmodule which in turn will
     * setup the plugboard and the rotor box
     */
    void setup(int argc, char **argv);
    /*
     * Launch Enigma machine
     * Read input and encrypt it
     */
    void operate();
};

#endif
