#include "passwordgen.h"

// construtors:

Passwordgen::Passwordgen()
{
    length = 20;
    upper = true;
    lower = true;
    intergers = true;
    spec = true;
}

Passwordgen::Passwordgen(int len, bool up, bool lo, bool in, bool sp)
{
    length = len;
    upper = up;
    lower = lo;
    intergers = in;
    spec = sp;
}

// what this class is all about:

void Passwordgen::genPassword(std::string & str, int len)
{
    length = len;

    for (int i = 0; i < length; i++)        // actually this is bad code, it has to re-loop if the user doesn't want a certain criteria for his/her password :(
    {
        int val = genMaster(1, 4);
        if (val == 1 && upper == true)
            str += genRandUpper();
        else if (val == 1 && upper != true)
            i--;
        else if (val == 2 && lower == true)
            str += genRandLower();
        else if (val == 2 && lower != true)
            i--;
        else if (val == 3 && intergers == true)
            str += genRandInt();
        else if (val == 3 && intergers != true)
            i--;
        else if (val == 4 && spec == true)
            str += genRandSpec();
        else if (val == 4 && spec != true)
            i--;
    }
}

void Passwordgen::changeParameters(int len, bool up, bool lo, bool in, bool sp)
{
    length = len;
    upper = up;
    lower = lo;
    intergers = in;
    spec = sp;
}


/* ------------------ PRIVATE METHODS: -------------------- */


int Passwordgen::genMaster(int x, int y)
{
    // https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
    std::random_device rd;                         // only used once to initialise (seed) engine
    std::mt19937 rng(rd());                        // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(x,y);   // guaranteed unbiased
    return (int) uni(rng);
}

char Passwordgen::genRandUpper()
{
    return (char) genMaster(65, 90);
}

char Passwordgen::genRandLower()
{
    return (char) genMaster(97, 122);
}

char Passwordgen::genRandInt()
{
    return (char) genMaster(48, 57);
}

char Passwordgen::genRandSpec()
{
    int val = genMaster(1, 2);
    if (val == 1)
        return '!';
    else
        return '?';
}
