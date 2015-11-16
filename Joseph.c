#include<stdio.h> 
#include<malloc.h>
#define m 2
#define n 5


typedef struct People  
{  
    int number;  

    struct People *next;  
}People;

People* Create_List(People* L)	//建立循环链表
{
	People *p = NULL;
	People *curr;
	int i = 1;						//i为计数工具

	while(i != n+1)
	{
		curr = (People *)malloc(sizeof(People));

		if(i == 1)
		{
			p = curr;
			L = curr;
		}
		else
		{
			p->next = curr;
			p = curr;
		}

		curr->number = i;
		i += 1;
	}

	p->next = L;

	printf("creating:%x\n",L);
	return L;
}

void Print_List(People *L)
{
	int i;
	People *u;
	u =(People *)malloc(sizeof(People));
	for(i = 1; i<n+1;i++)
	{
		printf("%d\n",L->number);
		L = L->next;			//stop running
	}
	L = u;
	printf("printing:%x\n",L);
}

void List_kind(People* L)  
{											//L为n个人构成的链表，报数报到m的人出列  
    People *q = NULL;
	People *p = NULL;
	People *x = NULL;
	People *k = NULL;

	int i;
	p = L;									//p指向当前结点，q指向p的前驱  
	
    while(p->next != p)						//当链表只剩下一个结点，即报数剩下一个人的时候结束。  
    {  
        for(i = 1;i < m; i++)  
        {									//for循环实现功能：使p指向要出列的结点，q指向p的前驱  
            q=p;  
            p=p->next;  
        }  

        printf("%d\n",p->number);  
        q->next = p->next;					//将要出列的结点从链表“剔除”  
        free(p);  
        p = q->next;						//p指向出列的下一个结点，重新开始报数  
    }  
    printf("%d\n",q->number);				//输出最后一个人  
    free(q);

/*-----------------测试地址---------------------*/
/*	x = (int *)malloc(2*sizeof(int));
	printf("x:%x\n",x);
	k = (double *)malloc(sizeof(double));
	printf("k:%x\n",k);

	L = k;
	printf("choosing:%x\n",L);
*/
}  

void main()
{
	People *L = NULL;


	printf("first locatin:%x\n",L);

	L = Create_List(L);				//transport the address
	printf("give value:%x\n",L);

	printf("RETURN:%x\n",L);

	printf("after create:%x\n",L);
	Print_List(L);						//形参 People *L 实参L 结论 打印不会影响到L的地址值
	printf("after printing:%x\n",L);

	printf("-----------------------出圈顺序-----------------------\n");
	List_kind(L);  

	printf("at last:%x\n",L);
	
  	getchar();
}
