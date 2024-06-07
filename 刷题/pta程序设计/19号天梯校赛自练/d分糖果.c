#include <stdio.h>  
  
int min_candies(int n, int scores[]) {  
    int candies = n; // 初始化糖果数量为孩子的数量  
    int prev_score = -1; // 用于比较当前孩子与前一个孩子的得分  
  
    for (int i = 0; i < n; i++) {  
        if (scores[i] > prev_score) {  
            candies += scores[i] - prev_score; // 如果当前孩子得分更高，则需要更多的糖果  
        }  
        prev_score = scores[i]; // 更新前一个孩子的得分为当前孩子的得分  
        candies++; // 每个孩子至少需要一个糖果  
    }  
  
    return candies;  
}  
  
int main() {  
    int n, i;  
    printf("请输入孩子的数量: ");  
    scanf("%d", &n);  
    int scores[n];  
    printf("请输入每个孩子的得分:\n");  
    for (i = 0; i < n; i++) {  
        scanf("%d", &scores[i]);  
    }  
    printf("所需的最小糖果数为: %d\n", min_candies(n, scores));  
    return 0;  
}
