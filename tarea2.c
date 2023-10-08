
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printMatriz(char* matriz)
{
    // funcion para printear el sudoku, sabemos que siempre sera de 9x9 
    int rows = 9;
    int cols = 9;
    
    //printf("--------------------------\n");
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
            printf("%c ", matriz[(j+(rows*i))-1]);
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
    /* 
    ) || (j == 1)
    for(int i = 0; i<n; i++)
    {
        for(int j = 1; j<n+1; j++)
        {
            printf("a: %d ", (j));
            printf("b: %d ", (j+(9*i))-1);
            printf("c: %d \n", (i));

        }
    }*/
    printf("--------------------------");
    printf("\n%s", matriz);
    printf("\n%c", matriz[0]);
    printf("\n%d", strlen(matriz));
    printf("\n%p", *matriz);


}


int main()
{
    char matriz[100] = "000200000060107400000060008000000100000010040000008000000000000000032000003890000";
    printMatriz(matriz);

}