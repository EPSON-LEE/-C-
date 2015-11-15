#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int row;
	int col;
	struct node *next;
}Link,*Linklist;

void Init_LinkList(Linklist *head); 
int  Length_Linklist(Linklist L);	
void Insert_Linklist(Linklist *head,int location,int row,int col,int length);
void Show_Linklist(Linklist head);
void Destroy_Linklist(Linklist *head);
void Reversal_Linklist(Linklist *head);
void Init_head_LinkList(Linklist *head);
void Union_Linklist(Linklist *head,Linklist *head2,Linklist *head3);

void Union_Linklist(Linklist *head,Linklist *head2,Linklist *head3)
{
	Linklist p = NULL,q = NULL;
	
	p = *head;
	q = *head2;

	while(p->next)
	{
		p = p->next;
	}

	p->next = (*head2);

	(*head3) = (*head);
}

void Init_head_LinkList2(Linklist *head)
{
	Linklist p = NULL,q = NULL;
	int col,row;
	
	printf("Please input your data(end:0)\n");
	scanf("%d%d",&col,&row);

	while(col && row)
	{
		p = malloc(sizeof(Link));
		p->col = col;
		p->row = row;

		p->next = q;
		q = p;

	printf("Please input your data(end:0)\n");
	scanf("%d%d",&col,&row);
	}
	*head = p;
}

void Reversal_Linklist(Linklist *head)
{
	Linklist p,q;
	q = NULL;
	p = (*head);

	while(p)
	{
		(*head) = p->next;
		p->next = q;
		q = p;
		p = (*head);
	}
	(*head) = q;
}

void Destrot_Linklist(Linklist *head)
{
	Linklist p = NULL,q = NULL;
	p = *head;
	p = q;
	if((*head) == NULL)
	{
		printf("It occurs a memory allocating error");
	}
	else
	{
		while(p != NULL)
		{
			q = p->next;
			free(p);
		}

		printf("You have destroyed the room successfully!\n");
	}
}

void Show_Linklist(Linklist head)
{
	Linklist p;
	p = head;

	printf("The data you have gotten is:\n");
	while(p != NULL)
	{
		printf("%d %d\n",(p->row),(p->col));
		p = p->next; 
	}

}

void Insert_Linklist(Linklist *head,int location,int row,int col,int length)		
{
	Linklist p = NULL,l = NULL;
	int i = 2;
	p = (*head);
	
	if(p)
	{
		while(i != location)
		{
			p = p->next;
			i++;
		}

		l =(Linklist)malloc(sizeof(Link));

		l->row = row;
		l->col = col;


		l->next = p->next;
		p->next = l;

		printf("You have Insert your data successfully\n");
	}
	else
	{
		printf("The form of your Linklist is not correct.\n");
	}
}

int Length_Linklist(Linklist L)
{
	Linklist p = L;
	int j = 1;

	while(p->next)
	{
		p = p->next; 
		j++;
	}

	return j;
}

void Init_LinkList(Linklist *head)
{
	Linklist p,q;
	
	int col,row;

	if((*head) != NULL)
	{
		printf("Initialising error");
	}
	else
	{
		printf("Please input your data:\n");
		scanf("%d%d",&row,&col);

		while(row && col)
		{
			p = (Linklist)malloc(sizeof(Link));
			p->row = row;
			p->col = col;
			p->next = NULL;

			if(*head == 0)
			{
				*head = p;
			}
			
			else
			{
				q->next = p;
			}
			q = p;
			
			printf("Please input your data:\n");
			scanf("%d%d",&row,&col);	
		}
	}
}

void main(void)
{
	int length;

	Linklist h = NULL;
	Linklist h2 = NULL;
	Linklist h3 = NULL;
    Init_LinkList(&h);
	
	Init_head_LinkList2(&h2);
	printf("-----------------------Insert from the head---------------\n");
	Show_Linklist(h2);

	printf("--------The length of the Linklist is %d-------------------\n", Length_Linklist(h2));

	Union_Linklist(&h,&h2,&h3);
	printf("\n\n");

	printf("--------------------After Union-------------------------:\n");
	Show_Linklist(h3);

	Destrot_Linklist(&h3);
	Destrot_Linklist(&h2);
	Destrot_Linklist(&h);
}
