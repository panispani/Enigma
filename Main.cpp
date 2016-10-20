#include "includes.hpp"
#include "Plugboard.cpp"
#include "Rotor.cpp"
#include "Reflector.cpp"
#include "Rotor_Box.cpp"
#include "Enigma.cpp"
#include "IOmodule.cpp"

int main(int argc, char **argv)
{
    unique_ptr<Enigma> enigma(new Enigma);
    enigma->setup(argc, argv);
    enigma->operate();
    return 0;
}
