#ifndef __ROTOR_BOX_HPP
#define __ROTOR_BOX_HPP

class Rotor_Box : public Encryptor {
    list<unique_ptr<Rotor>> rotors;
    unique_ptr<Reflector> reflector;
public:
    Rotor_Box();
    /*
     * Add input rotor to the list of rotors
     */
    void add(unique_ptr<Rotor>& rotor);
    /*
     * Map input character to another one
     * Use the rotors to make a forward pass
     * Then use the reflector
     * Then use the rotors to make a backward pass
     * Also rotate the rotors appropriately
     */
    virtual char map(char c);
};

#endif
