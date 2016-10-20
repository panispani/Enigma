#include "includes.hpp"
#include "Plugboard.cpp"
#include "Rotor.cpp"
#include "Reflector.cpp"
#include "Rotor_Box.cpp"
#include "Enigma.cpp"
#include "IOmodule.cpp"

void read_args(int argc, char **argv, list<string> &rfiles, string &pfile) {
    assert(argc >= 2);
    for (int  i = 1; i < argc - 1; i++) {
        rfiles.push_back(argv[i]);
    }
    pfile = argv[argc - 1];
}

int main(int argc, char **argv)
{
    //list<string> rotorfiles;
    //string plugfile;
    //read_args(argc, argv, rotorfiles, plugfile);

    unique_ptr<Enigma> enigma(new Enigma);
    enigma->setup(argc, argv);
    enigma->operate();
    return 0;
}
