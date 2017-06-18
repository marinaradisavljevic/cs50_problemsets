#include <stdio.h>
#include <cs50.h>

 int promptHeight(void);
 void printHashes(int number);
 void printSpaces(int number);
 
int main(void) {
    
    bool condition = true;
    int height;
    while(condition) {
        height = promptHeight();
        if(height<0) {
        printf("Height cannot be a negative number. Try again\n");
        } else if(height>23) {
        printf("Height cannot exceed 23 rows. Try again\n");
        } else {
            condition = false;
        }
    }
    
    int numberOfSymbols = height+1;
    int numberOfHashes = 2;
    for(int i = 0; i<height; i++) {
        int hashes = numberOfHashes+i;
        printSpaces(numberOfSymbols-hashes);
        printHashes(hashes);
        printf("\n");
        
    }
}
    
    
    int promptHeight(void) {
        printf("Enter height in rows: ");
        int rows = get_int();
        return rows;
    }
    
    void printHashes(int number) {
        for(int i=0; i<number; i++) {
            printf("#");
        }
    }
    
    void printSpaces(int number) {
        for(int i=0; i<number; i++) {
            printf(" ");
        }
    }

    


