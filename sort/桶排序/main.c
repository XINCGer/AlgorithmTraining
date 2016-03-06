/*
Õ∞≈≈–Ú
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int book[1001],i,j,t,n;
    for(i=0;i<=1000;i++){
        book[i]=0;
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&t);
        book[t]++;
    }
    for(i=1000;i>=0;i--){
        for(j=1;j<=book[i];j++){
            printf("%d\t",i);
        }
    }
    return 0;
}
