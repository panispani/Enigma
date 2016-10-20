#ifndef __PLUGBOARD_HPP
#define __PLUGBOARD_HPP

class Plugboard : public Encryptor, public Configurable {
    vector<int> char_wire;
    void init_plugboard();
public:
    Plugboard();
    void reset();
    virtual char map(char c);
    virtual void connect(int from, int to);
};

#endif
