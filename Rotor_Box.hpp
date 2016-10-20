#ifndef __ROTOR_BOX_HPP
#define __ROTOR_BOX_HPP

class Rotor_Box : public Encryptor {
    list<unique_ptr<Rotor>> rotors;
    unique_ptr<Reflector> reflector;
public:
    Rotor_Box();
    void add(unique_ptr<Rotor>& rotor);
    virtual char map(char c);
};

#endif
