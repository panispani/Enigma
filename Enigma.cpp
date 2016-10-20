#include "includes.hpp"

Enigma::Enigma() {
    plugboard = move(unique_ptr<Plugboard>(new Plugboard));
    rotorbox = move(unique_ptr<Rotor_Box>(new Rotor_Box));
    iomodule = move(unique_ptr<IOmodule>(new IOmodule));
}

void Enigma::setup(int argc, char **argv) {
    iomodule->setup(argc, argv);
    iomodule->setup_plugboard(plugboard);
    iomodule->setup_rotorbox(rotorbox);
}

void Enigma::operate() {
    char ch;
    while (iomodule->input(ch)) {
        CHECKCHAR(ch);
        ch = plugboard->map(ch);
        ch = rotorbox->map(ch);
        ch = plugboard->map(ch);
        iomodule->output(ch);
    }
}
