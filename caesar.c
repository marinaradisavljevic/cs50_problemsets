
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, string argv[]) {
    
    //check if the main received exactly 2 arguments through the command line, if not, return 1 as error with a message to the user
    if(argc != 2) {
        printf ("Invalid command line input\n");
        return 1;
    }
    
    //retrieve the second argument and convert it to an int. Key will be the remainder of the division of the argument by 26 (number of letters in alphabet).
    string inputK = argv[1];
    int k = atoi(inputK);
    int shift = k % 26;
    
    //take user's input to ecrypt and retrieve its length
    printf("plaintext: ");
    string plaintext = get_string();
    int stringLength = strlen(plaintext);
    
    printf("ciphertext: ");
    for (int i = 0; i<stringLength; i++) {
        //if c is a space or a punctuation sign, don't encrypt it, otherwise, check if it's a capital or a small letter.
        char c = plaintext[i];
        char cipherC = c;
        if (c >= 'A' && c <= 'Z') {
            //check if c + key exceeds the numerical values for capital letters. If so, encrypted value should become the number by which the sum exceeds 90 added to the first letter in the series: 'A'
            if (c + shift > 90) {
                cipherC = 'A' + ((c + shift) - 91);
            } else {
                cipherC = c + shift;
            }
             
        } else if (c >= 'a' && c <= 'z') {
            //check if c + key exceeds the numerical values for small letters. If so, encrypted value should become the number by which the sum exceeds 122 added to the first letter in the series: 'a'
            if (c + shift > 122) {
                cipherC = 'a' + ((c + shift) - 123);
            } else {
                cipherC = c + shift;
            }
            
        }
        //print the encrypted value
        printf("%c", cipherC);
        
    }
    //print a new line after encryption
    printf("\n");
    //return 0 to signal that the execution went as expected
    return 0;
    
}