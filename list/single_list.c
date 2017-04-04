#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book
{
	char bName[32];
	int price;
	struct book *ptNext;
}BOOK, *PT_BOOK;

PT_BOOK list_create(void);
void traverse(PT_BOOK h);
void list_delete(PT_BOOK h, char *name);
void list_insert(PT_BOOK h, PT_BOOK d, int n);
void list_px(PT_BOOK h);
void list_fx(PT_BOOK h);	

int main(void)
{
	PT_BOOK h;
	h = list_create();
//	traverse(h);	
	PT_BOOK d;
	d = (PT_BOOK)malloc(sizeof(BOOK));
	strcpy(d->bName, "time");
	d->price = 120;
	list_insert(h, d, 2);
//	traverse(h);
	list_px(h);
	traverse(h);
	list_fx(h);

	traverse(h);
	return 0;
}

PT_BOOK list_create(void)
{
	PT_BOOK h;
	PT_BOOK p;
	PT_BOOK q;
	char ch;
	h = (PT_BOOK)malloc(sizeof(BOOK));
	h->ptNext = NULL;
	q = h;
	while(1)
	{
		p = (PT_BOOK)malloc(sizeof(BOOK));
		printf("input book name:");
		gets(p->bName);
		printf("input book price:");
		scanf("%d", &p->price);
		p->ptNext = NULL;
		q->ptNext = p;
		q = p;
		while(getchar() != '\n');
		printf("是否继续输入:");
		ch = getchar();
		if(ch == 'N' || ch == 'n')
		{
			break;
		}
		while(getchar() != '\n');
	}
	return h;
}

void traverse(PT_BOOK h)
{
	while(h->ptNext != NULL)
	{
		h = h->ptNext;
		printf("book name:   <%s>       book price:   %d", h->bName, h->price);
		printf("\n--------------------------------------------------------\n");
	}
}

void list_delete(PT_BOOK h, char *name)
{
	PT_BOOK p;
	PT_BOOK q;
	q = h;
	while(q->ptNext != NULL)
	{
		p = q->ptNext;
		if(strcmp(name, p->bName) == 0)
		{
			q->ptNext = p->ptNext;
			free(p);
			p = NULL;
			return;
		}
		else
		{
			q = q->ptNext;
		}
	}
	printf("no book delete!\r\n");
}

void list_insert(PT_BOOK h, PT_BOOK d, int n)
{
	PT_BOOK q;
	int i = 0;
	q = h;
	while(i != n-1)
	{
		if(q->ptNext != NULL)
		{
			i++;
			q = q->ptNext;
		}
		else
		{
			printf("can`t insert!\r\n");
		}
	}
	d->ptNext = q->ptNext;
	q->ptNext = d;
	return;
}

void list_px(PT_BOOK h)
{
	int n = 0;
	int i, j;
	PT_BOOK r;
	PT_BOOK p;
	PT_BOOK q;
	r = h;
	while(r->ptNext != NULL)
	{
		n++;
		r = r->ptNext;
	}
	for(i = 0; i < n-1; i++)
	{
		r = h;
		for(j = 0; j < n-i-1; j++)
		{
			p = r->ptNext;
			q = p->ptNext;
			if(p->price < q->price)
			{
				p->ptNext = q->ptNext;
				q->ptNext = p;
				r->ptNext = q;
			}
			r = r->ptNext;
		}
	}
}

void list_fx(PT_BOOK h)
{
	int count = 0;
	int i;
	PT_BOOK r;
	PT_BOOK p;
	PT_BOOK q;
	r = h;
	while(r->ptNext != NULL)
	{
		count++;
		r = r->ptNext;
	}
	if(count >= 2)
	{
		r = h;
		p = r->ptNext;
		q = p->ptNext;
		for(i = 1; i <= count; i++)
		{
			if(i == 1)
			{
				p->ptNext = NULL;
			}
			else
			{
				p->ptNext = r;
			}
			r = p;
			p = q;
			if(p->ptNext != NULL)
			{
				q = q->ptNext;
			}
		}
		h->ptNext = r;
	}
}
