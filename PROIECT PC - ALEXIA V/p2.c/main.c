#include <stdio.h>
#include <stdlib.h>
int v[100], n,i, medn, medp, sump, sumn, nrn, nrp;
int main()
{

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    for(i=0;i<n;i++)
    {
        if(v[i]>0)
        {
             sump=sump+v[i];
             nrp++;
        }

        else if(v[i]<0)
        {
              sumn=sumn+v[i];
              nrn++;
        }
    }
    if(nrp>0)
    {
        medp=sump/nrp;
        printf("%d \n",medp);
    }
    else printf("Toate numerele sunt negative \n");
    if(nrn>0)
    {
        medn=sumn/nrn;
        printf("%d",medn);
    }
    else printf("Toate numerele sunt pozitive \n");
    return 0;
}
