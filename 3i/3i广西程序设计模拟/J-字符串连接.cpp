#include<iostream>
#include<cstring>
using namespace std;

#define MAX 10010
char sa[MAX],sb[MAX],a[MAX],b[MAX];

int main (){
	
	scanf("%s%s",a,b);
	int len=strlen(a),i,j=0;
	for (i = 1; i < len; i++) {
	  if (a[i] % 2 == a[i-1] % 2) {
	    sa[j++] = max(a[i], a[i-1]); 
	  }
	}sa[j]='\0';
	len=strlen(b);j=0;
	for (i = 1; i < len; i++) {
	  if (b[i] % 2 == b[i-1] % 2) {
	    sb[j++] = max(b[i], b[i-1]);
	  }
	}sb[j]='\0';
	if(strcmp(sa,sb)==0){
		printf("%s",sa);
	}
	else {
		printf("%s\n%s",sa,sb);
	}
	return 0;
}
