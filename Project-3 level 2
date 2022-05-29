#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
int main()
{
    FILE* in;
    FILE* fp;
    char letter[100][100];
    int row, column, k;
    float Matrix[20][20], c, sum = 0.0;
    int n = 3;
    char letterz = 'z';
    float x[10]; 

    in = fopen("eq.txt", "r");
    fp = fopen("eq.txt", "r");

    for (int row = 1; row < 4; row++) {
        fscanf(in, "%s%*[\n]", letter[row]);
        printf("%s\n", letter[row]);
    }
    fclose(in);
    

    // This loop is for getting input for Matrix.
    for (row = 1; row <= n+1; row++)
    {
        if (strchr(letter[row], letterz) == NULL) {
            Matrix[row][3] = 0;
            fscanf(fp, "%fx%fy%*[=]%f", &Matrix[row][1], &Matrix[row][2], &Matrix[row][4]);
        }
        else {
            fscanf(fp, "%fx%fy%fz%*[=]%f", &Matrix[row][1], &Matrix[row][2], &Matrix[row][3], &Matrix[row][4]);
        }
    }
    fclose(fp);
    // This part generates upper triangular matrix
    for (column = 1; column <= n; column++)
    {
        for (row = 1; row <= n; row++)
        {
            if (row > column)
            {
                c = Matrix[row][column] / Matrix[column][column];
                for (k = 1; k <= n + 1; k++)
                {
                    Matrix[row][k] = Matrix[row][k] - c * Matrix[column][k];
                }
            }
        }
    }
    x[n] = Matrix[n][n + 1] / Matrix[n][n];
    //This loop is for backward substitution.
    for (row = n - 1; row >= 1; row--)
    {
        sum = 0;
        for (column = row + 1; column <= n; column++)
        {
            sum = sum + Matrix[row][column] * x[column];
        }
        x[row] = (Matrix[row][n + 1] - sum) / Matrix[row][row];
    }
    printf("\nThe solution is: \n");
    for (row = 1; row <= n; row++)
    {
        printf("\nx%d=%f\t", row, x[row]);
    }
    return(0);
}
