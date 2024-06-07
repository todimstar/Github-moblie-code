#include <stdio.h>  
#include <stdlib.h>  //啥本希冀oj登不上去提交,按测试数据是ok了,思路检索也没问题 
#include <string.h>  
  
#define MAX_CHARS 256 // 假设字符集大小不超过256，适用于ASCII码  
  
int countWaysToSplit(char *s) {  
    int n = strlen(s);  
    if (n < 2) return 0;  
  
    int leftCount[MAX_CHARS] = {0}; // 记录左边的字符出现次数  
    int rightCount[MAX_CHARS] = {0};  // 记录右侧字符出现次数 
  	int left[n]={0};// 记录左边的字符种类 
  	int right[n]={0};// 记录右边的字符种类 
    // right 
    
	right[n-1]++;rightCount[(unsigned char)s[n-1]]++;
	
    for (int i = n-2; i >=0; i--) {  
    	if(rightCount[(unsigned char)s[i]]==0){
			right[i]=right[i+1]+1;rightCount[(unsigned char)s[i]]++;
		}else right[i]=right[i+1];
          
    }  
    int ways = 0; // 可能的分割方式数量  
  	left[0]++;leftCount[(unsigned char)s[0]]++;
  	if(left[0]==right[0])ways++;
    // 遍历字符串，从左检查每个分割点  
    for (int i = 1; i < n ; ++i) {  
        if(leftCount[(unsigned char)s[i]]==0){
			left[i]=left[i-1]+1;leftCount[(unsigned char)s[i]]++;
			
		}else left[i]=left[i-1];
      	
        // 检查左边字符串的字符种类是否等于右边字符串的字符种类  
        if(left[i]==right[i])ways++;
    }  
  
    return ways-1;  
}  
  
int main() {  
    char s[10001]; // 输入字符串，最大长度10000  
    scanf("%s", s);  
  
    int result = countWaysToSplit(s);  
    printf("%d\n", result);  
  
    return 0;  
}
