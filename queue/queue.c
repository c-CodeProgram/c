#include <stdio.h>  
#include <stdlib.h>  

typedef struct queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE, *PT_QUEUE;

void init(PT_QUEUE ptQueue);
int in_queue(PT_QUEUE ptQueue, int val);
int out_queue(PT_QUEUE ptQueue, int *val);
void traverse_queue(PT_QUEUE ptQueue);
int isFull_queue(PT_QUEUE ptQueue);
int isEmpty_queue(PT_QUEUE ptQueue);


int main(void)
{
	QUEUE Q;
	int val;
	init(&Q);

	in_queue(&Q, 1);
	in_queue(&Q, 2);
	in_queue(&Q, 3);
	in_queue(&Q, 4);
	in_queue(&Q, 5);
	in_queue(&Q, 6);
	in_queue(&Q, 7);
	in_queue(&Q, 8);

	traverse_queue(&Q);
	if (out_queue(&Q, &val)) 
	{ 
        	printf("\nout of queue success，the val is :%d\n",val);  
	}    	
	else 
	{ 
        	printf("\nout of queue failed!");  
        }
    	traverse_queue(&Q); 	
	return 0;
}

void init(PT_QUEUE ptQueue)
{
	ptQueue->pBase = (int *)malloc(sizeof(int) * 6);
	ptQueue->front = 0;
	ptQueue->rear = 0;
	return;
}

int isFull_queue(PT_QUEUE ptQueue)
{
	if((ptQueue->rear + 1) % 6 == ptQueue->front)
		return 1;
	else
		return 0;
}

int isEmpty_queue(PT_QUEUE ptQueue)
{
	if(ptQueue->front == ptQueue->rear)
		return 1;
	else
		return 0;
}

void traverse_queue(PT_QUEUE ptQueue)
{
	int i = ptQueue->front;
	while(i != ptQueue->rear)
	{
		printf("%d ", ptQueue->pBase[i]);
		i = (i + 1) % 6;
	}
	return;
}

int in_queue(PT_QUEUE ptQueue, int val)
{
	if(isFull_queue(ptQueue))
	{	
		return 0;
	}
	else
	{
		ptQueue->pBase[ptQueue->rear] = val;
		ptQueue->rear = (ptQueue->rear + 1) % 6;
		return 1;
	}
}

int out_queue(PT_QUEUE ptQueue, int *val)
{
	if(isEmpty_queue(ptQueue))
	{
		return 0;
	}
	else
	{
		*val = ptQueue->pBase[ptQueue->front];
		ptQueue->front = (ptQueue->front + 1) % 6;
		return 1;
	}
}
