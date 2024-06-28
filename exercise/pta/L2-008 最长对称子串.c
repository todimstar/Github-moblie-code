#include<stdio.h>
#include<string.h>
int main (){
    char a[1001],b[1001],c[1000]="Is PAT&TAP symmetric?";
    int i,j,lena,lenb,lenc;
    fgets(a, sizeof(a),stdin);
    gets(b);
    lena=strlen(a);lenb=strlen(b);lenc=strlen(c);
    printf("lena=%d,lenb=%d,lenc=%d",lena,lenb,lenc);
    strcpy(b,a);
    for(i=0;i<lena;i++){
        for(j=lena-1;j>0;j--){
            if(a[i]==b[j]){
                
            }
        }
    }
    return 0;
}
