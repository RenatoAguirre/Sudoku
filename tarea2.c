
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void show_sudoku(char* matrix)
{
    // funcion para printear el sudoku, sabemos que siempre sera de 9x9 
    int rows = 9;
    int cols = 9;
    
    printf("    A B C   D E F   G H I \n");
    
    for (int i = 0; i<rows; i++)
    {   
        if ((i) % 3 == 0)
        {
            printf("  -------------------------\n");
        }
        for (int j = 1; j<cols+1; j++)
        {   
            if (j == 1)
            {
                printf("%d | ", i+1);
            }
            if (matrix[(j+(rows*i))-1] == '0')
            {
                printf("  ");
            } 
            else
            {
                printf("%c ", matrix[(j+(rows*i))-1]);
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
    printf("  -------------------------\n");
    printf("\n");


}
void read_specific_line(char *file_name, int line_number, char *result_line)
{   
    //lee una linea especifica del archivo, denuevo sabemos que sera de 9x9 caracteres;
    //recibimos un puntero string para almacernar el resultado final
    //lo recibimos para poder manejar la memoria desde afuera de la funcion
    FILE *file;
    int max_characters = 83;
    //83 es el max de characters que queremos leer por cada linea,
    //81 de la matriz + \n

    file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("Error leyendo el archivo.");
    }
    for(int i = 0; i < line_number; i++)
    {
        fgets(result_line, max_characters, file); 
    }
    fgets(result_line, max_characters, file); //este ultimo para dejarlo almacenado
    fclose(file);
}

int row_col_to_string_index(int row, char col_char)
{  
    /*funcion que cambia la letra de una columna y numero de fila
       como por ejemplo 'a', 2 y la cambia por 0 
       ó por ejemplo b, 3 y da x*/
    char letters[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    
    for(int i = 0; i < 9; i++)
    {   
        //printf("");
        //printf("c: %c\n", letters[i]);
        //printf("b: %d\n", i);

        if (letters[i] == col_char)
        {
            return ((row - 1) * 9) + i;
        }
    }
    return -1; // si la columna no esta en la lista, retornamos -1 para simbolizar que hubo un error
}


int main()
{   
    int n = 81;
    char *sudoku = malloc((n+1)*sizeof(char));
    read_specific_line("puzles.txt", 4, sudoku);
    //printf("%s\n", sudoku);
    show_sudoku(sudoku);
    printf("x: %c\n", sudoku[row_col_to_string_index(8, 'I')]);
    
    free(sudoku);
}