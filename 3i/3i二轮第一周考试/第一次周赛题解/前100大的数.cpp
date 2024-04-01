#if 0
#endif

#include <stdio.h>
#include <string.h>

#define DEBUG_PRINT 1

#if DEBUG_PRINT
#define DEBUG printf
#else
#define DEBUG(...)
#endif

#include <iostream>
#include <algorithm>
#include <queue>

const int N = 100010;

using namespace std;

int heap[N];

char out_file[1010];

#define DEBUG_FOR 0



int main(void)
{

#if DEBUG_FOR
	for(int tk = 1; tk <= 10; tk ++)
	{
		snprintf(out_file, sizeof(out_file), "%d.in", tk);
		freopen(out_file, "r", stdin);
#endif		
		memset(heap, 0, sizeof(heap));
		
		int n = 0;
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d", &heap[i]);
		}
		
		sort(heap + 1, heap + n + 1);

#if DEBUG_FOR		
		snprintf(out_file, sizeof(out_file), "%d.out", tk);
		freopen(out_file, "w", stdout);
#endif		
		for(int i = n; i > n - 100; i --)
			printf("%d ", heap[i]);
#if DEBUG_FOR			
	}
#endif

	return 0;
}
