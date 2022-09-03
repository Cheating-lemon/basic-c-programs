#include<stdio.h>

void print_matrix(int matrix[10][10], int rows, int columns);
void transpose_mtx(int matrix[10][10], int rows, int columns);

int main()
{

    int rows, columns, Mtx[10][10];
    printf("Enter the order of the Matrix:");
    scanf("%dx%d",&rows,&columns);
    printf("Enter the Values of the Matrix: ");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%d",&Mtx[i][j] );
        }
    }
    printf("The given matrix is: \n");
    print_matrix(Mtx, rows, columns);
    printf("\nThe transpose of the Matrix is:\n");
    transpose_mtx(Mtx,rows,columns);
    print_matrix(Mtx,columns,rows);
    return 0;
}
//transposing a Matrix
void transpose_mtx(int matrix[10][10], int rows, int columns)
{
    int limit = rows-1;
    if (rows>columns)
        limit = columns-1;
    else if (rows<columns)
        limit = rows-1;
    
    //swaping the numbers 
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
             if (j>i && j<=limit)
             {
                matrix[i][j] = matrix[i][j] + matrix[j][i];
                matrix[j][i] = matrix[i][j] - matrix[j][i];
                matrix[i][j] = matrix[i][j] - matrix[j][i]; 
             }

             if (j>limit || i>limit)
                matrix[i][j] = matrix[j][i];
        }  
    }
} 

void print_matrix(int matrix[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d\t",matrix[i][j] );
        }
        printf("\n");  
    }
}