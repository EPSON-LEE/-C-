#include<stdio.h> 
#include<malloc.h>
#define m 2
#define n 5


typedef struct People  
{  
    int number;  

    struct People *next;  
}People;

People* Create_List(People* L)	//����ѭ������
{
	People *p = NULL;
	People *curr;
	int i = 1;						//iΪ��������

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
{											//LΪn���˹��ɵ�������������m���˳���  
    People *q = NULL;
	People *p = NULL;
	People *x = NULL;
	People *k = NULL;

	int i;
	p = L;									//pָ��ǰ��㣬qָ��p��ǰ��  
	
    while(p->next != p)						//������ֻʣ��һ����㣬������ʣ��һ���˵�ʱ�������  
    {  
        for(i = 1;i < m; i++)  
        {									//forѭ��ʵ�ֹ��ܣ�ʹpָ��Ҫ���еĽ�㣬qָ��p��ǰ��  
            q=p;  
            p=p->next;  
        }  

        printf("%d\n",p->number);  
        q->next = p->next;					//��Ҫ���еĽ��������޳���  
        free(p);  
        p = q->next;						//pָ����е���һ����㣬���¿�ʼ����  
    }  
    printf("%d\n",q->number);				//������һ����  
    free(q);

/*-----------------���Ե�ַ---------------------*/
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
	Print_List(L);						//�β� People *L ʵ��L ���� ��ӡ����Ӱ�쵽L�ĵ�ֵַ
	printf("after printing:%x\n",L);

	printf("-----------------------��Ȧ˳��-----------------------\n");
	List_kind(L);  

	printf("at last:%x\n",L);
	
  	getchar();
}
