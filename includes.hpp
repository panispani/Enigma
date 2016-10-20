#ifndef __INCLUDES_HPP
#define __INCLUDES_HPP

/*
 * Standard libraries
 */
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include <cassert>
#include <memory>

using namespace std;

/*
 * Header files
 */
#include "Configurable.hpp"
#include "Encryptor.hpp"
#include "Plugboard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Rotor_Box.hpp"
#include "IOmodule.hpp"
#include "Enigma.hpp"

/*
 * Useful macros
 */
#define ALPHABET_SIZE 26
#define TOINT(ch) (ch - 'A')
#define TOCHAR(n)\
    ((n + ALPHABET_SIZE) % ALPHABET_SIZE + 'A')
#define ROTATE(n, rot)\
    ((n + rot + ALPHABET_SIZE) % ALPHABET_SIZE)

#endif
