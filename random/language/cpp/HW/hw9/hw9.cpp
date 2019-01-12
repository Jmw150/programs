/*
Jordan Winkler and Christian Sassano
CSCI-C243 (data structures)
hw 9 
last updated: Mon Nov 13 11:04:59 EST 2017

*/


//#define assembler


#include <iostream>
using namespace std;

#include <sys/time.h>

template<class t>
void quickSort(t arr[], int left, int right);

void asmSort(int arr[], int left, int right);

int main ()
{
    int size = 0;
    cout << "size of array -> ";
    cin >> size;
    
    int* array = new int[size];

    for (int i = 0 ; i < size ; i++)
    {
        cin >> array[i];
    }

    struct timeval before, after;
    double timing;
    gettimeofday(&before, 0);

    //function to time test
#ifndef assembler
    quickSort(array, 0, size);
#endif

#ifdef assembler
    asmSort(array, 0, size);
#endif
    //function end

    gettimeofday(&after, 0);
    timing = (double) ((double)after.tv_sec +
                       (double)after.tv_usec/(1000*1000)) -
             (double) ((double)before.tv_sec +
                       (double)before.tv_usec/(1000*1000));

    for (int i = 0 ; i < size ; i++)
        cout << array[i] << ' ';
    cout << endl;

    cout << "time: " << timing << endl;

    return 0;
}


/****************************************************************
| Name: quicksort
|    
| Precodition: an array; 
|               information on the begining and end of the array
| Postcondition: a sorted array
|
| Parameters:
|       
|   IN: array, int for start and end
|   Out: same array 
|   
| Returns: nothing
\****************************************************************/
template<class t>
void quickSort(t arr[], int left, int right) 
{
      int i = left, j = right;
      t tmp;

      /* minor improvement to performance */
      int pivot = arr[(left + right) / 2];
 
      /* prepare for partision and do swap */
      while (i <= j) 
      {
          while (arr[i] < pivot)
              i++;
          while (arr[j] > pivot)
              j--;
          if (i <= j) 
          {
              tmp = arr[i]; // swap inline instead of function call
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
          }
      };
 
      /* recursion step */
      if (left < j)
          quickSort(arr, left, j);
      if (i < right)
          quickSort(arr, left, j);
      if (i < right)
          quickSort(arr, i, right);
}

// if there is time for it, this is an x86 assembly environment
// to get a little more speed out of the computer.
// likely best to use something like merge sort
void asmSort(int arr[], int left, int right)
{
    asm(
        " "
    );

}
