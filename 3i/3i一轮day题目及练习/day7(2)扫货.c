#include<stdio.h>
int main (){
    int n,i,cs=0,q,h;
    long int V;
    int vi[100009];
    scanf("%d %ld",&n,&V);
    for(i=0;i<n;i++){
        scanf("%d",&vi[i]);
    }

    for(q=0;q<n;q++){
        h=vi[q]+h;
        if(h>V){
            h=0;
            q-=1;
            cs+=1;
        }
    }
    printf("%d",cs);
    return 0;
}
