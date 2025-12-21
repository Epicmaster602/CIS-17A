#include "Prob1Random.h"
#include <cstdlib>

using namespace std;

// Constructor
Prob1Random::Prob1Random(const char n, const char *arr)
{
    nset = n;
    numRand = 0;

    set = new char[nset];
    freq = new int[nset];

    for (int i = 0; i < nset; i++)
    {
        set[i] = arr[i];
        freq[i] = 0;
    }
}

// Destructor
Prob1Random::~Prob1Random(void)
{
    delete [] set;
    delete [] freq;
}

// Returns a random value from the set
char Prob1Random::randFromSet(void)
{
    int idx = rand() % nset;
    freq[idx]++;
    numRand++;
    return set[idx];
}

// Returns frequency array
int *Prob1Random::getFreq(void) const
{
    return freq;
}

// Returns the set
char *Prob1Random::getSet(void) const
{
    return set;
}

// Returns total number of random calls
int Prob1Random::getNumRand(void) const
{
    return numRand;
}
