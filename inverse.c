#include<stdio.h>
#include<math.h>

//order_of_matrix = N
void get_minor_Mtx(int Mtx[10][10], int minor_Mtx[10][10], int N, int x, int y)
{
    for (int row = 0, i=0; row < N; row++)
    {
        for (int column = 0,j=0; column < N; column++)
        {
            if (row!=x && column!=y)
                minor_Mtx[i][j++] = Mtx[row][column];
            if (j == N-1)
                i++;
        }
    }
}

int determinant(int Mtx[10][10], int n)
{
    int D,sign;
    if (n == 1)
        D = Mtx[0][0];
    
    for (int column = 0; column < n; column++)
    {
        int minor_mtx[n][n];
        get_minor_Mtx(Mtx,minor_mtx, n ,0,column);
        D += pow(-1,column) * Mtx[0][column] * determinant(minor_mtx, n-1);
    }
    return D;     
}

void get_co_factor_Mtx(int Mtx[10][10], int co_factor_Mtx[10][10], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int minor_Mtx[N][N];
            get_minor_Mtx(Mtx,minor_Mtx,N,i,j);
            co_factor_Mtx[i][j] = pow(-1,i+j)*( determinant(minor_Mtx, N));
        }   
    }
}

void transpose(int Mtx[10][10], int N)
{
    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp = Mtx[i][j];
            Mtx[i][j] = Mtx[j][i];
            Mtx[j][i] = temp;
        } 
    } 
} 

void inverse(int Mtx[10][10], int IMtx[10][10], int N)
{
    int coFactor[10][10];
    get_co_factor_Mtx(Mtx,coFactor,N);
    transpose(coFactor,N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            IMtx[i][j] = (1/determinant(Mtx,N))* coFactor[i][j];
            printf("%d",determinant(Mtx,N));
        }
    }
}

void print_Matrix(int Mtx[10][10], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%f\t",Mtx[i][j] );
        }
        printf("\n");
    }
    
}

void main()
{
    int N,M;
    int Mtx[10][10], I[10][10];
    do
    {
        printf("Enter the order of the 'square' Matrix(RxC): ");
        scanf("%dx%d",&N,&M);
    } while (M!=N);
    printf("Enter the values of the Matrix which needs to be inverted: ");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d",&Mtx[i][j]);
        }
    }
    inverse(Mtx,I,N);
    print_Matrix(I,N);
}