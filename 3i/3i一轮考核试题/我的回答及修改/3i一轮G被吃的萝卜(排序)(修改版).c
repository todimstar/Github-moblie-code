//#include<stdio.h>
//int main(){
//    int n,i,j=0,f;
//    scanf("%d",&n);
//    int xu[n];
//    for(i=0;i<n;i++){
//        scanf("%d",&xu[i]);
//    }
//    for(f=0;f<n;f++){
//        for(i=n;i>0;i--){
//            if(xu[i-1]>xu[i]){
//                j=xu[i-1];
//                xu[i-1]=xu[i];
//                xu[i]=j;
//            }
//        }
//    }
//    for(i=0;i<n;i++){
//		printf("%d",xu[i]);
//	}
//    
//    return 0;
//}


#include<stdio.h>
int main(){
    int n,i,j=0,f;
    scanf("%d",&n);
    int xu[n];
    for(i=0;i<n;i++){
        scanf("%d",&xu[i]);
    }
    for(f=0;f<n;f++){
        for(i=n;i>0;i--){
            if(xu[i-1]>xu[i]){
                j=xu[i-1];
                xu[i-1]=xu[i];
                xu[i]=j;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",xu[i]);//为什么交上去不对50%？ 
	}
    return 0;
}
