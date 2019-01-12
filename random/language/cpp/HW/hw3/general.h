/*********************************************************************
  Author:        Jordan Winkler, IUSB, CS
                 Dana Vrajitoru, IUSB, CS
                 W. Knight, IUSB, CS
  Class:         C243 Data Structures
  File name:     general.h
  Last updated:  September 2017
  Description:   Some useful general purpose functions.
**********************************************************************/

#ifndef GENERAL_H
#define GENERAL_H

#include <cstdlib> //for baackwards compatability

/******************  T E S T   A L L O C A T I O N  *******************

This utility function accepts as an argument a pointer of any type 
whatsoever. It tests the pointer "p" to see whether it is NULL, and 
if it is, the function terminates the program with an error message 
saying "dynamic allocation failed."  If "p" is not NULL, the function 
does nothing.  This function is NOT a member of a class.  Documented 
and coded by W. Knight.  */ 
void testAllocation(void *p);

// swap two integers
void swap(int &a, int &b);

// Clears the terminal screen.
void clearScreen();

#endif
