#include <iostream>
#include <math.h>
using namespace std;

/****************************************************************
| Name: stringToInt
|    
| Precodition: <iostream>, <stdlib> ,<math.h> used
| Postcondition: gives back a positive integer that the user typed
|
| Parameters:
|       
|   IN:  char* string
|   Out: none
|   
| Returns: an int from the user
\****************************************************************/
int stringToInt(char* input) 
//char* assumed to come from main argv which has a lot of space on it
{
    /* for flag if number is too big for current architexture */
    const int arrayMax = int(log10(pow(2, sizeof(int)*8))+1); 

    int Rows = 0;

    /* get size of input array, minus null terminator */
    int arraySize = 0;
    while (input[arraySize++] != '\0'); 
    arraySize--;
    
    if (arraySize > arrayMax)
    {
        cout << "\nSmaller number please\n";
        exit(1);
    }

    /* transfer to int */
    /* if negative */
    if (input[0] == '-')
    {
        for (int i = 1 ; input[i] != '\0' ; i++)
        {
            if (input[i] <= '9' && input[i] >= '0')
            {
                Rows += int(input[i] - '0');
                Rows *= 10; 
            }
            else 
            {
                cout << "\nError: non-number\n";
                exit(1);
            }
        }
        Rows /= 10;
        Rows *= -1;
        return Rows;
    }
    /* if positive */
    for (int i = 0 ; input[i] != '\0' ; i++)
    {
        if (input[i] <= '9' && input[i] >= '0')
        {
            Rows += int(input[i] - '0');
            Rows *= 10; 
        }
        else 
        {
            cout << "\nError: non-number\n";
            exit(1);
        }
    }
    return Rows /= 10;
}

/****************************************************************
| Name: breakIntoPrimes
|    
| Precodition: <iostream>, <stdlib.h>, an int array, and a number
|              to test
| Postcondition: an array of primes from the tested number
|
| Parameters:
|       
|   IN: int CompositeNumber, int max
|   Out: int array
|   
| Returns: nothing
\****************************************************************/
void breakIntoPrimes(int CompositeNumber, int A[], int MAX)
{
    for (int i = 0 ; i < MAX ; i++) //clean the array
        A[i] = 0;
    
    int j = 0;
    for (int i = 2 ; i <= CompositeNumber ; i++)
    {
        if (CompositeNumber % i == 0)
        { 
            A[j++] = i;
            CompositeNumber /= i;
            i--; // reset for multiple primes
        }
        if (j == MAX)
        {
            cout << "Error: too many primes\n";
            exit(1);
        }
    }
}

int main (int argc, char** argv)
{

    if (argc != 2)
    {
        cout << "breakIntoPrimes [n]\n";
        return 1;
    }

    const int MAX = 50;
    int prim[MAX] = {0};

    int CompositeNumber = stringToInt(argv[1]);
    breakIntoPrimes(CompositeNumber, prim, MAX);

    for (int i = 0 ; i < MAX ; i++)
        if (prim[i] != 0)
            cout << prim[i] << ' ';

    cout << endl;

    return 0;
}
