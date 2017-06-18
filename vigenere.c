#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, string argv[]) {
    
    //check if the main received exactly 2 arguments through the command line, if not, return 1 as error with a message to the user
    if(argc != 2) {
        printf("Invalid number of arguments\n");
        return 1;
    }
    
    //retrieve the second argument and its length
    string key = argv[1];
    int keyLength = strlen(key);
    
    // check if the argument contains something other than letters. If so, display an error message and return 1.
    for (int i = 0; i<keyLength; i++) {
        if (!isalpha(key[i])) {
            printf("The second argument can contain only letters.\n");
            return 1;
        }
    }
    
    // create an array that will hold the keys
    int keyValues[keyLength];
    
    // match each letter of the key with its numeric value and place that value in the key array
    for (int i = 0; i < keyLength; i++) {
        char c = toupper(key[i]);
        
        switch(c) {
            case 'A':
            keyValues[i] = 0;
            break;
            
            case 'B':
            keyValues[i] = 1;
            break;
            
            case 'C':
            keyValues[i] = 2;
            break;
            
            case 'D':
            keyValues[i] = 3;
            break;
            
            case 'E':
            keyValues[i] = 4;
            break;
            
            case 'F':
            keyValues[i] = 5;
            break;
            
            case 'G':
            keyValues[i] = 6;
            break;
            
            case 'H':
            keyValues[i] = 7;
            break;
            
            case 'I':
            keyValues[i] = 8;
            break;
            
            case 'J':
            keyValues[i] = 9;
            break;
            
            case 'K':
            keyValues[i] = 10;
            break;
            
            case 'L':
            keyValues[i] = 11;
            break;
            
            case 'M':
            keyValues[i] = 12;
            break;
            
            case 'N':
            keyValues[i] = 13;
            break;
            
            case 'O':
            keyValues[i] = 14;
            break;
            
            case 'P':
            keyValues[i] = 15;
            break;
            
            case 'Q':
            keyValues[i] = 16;
            break;
            
            case 'R':
            keyValues[i] = 17;
            break;
            
            case 'S':
            keyValues[i] = 18;
            break;
            
            case 'T':
            keyValues[i] = 19;
            break;
            
            case 'U':
            keyValues[i] = 20;
            break;
            
            case 'V':
            keyValues[i] = 21;
            break;
            
            case 'W':
            keyValues[i] = 22;
            break;
            
            case 'X':
            keyValues[i] = 23;
            break;
            
            case 'Y':
            keyValues[i] = 24;
            break;
            
            case 'Z':
            keyValues[i] = 25;
            break;
        }
    }
    
    //retrieve the text to encrypt from the user and its length
    printf("plaintext: ");
    string plain = get_string();
    int plainLength = strlen(plain);
    
    printf("ciphertext: ");
    
    //initialize two counters: one to iterate over the plain text and the other to keep track of the position to use in the key array
    for (int i = 0, j = 0; i < plainLength; i++) {
        char c = plain[i];
        // if c is not a letter, cipherC will have the same value
        char cipherC = c;
        int shift;
        
        // check if c is a letter
        if (isalpha(c)) {
            // check if j is within the bounds of the keyValues array range. If not, calculate the shift with modulo
            if (j >= keyLength) {
                shift = keyValues[j % keyLength];
            } else {
                shift = keyValues[j];
            }
            
            // check if c is a capital or a small letter
            if (c >= 'A' && c <= 'Z') {
                //check if c + shift exceeds the numerical values for capital letters. If so, encrypted value should become the number by which the sum exceeds 90 added to the first letter in the series: 'A'
                if (c + shift > 90) {
                    cipherC = 'A' + ((c + shift) - 91);
                } else {
                    cipherC = c + shift;
                }
             
            } else if (c >= 'a' && c <= 'z') {
                //check if c + shift exceeds the numerical values for small letters. If so, encrypted value should become the number by which the sum exceeds 122 added to the first letter in the series: 'a'
                if (c + shift > 122) {
                    cipherC = 'a' + ((c + shift) - 123);
                } else {
                    cipherC = c + shift;
                }
            
            }
            j++;
        }
        //print the encrypted value
        printf("%c", cipherC);
    }
            
    //print a new line after encryption
    printf("\n");
    //return 0 to signal that the execution went as expected
    return 0;
}