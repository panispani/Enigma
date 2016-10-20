#ifndef __ROTOR_HPP
#define __ROTOR_HPP

class Rotor : public Encryptor, public Configurable {
    int times_rotated;
    bool rev_map;
    vector<int> wire_to;
    vector<int> wire_from;
public:
    Rotor();
    /*
     * Map input character to wired one
     * Treat differently forward and backward mapping
     * This is handled by using variable rev_map
     * as forward and backward mapping are alternating
     */
    virtual char map(char c);
    /*
     * Connect the character with index (0-based) from
     * to the character with index (0-based) to
     */
    virtual void connect(int from, int to);
    /*
     * Return true if the rotor did a full rotation
     * The next rotor would have to be rotated then
     */
    bool turn_next();
};

#endif
