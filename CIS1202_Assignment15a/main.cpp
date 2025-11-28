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
    const int SIZE = 5;
    char startTestArray[SIZE] = {'a', 'a', 'Z', '?', 'A'};
    int offsetTestArray[SIZE] = {1, -1, -1, 5, 32};
    
    
    for(int i = 0; i < SIZE; ++i)
    {
        cout << "Test case #" << (i + 1) << ": ";
        
        try
        {
            cout << character(startTestArray[i], offsetTestArray[i]) << endl;
        }
        catch(Exceptions::invalidCharacterException)
        {
            cout << "ERROR: invalid character." << endl;
        }
        catch(Exceptions::invalidRangeException)
        {
            cout << "ERROR: invalid range." << endl;
        }
    }
    
    
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
