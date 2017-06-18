#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("Enter the number of minutes you spent showering: ");
    int minutes = get_int();
    printf("You used approx. %i bottles of water while taking the shower\n", minutes*192/16);
}