#ifndef PASSWORDGEN_H
#define PASSWORDGEN_H

#include <random>
#include <string>

class Passwordgen
{
public:
    Passwordgen();
    Passwordgen(int len, bool up, bool lo, bool in, bool sp);
    //~Passwordgen();   // no need for this atm

    void genPassword(std::string & str, int len = 20);  // returns a string alocated with new, make sure to use delete later!
    void changeParameters(int len, bool up, bool lo, bool in, bool sp);

private:
    int genMaster(int x, int y);
    char genRandUpper();
    char genRandLower();
    char genRandInt();
    char genRandSpec();     // only use '?' and '!' atm because of "simplicity"!

    int length;

    bool upper;
    bool lower;
    bool intergers;
    bool spec;
};

#endif // PASSWORDGEN_H
