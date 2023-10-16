#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void show_sudoku(char* matrix)
{
    // funcion para printear el sudoku, sabemos que siempre sera de 9x9 
    int rows = 9;
    int cols = 9;
    
    printf("\n");
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

int check_move(char *sudoku, int index)
{   //retorna 1 si es jugada valida, 0 en caso contrario
    int number_at_index = sudoku[index] - '0';
    if (number_at_index == 0)
    {
        return 1;
    }
    return 0;
}

int is_valid_sudoku(char *sudoku) 
{
    /* 
     creamos una matriz donde vamos a ir guardando los numeros
     que ya vimos, luego simplemente checkeamos si ya lo vimos
     se van guardando de la sgte manera:
     rows[row][numero] = 1 si ya se vio, 0 de lo contrario
     esta fuuncion, solo sirve para ver si la sgte movida es valida
     para chekear la completitud del sudoku no hay q tomar en cuenta los 0
     por lo tanto habra q hacer otra funcion. 
    */
    int rows[9][10] = {0}; 
    int columns[9][10] = {0}; 
    int boxes[9][10] = {0}; //estas son las casillas de 3x3

    for (int i = 0; i < 81; i++) 
    {
        int row = i / 9;
        int col = i % 9;
        char cell = sudoku[i];

        if (cell >= '1' && cell <= '9') 
        {
            int num = cell - '0'; //para tranformar el char del string a int

            if (rows[row][num] || columns[col][num] || boxes[row / 3 * 3 + col / 3][num]) {
                return 0;
            }

            rows[row][num] = 1;
            columns[col][num] = 1;
            boxes[row / 3 * 3 + col / 3][num] = 1;
        }
    }
    return 1; //si llego hasta aca, es valido
}
//Funcion para remplzar los nmero en nuestro sudoku
void do_move(char *sudoku, int row, char col, char number)
{   
    int index = row_col_to_string_index(row, col);
    sudoku[index] = number;
}

int is_valid_move(char *sudoku, int row, char col, char number)
{   
    char new_sudoku[81] = "";
    strcpy(new_sudoku, sudoku);
    
    //int index = row_col_to_string_index(row, col);
    do_move(new_sudoku, row, col, number);

    if (is_valid_sudoku(new_sudoku))
    {
        return 1;
    }
    return 0;
}
int is_sudoku_complete(char *sudoku)
{   
    //chekeamos si el sudoku es valido, y si no contiene ceros es porque esta completo
    if (is_valid_sudoku(sudoku))
    {
        for (int i = 0; i < 81; i++)
        {
            if (sudoku[i] == '0')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{   
    int n = 81;
    char *sudoku = malloc((n+1)*sizeof(char));
    read_specific_line("puzles.txt", 4, sudoku);

    char original_sudoku[100] = "";
    strcpy(original_sudoku, sudoku);

    while (1)
    {   
        
        show_sudoku(sudoku);
        

        //recibimnos la columna 
        char col;
        printf("\nIngrese columna (a/i) (x para salir), (o para mostrar sudoku original): ");
        scanf(" %c", &col);
        col = toupper(col);

        if (col == 'X')
        {
            break;
        }
        if (col == 'O')
        {
            show_sudoku(original_sudoku);
            continue;
        }
        
        //recibimos row
        int row = 0;
        printf("\nIngrese numero de fila (1/9): ");
        scanf(" %d", &row);

        //recibimos numero
        char number = ' ';
        printf("numero? (0 para borrar): ");
        scanf(" %c", &number);
        
        //si la jugada es valida se hace
        if (is_valid_move(sudoku, row, col, number))
        {
            do_move(sudoku, row, col, number);
        }
        else
        {
            printf("\nJugada no valida... \n");
        }

        //checkeamos si se ganó 
        if (is_sudoku_complete(sudoku))
        {
            printf("\n FELICIDADES, GANASTE!! \n");
            break;
        }
    }
         
    free(sudoku);
}