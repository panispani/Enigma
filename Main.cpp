#include "includes.hpp"

int main(int argc, char **argv)
{
    unique_ptr<Enigma> enigma(new Enigma);
    enigma->setup(argc, argv);
    enigma->operate();
    return 0;
}
