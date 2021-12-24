#include <stdio.h>
#include <stdlib.h>
int * matrix(int *A, int a)//маccив
{
    int number;
    for(int i=0;i < a; i++)
    {
        printf("Element [%d] = ",i+1);
        scanf("%d",&A[i]);
        printf("\n");
    }

    return A;
}

int * memoryAllocation(int rows)// выделение памяти
{
    int i = 0;
    int *matrix = (int *)malloc(rows*sizeof(int));
    return matrix;
}
void clearMemory(int *matrix, int rows)//очистка памяти
{
    int i;
    for(i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int * print_matrix(int *A, int a)//вывод массива
{
    for(int i = 0; i < a; i++)
    {
        printf("%d \t", A[i]);
    }
    printf("\n");
}
int main()
{
    int *A;
    unsigned int  N;
    FILE*fp;
    printf("Hello world!\n");

    fp = fopen("positive_number.txt", "r");
    fscanf(fp, "%d", &N);
    printf("\nX = %d", N);
    printf("\n");
    A = memoryAllocation(N);
    matrix(A, N);
    printf("\n");
    print_matrix(A,N);
    fclose(fp);

    fp = fopen("text_1.txt", "w");
    for(int i=0;i<N; i++)
    {
        fprintf(fp, "%2d", A[i]);
    }
    fclose(fp);

    fp = fopen("text_1binar.bin", "wb");
    for(int i=0;i<N; i++)
    {
        fwrite(&A[i], sizeof(int), 1, fp);
    }
    fclose(fp);
    return 0;
}
