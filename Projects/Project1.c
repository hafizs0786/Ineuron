#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

void title();
void rules();
void matrix(int[][4]);
void showMat(int[][4]);
int winner(int[][4]);
void swap(int*,int*);
int shiftUp(int[][4]);
int shiftDown(int[][4]);
int shiftLeft(int[][4]);
int shiftRight(int[][4]);
int enteredKey();

int main()
{   
    int key,i,j,k=1,mat[4][4], moves; 
    char rep=49,player[20];
    while (rep==49)
    {
        moves=200;
        title();
        printf("\nEnter your name: ");
        gets(player);
        system("cls");

        rules();           
        matrix(mat);

        while(1)
        {
            title();
            printf("\nPlayer Name: %s, Moves Remaining: %d\n\n",player,moves);

            showMat(mat);     
            if(winner(mat))
            {
                printf("\nCongratulations! %s you win.",player);
                break;
            }
            if(!moves)
            {
                printf("\nSorry! no more moves left. Better luck next Time.");
                break;
            }            
            printf("\nUse arrow keys to move: "); 
            key=enteredKey();

            switch (key)
            {
                case 49: 
                    for(i=0; i<4; i++)  
                    {
                        for(j=0; j<4; j++)  
                        {
                            mat[i][j] = k;
                            k++;
                        }
                    }
                    mat[i-1][j-1] = 0;
                    k=1;
                    break;  
                case 69: //ASCII code of 'e'            
                case 101: //ASCII code of 'E'
                    printf("\n\nThanks for Playing !");
                    printf("\nPress any key to exit the game \n");
                    getch();
                    return 0;
                case 72:
                    if(shiftUp(mat))
                        moves--;
                    break;      
                case 75:
                    if(shiftLeft(mat))
                        moves--;
                    break;   
                case 77:
                    if(shiftRight(mat))
                        moves--;
                    break;   
                case 80:
                    if(shiftDown(mat))
                        moves--;
                    break;   
                default:
                    break;
            }
            system("cls");
        }
        printf("\n\nPress 1 to play again\n");
        rep = getch();        
        system("cls");
    }
    
    return 0;
}

void title()
{
    printf("\t\t -------------------\n");
    printf("\t\t|   Matrix Puzzle   |\n");
    printf("\t\t -------------------\n\n");
}

//Game Rules
void rules()
{
    int i,j,k=1;
    title();
    printf("\nGAME RULES : \n");
    printf("\n\t1. You can move only 1 step at a time by using arrow keys");
    printf("\n\t   Move Up    :  by Up arrow key");
    printf("\n\t   Move Down  :  by Down arrow key");
    printf("\n\t   Move Left  :  by Left arrow key");
    printf("\n\t   Move Right :  by Right arrow key");
    printf("\n\n\t2. You can move numbers at an empty position only.");
    printf("\n\t3. For each valid move : your total number of moves will decrease by 1.");
    printf("\n\t4. You can exit the game at any time by pressing 'E' or 'e'.");
    
    printf("\n\nWINNING SITUATION");
    printf("\n\n\tNumber in a 4x4 matrix should be in order from 1 to 15\n");
    
    printf("\t -------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("\t| ");
        for (j = 0; j < 4; j++)
            if (k != 16)            
                printf("%2d | ",k++);
            else
                printf("   |");
        printf("\n"); 
    }       
    printf("\t -------------------\n");

    printf("\n\tTry to win in minimum number of moves.");
    printf("\n\nPress any key to start the game: ");
    getch();
    system("cls");
}

//To create matrix with random
void matrix(int mat[][4])
{
    int n=15 ,num[n];
    int k=1,i,j;
    for(i=0; i<15; i++)
        num[i] = i+1;

    srand(time(NULL));
    int lastIndex = n - 1, index;

    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
        {
            if(lastIndex >=0)
            {
                index = rand() % (lastIndex + 1);
                mat[i][j] = num[index];
                num[index] = num[lastIndex--];
            }
        }
    mat[i-1][j-1] = 0;
}

//To print matrix
void showMat(int mat[][4])
{
    int i,j;
    printf(" -------------------\n");
    for(i=0; i<4; i++)
    {
        printf("|");
        for(j=0; j<4; j++)
            if(mat[i][j]!=0)
                printf(" %2d |",mat[i][j]);
            else
                printf("    |");
        printf("\n");
    }
    printf(" -------------------\n");
}

//To check if player win or not
int winner(int mat[][4])
{
    int i,j,k=1;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++,k++)
            if(mat[i][j]!=k && k!=16)
                return 0;
    
    return 1;
}

//To swap values
void swap(int *x,int *y)
{    
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//To Shift Up
int shiftUp(int mat[][4])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(mat[i][j]==0)
                break;
        if(j<4)
            break;
    }

    if(i==0)
        return 0;
    
    swap(&mat[i][j],&mat[i-1][j]);
    return 1;
}

//To Shift Down
int shiftDown(int mat[][4])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(mat[i][j]==0)
                break;
        if(j<4)
            break;
    }

    if(i==3)
        return 0;
    
    swap(&mat[i][j],&mat[i+1][j]);
    return 1;
}

//To Shift Left
int shiftLeft(int mat[][4])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(mat[i][j]==0)
                break;
        if(j<4)
            break;
    }

    if(j==0)
        return 0;

    swap(&mat[i][j],&mat[i][j-1]);
    return 1;
}

//To ShiftRight
int shiftRight(int mat[][4])
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
            if(mat[i][j]==0)
                break;
        if(j<4)
            break;
    }

    if(j==3)
        return 0;

    swap(&mat[i][j],&mat[i][j+1]);
    return 1;
}

//To get key entered by value
int enteredKey()
{
    char k = getch();
    if(k!=0)
        return k;
    return getch();
}