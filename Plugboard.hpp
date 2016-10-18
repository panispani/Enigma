#ifndef __PLUGBOARD_HPP
#define __PLUGBOARD_HPP

class Plugboard : public Encryptor {
    vector<int> char_wire;
    void init_plugboard();
public:
    Plugboard();
    virtual char map(char c);
    void setup(string plugfile);
};

#endif
