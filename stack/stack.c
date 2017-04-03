#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	struct node *ptNext;
}NODE, *PT_NODE;

typedef struct stack
{
	PT_NODE pTop;
	PT_NODE pBottom;
}STACK, *PT_STACK;

int init(PT_STACK pStack);
int isEmpty(PT_STACK pStack);
int traverse(PT_STACK pStack);
int push(PT_STACK pStack, int val);
int pop(PT_STACK pStack, int *pt_Val);
int clear(PT_STACK pStack);

int main(void)
{
	STACK S;
	int val;
	init(&S);
	push(&S, 1); 
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	push(&S, 6);
	traverse(&S);
	if(pop(&S, &val))
	{
		printf("pop success, the val is %d\n", val);
	}
	else
	{
		printf("pop failed!\n");
	}

	traverse(&S); 
	return 0;
}

int init(PT_STACK pStack)
{
	pStack->pTop = (PT_NODE)malloc(sizeof(NODE));
	if(pStack->pTop == NULL)
	{
		printf("malloc failed!\r\n");
		return -1;
	}
	else
	{
		pStack->pBottom = pStack->pTop;
		pStack->pTop->ptNext = NULL;
	}
}

int traverse(PT_STACK pStack)
{
	PT_NODE p = pStack->pTop;
	while(p != pStack->pBottom)
	{
		printf("%d ", p->data);
		p = p->ptNext;
	}
	printf("\n");
	return 0;
}

int isEmpty(PT_STACK pStack)
{
	if(pStack->pTop == pStack->pBottom)
		return 1;
	else
		return 0;
}

int push(PT_STACK pStack, int val)
{
	PT_NODE pNew 	= (PT_NODE)malloc(sizeof(NODE));
	pNew->data 	= val;
	pNew->ptNext 	= pStack->pTop;
	pStack->pTop  	= pNew;
	return 0;
}

int pop(PT_STACK pStack, int *pt_Val)
{
	if(isEmpty(pStack))
	{
		return 0;
	}
	else
	{
		PT_NODE r = pStack->pTop;
		*pt_Val = r->data;
		pStack->pTop = r->ptNext;
		free(r);
		r = NULL;
		return 1;
	}
}

int clear(PT_STACK pStack)
{
	if(isEmpty(pStack))
	{
		return 0;
	}
	else
	{
		PT_NODE p = pStack->pTop;
		PT_NODE q = NULL;
		while(p != pStack->pBottom)
		{
			q = p->ptNext;
			free(p);
			p = q;
		}
		pStack->pTop = pStack->pBottom;
	}
	return 1;
}
