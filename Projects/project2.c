#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

void matrix(char[][3]);
void title();
int win(char[][3]);
int draw(char[][3]);
void plrMode(char[][3],char*,char*);
void comMode(int[][3],char[][3],char*,int);
int computer(int[][3],char[][3],int,int*,int);

int main()
{
    int num,rep=49,flag=1,evil;
    char p1[20], p2[20];          
    while (rep==49)
    {
        x:
        evil=0;
        char pos[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }; //for display matrix
        int com[3][3] = { {2,2,2},{2,2,2},{2,2,2} }; //for computer matrix
        title();
        printf("1.Play with Player.\n");
        printf("2.Play with Smart Computer.\n");
        printf("3.Play with Evil Computer.\n");
        printf("4.Exit\n");
        if(!flag)
            printf("\nInvalid Choice");
        printf("\nEnter your choice: ");
        scanf("%d",&num);
        fflush(stdin);
        flag=1;
        switch (num)
        {
        case 1: 
            plrMode(pos,p1,p2);
            break;
        case 2:
            comMode(com,pos,p1,evil);
            break;
        case 3:            
            evil=1;
            comMode(com,pos,p1,evil);
            break;
        case 4:
            exit(0);
        default:
            flag=0;
            system("cls");
            goto x;
        }
        printf("\n**********************************************\n");
        printf("Press 1 to play again: ");
        rep = getch();
        system("cls");
    }  
    return 0;
}

//Matrix Area to play
void matrix(char mat[][3])
{
    int i,j,x;
    int size=3;//For 3x3 Matrix
    int col,num;
    for (i=0; i<size*3; i++)
    {
        x=0;
        col=8;
        for (j=0; j<size*8; j++)
        {
            if(j==col)
            {                
                printf("|");
                col+=8;
            }
            else if(((i+1)%3==0) && (j!=col) && (i+1!=size*3))
                printf("_");
            else if((i==1 || i==4 || i==7) && (j==4 || j==12 || j==20))
            {
                printf("%c",mat[i/3][x]);
                x++;
            }
            else
                printf(" ");
        }
        printf("\n");
    }    
}

void title()
{    
    printf("\t -------------------\n");
    printf("\t| Smart Tic Tac Toe |\n");
    printf("\t -------------------\n\n");
}

//Vs Player Mode
void plrMode(char mat[][3],char *p1,char *p2)
{
    int num=0,row,col,plr=0,i,flag=1; 
    
    system("cls");            
    title(); 
    printf("Enter First Player Name: ");
    fflush(stdin);
    gets(p1);
    printf("\nEnter Second Player Name: ");
    gets(p2);
    while(1)
    {
        i=0;
        system("cls");
        title();
        printf("GAME MODE: PLAYER VS PLAYER\n\n");         
        printf("%s: O\n%s: X\n\n\n",p1,p2);    
        matrix(mat);        
        printf("\n\n**********************************************\n");
        if(win(mat))
        {
            plr=!plr;
            if(plr==0)
                printf(" %s Win!",p1);
            else                
                printf(" %s Win!",p2);
            break;
        }
        if(draw(mat))
        {
            printf(" Game Draw!");
            break;
        }
        
        if(!flag)
            printf(" Invalid position to mark!\n");

        if(plr==0)
            printf(" %s: ",p1);
        else
            printf(" %s: ",p2);

        scanf("%d",&num);
        fflush(stdin);
        flag=1;

        if(num<1 || num>9)
            flag=0;

        for(row=0; row<3; row++)
        {
            for(col=0; col<3; col++)
            {
                i++; //running position to match with entered number
                if(i==num)
                {                   
                    if(mat[row][col]!='O' && mat[row][col]!='X')
                    {
                        if(plr==0)
                            mat[row][col] = 'O';
                        else
                            mat[row][col] = 'X';
                        plr=!plr;
                        break; 
                    }
                    else
                        flag=0;           
                }                
            }
        }
    }
}

//Vs Computer Mode
void comMode(int com[][3],char mat[][3],char *p1,int evil)
{
    
    int num,plr=0,flag=1;  
    system("cls");            
    title(); 
    printf("Enter Player Name: ");
    fflush(stdin);
    gets(p1);  
    while(1)
    {
        system("cls");
        title();
        if(evil)
            printf("GAME MODE: PLAYER VS EVIL COMPUTER\n\n");    
        else
            printf("GAME MODE: PLAYER VS SMART COMPUTER\n\n");
        printf("%s: O\nComputer: X\n\n\n",p1);
        matrix(mat);
        printf("\n\n**********************************************\n");
        if(win(mat))
        {
            plr=!plr;
            if(plr==0)
                printf(" %s Win!",p1);
            else                
                printf(" Computer Win!");
            break;
        }
        if(draw(mat))
        {
            printf(" Game Draw!");
            break;
        }
        if(!flag)
            printf(" Invalid position to mark!\n");
        
        printf(" %s: ",p1);
        plr = computer(com,mat,plr,&flag,evil);
    }
}

