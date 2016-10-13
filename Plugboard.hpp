#ifndef __PLUGBOARD_HPP
#define __PLUGBOARD_HPP

class Plugboard : public Encryptor {
    vector<int> char_wire;
public:
    Plugboard();
    void connect(int i, int j);
    virtual char map(char c);
    void setup(string plugsetup);
};

#endif
