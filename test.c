#include <stdio.h>
#include "stack.h"

#define BAG_MAXSIZE 10

void PrintBag(Stack *pStack, int *allGoods)
{
	int i;
	for(i=0; i < pStack->top; i++)
	{
		printf("%d ", allGoods[pStack->base[i]]);
	}
	printf("\n");
}

int main(void)
{
	Stack stack;
	int i, p, w, goodsNum;
	int allGoods[] = {1,8,4,3,5,2};

	goodsNum = (int)(sizeof(allGoods)/sizeof(int));

	Init_Stack(&stack);

	for(i=0; (i < goodsNum)||(IsNotEmpty(&stack)); i++)
	{
		w = GetWeigh(&stack, allGoods);
		if(w == BAG_MAXSIZE)
		{
			PrintBag(&stack, allGoods);
			PopBack(&stack, &p);
			i = p;
		}
		else if(w < BAG_MAXSIZE)
		{
			if(i < goodsNum)
			{
				PushBack(&stack, i);
			}
			else
			{
				PopBack(&stack, &p);					 //ťŘËÝ.
				i = p;
			}
		}
		else
		{
			PopBack(&stack, &p);
			i = p;
		}
	}

	return 0;
}
