#include "includes.hpp"

char Reflector::map(char c) {
    int index = c - 'A';
    return (index + 13) % 26 + 'A';
}
