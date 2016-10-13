#include "includes.hpp"
#include "Plugboard.cpp"
#include "Rotor.cpp"
#include "Reflector.cpp"
#include "Rotor_Box.cpp"
#include "Enigma.cpp"

int main(int argc, char **argv)
{
    // MAYBE EXPORT IN A FUNCTION
    assert(argc >= 2);
    int num_rotors = argc - 2;
    list<string> rotorlist;
    for (int  i = 1; i < argc - 1; i++) {
        rotorlist.push_back(argv[i]);
    }
    string plugsetup = argv[argc - 1];
    // MAYBE EXPORT IN A FUNCTION

    Enigma enigma(rotorlist, plugsetup);
    enigma.setup(); //erase later, think of common fucntion
    enigma.operate();
    cout << "all hail the lord" << endl;
    return 0;
}
