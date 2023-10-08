
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printMatriz(char* matriz)
{
    // funcion para printear el sudoku, sabemos que siempre sera de 9x9 
    int rows = 9;
    int cols = 9;
    
    printf("    A B C   D E F   G H I \n");
    
    for(int i = 0; i<rows; i++)
    {   
        if ((i) % 3 == 0)
        {
            printf("  -------------------------\n");
        }
        for(int j = 1; j<cols+1; j++)
        {   
            if (j == 1)
            {
                printf("%d | ", i+1);
            }
            if (matriz[(j+(rows*i))-1] == '0')
            {
                printf("  ");
            } 
            else
            {
                printf("%c ", matriz[(j+(rows*i))-1]);
            }
            if (j % 3 == 0)
            {
                printf("| ");
            }           
            if ((j == cols) && (j != 1))
            {
                printf("\n");
            }           
        }
    }
}


int main()
{
    char matriz[100] = "000200000060107400000060008000000100000010040000008000000000000000032000003890000";
    printMatriz(matriz);

}