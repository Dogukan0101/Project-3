#include<stdio.h>
int main()
{
    int row,column,k,n;
    float Matrix[20][20],c,x[10],sum=0.0;
    printf("\nEnter the order of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of matrix: \n\n");
    // This loop is for getting input for Matrix.
    for(row=1; row<=n; row++)
    {
        for(column=1; column<=(n+1); column++)
        {
            printf("A[%d][%d] : ", row,column);
            scanf("%f",&Matrix[row][column]);
        }
    }
    // This part generates upper triangular matrix
    for(column=1; column<=n; column++) 
    {
        for(row=1; row<=n; row++)
        {
            if(row>column)
            {
                c=Matrix[row][column]/Matrix[column][column];
                for(k=1; k<=n+1; k++)
                {
                    Matrix[row][k]=Matrix[row][k]-c*Matrix[column][k];
                }
            }
        }
    }
    x[n]=Matrix[n][n+1]/Matrix[n][n];
    //This loop is for backward substitution.
    for(row=n-1; row>=1; row--)
    {
        sum=0;
        for(column=row+1; column<=n; column++)
        {
            sum=sum+Matrix[row][column]*x[column];
        }
        x[row]=(Matrix[row][n+1]-sum)/Matrix[row][row];
    }
    printf("\nThe solution is: \n");
    for(row=1; row<=n; row++)
    {
        printf("\nx%d=%f\t",row,x[row]); 
    }
    return(0);
}
