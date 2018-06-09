
#ifndef _STACK_H
#define _STACK_H

#define INIT_STACK_SIZE 10

typedef struct Stack_st {
	int *base;
	int top;
	int Max_Size;
}Stack;

void Init_Stack(Stack *);
int PopBack(Stack *pStack, int *pData);
void PushBack(Stack *pStack, int data);
int GetWeigh(Stack *pStack, int *allGoods);
int IsNotEmpty(Stack *pStack);

#endif

