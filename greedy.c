#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    bool condition = true;
    
    while(condition) {
        printf("The change owed: ");
        float change = get_float();
        if(change<0) {
            printf("You cannot enter a negative value, please try again\n");
        } else {
            int changeInCents = round(change*100);
            int coins = 0;
            
            coins += changeInCents / 25;
            changeInCents = changeInCents % 25;
            
            coins += changeInCents / 10;
            changeInCents = changeInCents % 10;
            
            coins += changeInCents / 5;
            changeInCents = changeInCents % 5;
            
            coins += changeInCents / 1;
            
            printf("%i\n", coins);
            
            condition = false;
        }
        
    }
}