#include "includes.hpp"

char Reflector::map(char c) {
    return TOCHAR(TOINT(c) + REFLECTOR_OFFSET);
}
