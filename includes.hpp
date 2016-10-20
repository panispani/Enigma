#ifndef __INCLUDES_HPP
#define __INCLUDES_HPP

/*
 * Standard libraries
 */
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cassert>
#include <memory>

using namespace std;

/*
 * Header files
 */
#include "Encryptor.hpp"
#include "Plugboard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Rotor_Box.hpp"
#include "Enigma.hpp"

/*
 * Useful macros
 */
#define CHECKFILE(fin)\
    if (!fin) {\
        cout << "Error: file not found" << endl;\
        exit(EXIT_FAILURE);\
    }

#define CHECKCHAR(ch)\
    if (ch < 'A' || ch > 'Z') {\
        cout << "Error: Invalid character" << endl;\
        exit(EXIT_FAILURE);\
    }

#define ALPHABET_SIZE 26
#define TOINT(ch) (ch - 'A')
#define TOCHAR(n)\
    ((n + ALPHABET_SIZE) % ALPHABET_SIZE + 'A')
#define ROTATE(n, rot)\
    ((n + rot + ALPHABET_SIZE) % ALPHABET_SIZE)

#endif
