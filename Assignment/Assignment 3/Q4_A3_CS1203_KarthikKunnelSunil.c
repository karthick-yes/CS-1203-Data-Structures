
#include <stdio.h>

void towerOfhanoi(int n, char fromrod, char torod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move the disk 1 from rod %c to rod %c", fromrod, torod);
        return;
    }
    towerOfhanoi(n - 1, fromrod, aux_rod, torod);
    printf("\n Move the disk %d from rod %c to rod %c", n, fromrod, torod);
    towerOfhanoi(n - 1, aux_rod, torod, fromrod);
}

int main()
{
    int n = 4; // Number of disks
    towerOfhanoi(n, 'L', 'N', 'M');  // L, M and N are names of rods
    return 0;
}



/*
 The state space is an 8x8 matrix, representing a chess board, where each queen can be placed in any arrangement as long as the total number of queens does not exceed 8.
The initial state is an empty chess board, with no queens placed on it.
The transition operator refers to the action of adding a new queen to an empty row on the board.
The goal state is achieved when 8 queens are placed on the board in such a way that they are all in non-attacking positions. This means that no two queens are in the same row, column, or diagonal line on the chess board.
 

 */


#include <stdio.h>
#define N 8

int board[N][N]; //chessboard

int is_attack(int i, int j)
{
    int k, l;
    //if there is a queen in a row or column
    for(k=0;k<N;k++)
    {
        if((board[i][k] == 1) || (board[k][j] == 1))
            return 1;
    }
    //also checking the diagonals
    for(k=0;k<N;k++)
    {
        for(l=0;l<N;l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int N_queen(int n)
{
    int i, j;
    //solution is found if n=0
    if(n==0)
        return 1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            //checking if one can place a queen here or not
            //queen can not be placed if the place is being attacked
            //or already occupied by.
            if((!is_attack(i,j)) && (board[i][j]!=1))
            {
                board[i][j] = 1;
                //recursion implementation
                //checks wether if one can put the next queen with this arrangement or not
                if(N_queen(n-1)==1)
                {
                    return 1;
                }
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    int i, j;
    //init elements to 0
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]=0;
        }
    }
    //function call
    N_queen(8);
    //printing the matix
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",board[i][j]);
        printf("\n");
    }

}
