#include <stdio.h>
#include <stdlib.h>
typedef enum { FALSE, TRUE } boolean;
int n,m,k,arr[10][10], row, col;
void citireN(int x)
{
    printf("Numarul maxim admisibil pentru linii este: %d", x);
    printf("\nIntrodu numarul de linii :\n");
    scanf("%d", &n);
}
void citireM(int x)
{
    printf("Numarul maxim admisibil pentru coloane este: %d", x);
    printf("\nIntrodu numarul de coloane :\n");
    scanf("%d", &m);
}
void citireK(int x)
{
    printf("Numarul maxim admisibil pentru elementul K este: %d", m);
    printf("\nIntrodu numarul K :\n");
    scanf("%d", &k);
}
void matrix(int n, int m)
{
    for(row=0;row<n;row++)
    {
        for(col=0;col<m;col++)
        {
            printf("Introdu elementul arr[%d][%d] al matricei:", row, col);
            scanf("%d", &arr[row][col]);
        }

    }
}
void functie(int arr[10][10], int k)
{ int row2=0, col2=0,nr = 0;
 boolean ok=FALSE;

    for(row=0;row<n;row++)
    {
        nr=0;
        for(col=0;col<m;col++)
        {
            if(arr[row][col] != 0 )
                nr++;
        }
        if(nr>=k)
        {
                for(col2=0;col2<m;col2++)
                    printf("%d ", arr[row][col2]);
                    printf("\n");
                    ok=TRUE;
        }

    }
    if(ok==FALSE)
         printf("Nu exista o linie care sa indeplineasca  aceste conditii");
}
int main()
{
    citireN(9);
    citireM(9);
    citireK(9);
    matrix(n,m);
    printf("Matricea este: \n");

    for(row=0;row<n;row++)
    {
          for(col=0;col<m;col++)
            printf("%d ", arr[row][col]);
            printf("\n");
    }
    printf("\n");
    functie(arr,k);
    return 0;
}
