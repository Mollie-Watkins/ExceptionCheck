// Mollie Watkins
// CIS 1202 801
// November 27, 2025

#include <iostream>
#include "Exceptions.h"

using namespace std;


char character(char, int);


// Name:
// Purpose:
// Parameters:
// Returns:
int main()
{
    
    
    
    return EXIT_SUCCESS;
}


// Name:
// Purpose:
// Parameters:
// Returns:
char character(char start, int offset)
{
    char    target = start + offset,
            validMin,
            validMax;
    
    
    // Valid range determination
    if(!isalpha(start))
    {
        throw Exceptions::invalidCharacterException{};
    }
    else if(isupper(start))
    {
        validMin = 'A';
        validMax = 'Z';
    }
    else
    {
        validMin = 'a';
        validMax = 'z';
    }
    
    
    // Target value check
    if(target < validMin || target > validMax)
    {
        throw Exceptions::invalidRangeException{};
    }
    
    
    return target;
}
