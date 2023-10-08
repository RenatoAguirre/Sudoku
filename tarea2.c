
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
                printf("0 ");
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

}
void read_specific_line(char *file_name, int line_number, char *result_line)
{   
    //lee una linea especifica del archivo, denuevo sabemos que sera de 9x9 caracteres;
    //recibimos un puntero string para almacernar el resultado final
    //lo recibimos para poder manejar la memoria desde afuera de la funcion
    FILE *file;
    int max_characters = 83;
    //83 es el max de characters que queremos leer,
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

int main()
{
    char matrix[100] = "";
    read_specific_line("puzles.txt", 10, matrix);
    printf("%s", matrix); 
    show_sudoku(matrix);

}