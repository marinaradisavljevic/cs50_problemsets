#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void) {
    // takes user's input
    string name = get_string();
    
    // checks that the input is not NULL
    if (name != NULL) {
        // prints the first initial
        printf("%c", toupper(name[0]));
        
        // iterates over the given string checking for a space. when it finds it, prints the next letter as an initial
        for(int i=0, n=strlen(name); i<n; i++) {
            if(name[i] == ' ') {
                printf("%c", toupper(name[i+1]));
            }
        }
        // adds a new line
        printf("\n");
    }
    else {
        printf ("You must enter a valid string");
    }
}

