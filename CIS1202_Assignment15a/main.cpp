// Mollie Watkins
// CIS 1202 801
// November 27, 2025
// Driver program to test the character function

#include "Exceptions.h"
#include <iostream>
#include <cctype>


using namespace std;

char character(char, int);


// main
// Purpose: Uses an array of test cases to test the character function
// Parameters: None
// Returns: EXIT_SUCCESS to indicate a successful run
int main()
{
    const int SIZE = 5;
    int offsetTestArray[SIZE] = {1, -1, -1, 5, 32};
    char startTestArray[SIZE] = {'a', 'a', 'Z', '?', 'A'};

    
    for(int i = 0; i < SIZE; ++i)
    {
        cout << "Test case #" << (i + 1) << ": ";
        
        try
        {
            cout << character(startTestArray[i], offsetTestArray[i]) << endl;
        }
        catch(Exceptions::invalidCharacterException)
        {
            cout << "ERROR: Invalid character." << endl;
        }
        catch(Exceptions::invalidRangeException)
        {
            cout << "ERROR: Invalid range." << endl;
        }
    }
    
    
    cout << endl;
    return EXIT_SUCCESS;
}


// Name: character
// Purpose: Calculates a target character from the given parameters and validates that it falls within the allowed range
// Parameters:
//      start - the starting character used in the target calculation
//      offset - an int used in the target calculation
// Returns: The calculated character
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
