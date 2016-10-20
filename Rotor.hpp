#ifndef __ROTOR_HPP
#define __ROTOR_HPP

class Rotor : public Encryptor, public Configurable {
    /*
     * Times rotated each rotor
     */
    bool rev_map;
    int times_rotated;
    vector<int> wire_to;
    vector<int> wire_from;
public:
    Rotor();
    virtual char map(char c);
    virtual void connect(int from, int to);
    bool turn_next();
};

#endif
