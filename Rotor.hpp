#ifndef __ROTOR_HPP
#define __ROTOR_HPP

class Rotor : public Encryptor {
    /*
     * Times rotated each rotor
     */
    int times_rotated;
    vector<int> char_wire;
    vector<int> wire_char;
public:
    Rotor();
    void setup(string rotorfile);
    virtual char map(char c);
    char rmap(char c);
    bool turn_next();
};

#endif
