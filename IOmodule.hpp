#ifndef __IOMODULE_HPP
#define __IOMODULE_HPP

class IOmodule {
    list<unique_ptr<string>> rfiles;
    unique_ptr<string> pfile;
public:
    /*
     * Save filenames for setting up the
     * plugboard and the rotors
     */
    void setup(int argc, char **argv);
    /*
     * Setup provided plugboard according to the
     * program arguments
     */
    void setup_plugboard(unique_ptr<Plugboard>& plugboard);
    /*
     * Setup provided rotor box by creating rotors
     * and adding them to it
     * Wiring of rotors is configured by the program
     * arguments
     */
    void setup_rotorbox(unique_ptr<Rotor_Box>& rotorbox);
    /*
     * Read next character
     * Return true if this succeeds, false otherwise
     * false return value indicates end of input
     */
    bool input(char &ch);
    /*
     * Output character
     */
    void output(char ch);
};

#endif
