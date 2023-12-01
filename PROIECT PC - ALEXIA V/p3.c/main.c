#include <stdio.h>
#include <stdlib.h>
int n=0;
void citire()
{
    scanf("%d", &n);
    if(n<1 || n>100)
    {
        printf("Valoarea introdusa nu apartine intervalului (1-100) , introduceti alta valoare: ");
        citire(n);
    }
}
float FunctiaFor(int n)
{

    float produs=1, i=2;

    for(i=2; i<=n; i++)
        produs=produs*(1-1/(i*i));

    return produs;
}
float FunctiaWhile(int n)
{
    float produs=1, i=2;
    while(i<=n)
    {
        produs=produs*(1-1/(i*i));
        i++;
    }
    return produs;

}
float FunctiaDoWhile(int n)
{
    float produs=1, i=2;
    if(i<=n)
    {
        do
        {
            produs=produs*(1-1/(i*i));
            i++;
        }
        while(i<=n);
    }


    return produs;
}
int main()
{
    citire(n);
    printf("%f", FunctiaFor(n));
    printf("\n");
    printf("%f", FunctiaWhile(n));
    printf("\n");
    printf("%f", FunctiaDoWhile(n));
    return 0;
}
