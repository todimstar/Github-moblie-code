#include <stdio.h>

//#define debug printf
#define debug(...)

struct box
{
	int index;
	int red;
	int green;
	int blue;
}boxs[1010];

struct box *pBoxs[1010];

int n;

void swap(struct box **p1, struct box **p2)
{
	struct box *tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	
	for(int i = 1; i <= n ; i++)
	{
		debug("%d ", pBoxs[i]->index);
//		printf("%d %d %d\n", pBoxs[i]->red, pBoxs[i]->green, pBoxs[i]->blue);
	}
//	puts("");
	
}

void sort()
{
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= i; j ++)
		{
			if(pBoxs[i]->red > pBoxs[j]->red)
			{
				debug("1: %d - %d\n", i, j);
				swap(&pBoxs[i], &pBoxs[j]);
			}
			else if(pBoxs[i]->red == pBoxs[j]->red)
			{
				if(pBoxs[i]->green > pBoxs[j]->green)
				{
					debug("2: %d - %d\n", i, j);
					swap(&pBoxs[i], &pBoxs[j]);
				}
				else if(pBoxs[i]->green == pBoxs[j]->green)
				{
					if(pBoxs[i]->blue > pBoxs[j]->blue)
					{
						debug("3: %d - %d\n", i, j);
						swap(&pBoxs[i], &pBoxs[j]);
					}
				}
			} 
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		boxs[i].index = i;
		scanf("%d%d%d", &boxs[i].red, &boxs[i].green, &boxs[i].blue);
		pBoxs[i] = &boxs[i];
	}
	
	sort();
	for(int i = 1; i <= n ; i++)
	{
		printf("%d ", pBoxs[i]->index);
//		printf("%d %d %d\n", pBoxs[i]->red, pBoxs[i]->green, pBoxs[i]->blue);
	}
	
	return 0;
}
