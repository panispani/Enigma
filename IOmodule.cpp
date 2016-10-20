#include "includes.hpp"
#define MIN_ARGS 2
#define FIRST_ROTOR_ARG 1
#define LAST_ROTOR_ARG (argc - 2)
#define PLUGBOARD_ARG (argc - 1)

void IOmodule::setup(int argc, char **argv) {
    assert(argc >= MIN_ARGS);
    unique_ptr<string> rfile;
    for (int  i = FIRST_ROTOR_ARG;
              i <= LAST_ROTOR_ARG;
              i++) {
        rfile.reset(new string(argv[i]));
        rfiles.push_back(move(rfile));
    }
    pfile.reset(new string(argv[PLUGBOARD_ARG]));
}

void IOmodule::setup_plugboard(unique_ptr<Plugboard>& plugboard) {
    ifstream fin(pfile->c_str());
    CHECKFILE(fin);
    int plugA;
    int plugB;
    plugboard->reset();
    while (fin >> plugA) {
        fin >> plugB;
        plugboard->connect(plugA, plugB);
    }
}

void IOmodule::setup_rotorbox(unique_ptr<Rotor_Box>& rotorbox) {
    for (auto rfile = rfiles.begin();
            rfile != rfiles.end();
            ++rfile) {
        ifstream fin((*rfile)->c_str());
        CHECKFILE(fin);
        unique_ptr<Rotor> rotor = move(unique_ptr<Rotor>(new Rotor));
        int pos;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            fin >> pos;
            rotor->connect(pos, i);
        }
        rotorbox->add(rotor);
    }
}

bool IOmodule::input(char &ch) {
    cin >> skipws;
    return (bool)(cin >> ch);
}

void IOmodule::output(char ch) {
    cout << ch;
}


