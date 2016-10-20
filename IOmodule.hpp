#ifndef __IOMODULE_HPP
#define __IOMODULE_HPP

class IOmodule {
    list<string> rfiles;
    string pfile;
public:
    void setup(int argc, char **argv);
    void setup_plugboard(unique_ptr<Plugboard>& plugboard);
    void setup_rotorbox(unique_ptr<Rotor_Box>& rotorbox);
    bool input(char &ch);
    void output(char ch);
};

#endif
