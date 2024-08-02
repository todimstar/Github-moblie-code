//应该是上楼梯类型题，组合型枚举，求出1,2,5步上n级台阶有几种方法
#include <stdio.h>

    // memoization array
int path[3] = {1, 2, 5};    // move path declaration to global scope

int dfs(int u) {
if (u < 0) return 0;    // if u is negative, return 0
if (u == 0) return 1;
    // if already computed, return the result

// if not computed, compute and store the result
int cnt = 0;
//printf("进了%d\n",u);
for (int i = 0;   i < 3;   i++) {
	//printf("%d的第%d次\n",u,i);
cnt += dfs(u - path[i]);
}
//printf("算出了%d\n",u);   // store the result for future reference
return cnt;
}

int main() {

int num = dfs(15);
printf("%d\n", num);
return 0;  //只能算到10？？ 
}
/*
//回答一致，确实正确，并使用了记忆化数组
#include <stdio.h>

// memoization array
int path[3] = {1, 2, 5};

// memoization table
int memo[11] = {0};

int dfs(int u) {
    if (u < 0) return 0; // if u is negative, return 0
    if (u == 0) return 1; // if u is 0, return 1
    if (memo[u] != 0) return memo[u]; // if already computed, return the result

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        cnt += dfs(u - path[i]);
    }
    memo[u] = cnt; // store the result for future reference
    return cnt;
}

int main() {
    int num = dfs(15);
    printf("%d\n", num);
    return 0;
}*/