int computer(int com[][3],char mat[][3],int plr,int *f,int evil)
{
    int num,row,col,i=0,selRow,selCol,mul=1,max=1,flag=1;
    
    //Run on players chance
    if(!plr)
    {        
        scanf("%d",&num);
        fflush(stdin);
        *f=1;
        if(num<1 || num>9)
            *f=0;
        for(row=0; row<3; row++)
        {
            for(col=0; col<3; col++)
            {
                i++;
                if(i==num)
                {    
                    if(mat[row][col]!='O' && mat[row][col]!='X')
                    {
                        mat[row][col]='O';
                        com[row][col]=1;
                        return !plr;
                    }  
                    else
                        *f=0;                              
                } 
            }
        }
    }
    else //Run on computers chance
    {
        //To check if computer is winning
        for(row=0; row<3; row++)
        {
            for(col=0; col<3; col++)
            {
                if(com[row][col]==2)
                {
                    com[row][col]=3;
                    mul = com[row][0]*com[row][1]*com[row][2];
                    if(mul==27)
                    {
                        mat[row][col]='X';
                        return !plr;
                    }
                    else if(max<mul)
                    {
                        max=mul;
                        selRow = row;
                        selCol = col;
                    }  
                    mul = com[0][col]*com[1][col]*com[2][col];
                    if(mul==27)
                    {
                        mat[row][col]='X';
                        return !plr;
                    }
                    else if(max<mul)
                    {
                        max=mul;
                        selRow = row;
                        selCol = col;
                    }
                    if(row==col)
                    {
                        mul = com[0][0]*com[1][1]*com[2][2];
                        if(mul==27)
                        {
                            mat[row][col]='X';
                            return !plr;
                        }
                    }
                    else if(max<mul)
                    {
                        max=mul;
                        selRow = row;
                        selCol = col;
                    }
                    if ((row==0 && col==2) || (row==1 && col==1) || (row==2 && col==0))
                    {
                        mul = com[0][2]*com[1][1]*com[2][0];
                        if(mul==27)
                        {
                            mat[row][col]='X';
                            return !plr;
                        }
                    } 
                    else if(max<mul)
                    {
                        max=mul;
                        selRow = row;
                        selCol = col;
                    }                    
                    com[row][col]=2;          
                }
            }
        }

        //To check if player is winning
        for(row=0; row<3; row++)
        {
            for(col=0; col<3; col++)
            {
                if(com[row][col]==2)
                {
                    com[row][col]=3;
                    mul = com[row][0]*com[row][1]*com[row][2];
                    if(mul==3)
                    {
                        mat[row][col]='X';
                        if(!evil)
                            return !plr;
                        else
                        {
                            flag=0;
                            break;
                        }
                    }  
                    mul = com[0][col]*com[1][col]*com[2][col];
                    if(mul==3)
                    {
                        mat[row][col]='X';
                        if(!evil)
                            return !plr;
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(row==col)
                    {
                        mul = com[0][0]*com[1][1]*com[2][2];
                        if(mul==3)
                        {
                            mat[row][col]='X';
                            if(!evil)
                                return !plr;
                            else
                            {
                                flag=0;
                                break;
                            }
                        }
                    }
                    if ((row==0 && col==2) || (row==1 && col==1) || (row==2 && col==0))
                    {
                        mul = com[0][2]*com[1][1]*com[2][0];
                        if(mul==3)
                        {
                            mat[row][col]='X';
                            if(!evil)
                                return !plr;
                            else
                            {
                                flag=0;
                                break;
                            }
                        }
                    }
                    com[row][col]=2;
                }      
            }
        }
        
        //To mark on max winning place if both not winning
        if(flag)
        {
            mat[selRow][selCol]='X';
            com[selRow][selCol]=3;
        }
        return !plr;
    }
    
    return plr;
}

//Winning condition check
int win(char mat[][3])
{
    int row=0,col=0;

    for(row=0; row<3; row++)
        if(mat[row][0] == mat[row][1] && mat[row][1] == mat[row][2])
            return 1;

    for(col=0; col<3; col++)
        if(mat[0][col] == mat[1][col] && mat[1][col] == mat[2][col])
            return 1;

    if(mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2])
        return 1;

    if(mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
        return 1;
         
    return 0;
}

//Game draw condition check
int draw(char mat[][3])
{
    int i,j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(mat[i][j]!='X' && mat[i][j]!='O')
                return 0;
                
    return 1;
}