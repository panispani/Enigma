#ifndef __PLUGBOARD_HPP
#define __PLUGBOARD_HPP

class Plugboard : public Encryptor, public Configurable {
    vector<int> char_wire;
public:
    Plugboard();
    /*
     * Reset plugboard so that everything is
     * wired to itself
     */
    void reset();
    /*
     * Map input character according to wirings
     */
    virtual char map(char c);
    /*
     * Connect character with index (0-based) from
     * to character with index (0-based) to
     */
    virtual void connect(int from, int to);
};

#endif
