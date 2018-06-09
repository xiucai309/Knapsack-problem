#include "stack.h"
#include <stdlib.h>

void Init_Stack(Stack *pStack)
{
	if(pStack)
	{
		pStack->base = (int *)malloc(sizeof(int) * INIT_STACK_SIZE);
		if(!pStack->base)
		{
			exit(0);
		}
		pStack->top = 0;
		pStack->Max_Size = INIT_STACK_SIZE;
	}
}

int PopBack(Stack *pStack, int *pData)
{
	if(pStack)
	{
		if(pStack->top > 0)
		{
			*pData = pStack->base[--(pStack->top)];
			return 1;
		}
		return -1;
	}
	return -1;
}

void PushBack(Stack *pStack, int data)
{
	if(!pStack)
	{
		return ;
	}
	if(pStack->top > pStack->Max_Size - 1)
	{
		pStack->base = (int *)malloc(sizeof(int) * pStack->Max_Size * 2);
		if(!pStack->base)
		{
			exit(0);
		}
		pStack->Max_Size *= 2;
	}

	pStack->base[pStack->top++] = data;
}

int GetWeigh(Stack *pStack, int *allGoods)
{
	int i, w = 0;
	for(i=0; i < pStack->top; i++)
	{
		w += allGoods[pStack->base[i]];
	}
	return w;
}

int IsNotEmpty(Stack *pStack)
{
	if(!pStack || pStack->top <= 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

