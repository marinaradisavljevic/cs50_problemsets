/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // if the array is empty, value is definitely not there
    if(n<1) {
        return false;
    }
    
    // define an index to perform binary search
    int length;
    
    // if the array size is an odd number, add 1 to it before dividing it in two to assign to the length variable
    if(n%2==0) {
        length = n/2;
    } else {
        length = (n+1)/2;
    }
    // make sure that length is within the bounds of the array
    while(length > -1 && length < n) {
        if(value == values[length]) {
            return true;
        } else if(value < values[length]) {
            length = length/2;
        } else if(value>values[length]) {
            // if length is 1, it will keep adding 0 to length in an infinte loop. In that case, return false and break the loop.
            if(length==1) {
                return false;
            } else {
                length = length + length/2;
            }
            
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i = 0; i < n-1; i++) {
        // set the minimum to the first checked value
        int min = values[i];
        for(int j = i+1; j<n; j++) {
            // check the rest of the array. If another element is < min, make it the new minimum and swap their places
            if(min > values[j]) {
                min = values[j];
                values[j] = values[i];
                values[i] = min;
            }
        }
    }
    return;
}
