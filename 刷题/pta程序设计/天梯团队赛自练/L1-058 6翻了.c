#include<stdio.h>
#include<string.h>
int main(){
    char a[1002];//得1002才是下标到1001;过了 
    int i,len;
    int start=0,cot66=0;
    char* p=NULL;
    
    fgets(a,sizeof(a),stdin);
    len=strlen(a);a[--len]='\0';
    for(i=0;i<len;i++){
        if(a[i-1]=='6'&&a[i]=='6'){
            cot66++;
        }else {
            cot66=0;start=i;
        }
        if(a[i+1]!='6'&&cot66>2&&cot66<9){//i+1过len不过a[1002],未越界
            a[start]='\0';a[i]='9';p=&a[i];
            strcat(a,p);len-=cot66;i=start; 
        }else if(a[i+1]!='6'&&cot66>=9){
            a[start]='\0';a[i-1]='2';a[i]='7';p=&a[i-1];//没'27'
            strcat(a,p);len-=(cot66-1);i=start; 
        }
    }
    printf("%s\n",a);
    return 0;
}
