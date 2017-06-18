/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int tile = d *d - 1;
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            board[i][j] = tile;
            tile--;
        }
    }
    // switch positions of 1 and 2 if the board has an odd number of elements
    if(d%2 == 0) {
        board[d-1][d-2] = 2;
        board[d-1][d-3] = 1;
    }
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            if(board[i][j] < 10 && board[i][j] > 0) {
                printf("%2i ", board[i][j]);
            } else if(board[i][j] == 0) {
               printf("   "); 
            } else {
                printf("%i ", board[i][j]);
            }
            
            
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int tileRow;
    int tileColumn;
    int zeroRow;
    int zeroColumn;
    // loop through the array to find row and column of the tile (if it is in the array), and of the 0 element
    for(int i = 0; i < d; i++) {
        for(int j = 0; j < d; j++) {
            if(board[i][j] == tile) {
                tileRow = i;
                tileColumn = j;
            }
            if(board[i][j] == 0) {
                zeroRow = i;
                zeroColumn = j;
            }
        }
    }
    // if the tile is in the same row as the 0 element and it is to its left or right, swap their places. If they are in the same column and adjacent rows, do the swap.
    if((tileRow == zeroRow && tileColumn == zeroColumn-1) || (tileRow == zeroRow && tileColumn == zeroColumn + 1)) {
        board[zeroRow][zeroColumn] = tile;
        board[tileRow][tileColumn] = 0;
        return true;
    } else if ((tileColumn == zeroColumn && tileRow == zeroRow-1) || (tileColumn == zeroColumn && tileRow == zeroRow + 1)) {
        board[zeroRow][zeroColumn] = tile;
        board[tileRow][tileColumn] = 0;
        return true;
    }
    // the tile is not in the array
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // check that tiles form a sequence of numbers starting with 1 and ending with d*d - 1.
    int n = 1;
    for(int i = 0; i<d; i++) {
        for(int j = 0; j < d; j++) {
            // the last element on the board should be zero
            if(i == d-1 && j == d-1) {
                if(board[i][j] != 0) {
                    return false;
                }
            } else {
                if(board[i][j] != n) {
                    return false;
                }
            }
            n++;
        }
    }
    return true;
}
