#ifndef __CONFIGURABLE_HPP
#define __CONFIGURABLE_HPP

/*
 * Configutable acts as an interface for
 * configurable components
 */
class Configurable {
    /*
     * Connects pins "from" and "to"
     */
    virtual void connect(int from, int to) = 0;
};

#endif
