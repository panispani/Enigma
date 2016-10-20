#ifndef __ENCRYPTOR_HPP
#define __ENCRYPTOR_HPP

/*
 * Encryptors take a character as an input
 * and map it to another one
 */
class Encryptor {
    /*
     * Maps a character to another one
     */
    virtual char map(char c) = 0;
};

#endif
