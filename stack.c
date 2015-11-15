#include<stdio.h>
#include<stdlib.h>
/*******************************************
	1�������˶�ջ��ָ�����ݽṹlinkStack����
����top��count�������� top����ָ��ǰ������
�ᣬcount�Զ�ջ�����ݽ����ͳ�ơ�
	2�����������ݽ�������ݽṹstackNode����
����data�� struct* next
	3�����ݽ�����������Լ�����ģ��൱������
�еĽ�㡣
	4�����������ݽṹ�����ˡ�createStack��
push()��pop()��print()��printlength()�������
********************************************/
typedef char datatype;
typedef int status;

typedef struct stackNode{
	datatype data;
	struct stackNode* next;
}stackNode;

typedef struct topPtr{
	stackNode *top;
	int count;
}linkStack;

status createStack(linkStack **ptr)
{
	(*ptr) =(linkStack *)malloc(sizeof(linkStack));
	(*ptr)->top = (stackNode *)malloc(sizeof(stackNode));


	(*ptr)->top = NULL;
	(*ptr)->count = 0;

	return 1;
}

status push(linkStack **ptr,datatype data)
{
	stackNode* p;
	p = (stackNode *)malloc(sizeof(stackNode));

	p->data = data;

	p->next = (*ptr)->top;
	(*ptr)->top = p;

	(*ptr)->count += 1;

	return 1;
}

status pop(linkStack **ptr)
{
	stackNode *temp;

	temp = (*ptr)->top->next;

	free((*ptr)->top);

	(*ptr)->top = temp;
	(*ptr)->count--;

	return 1;
}

status printStack(linkStack *ptr)
{
	linkStack* p;
	
	p = ptr;

	while(p->top)
	{
		printf("%d\n",p->top->data);
		p->top = p->top->next;
	}

	return 1;
}

status printLength(linkStack *ptr)
{
	return ptr->count;
}


status printLength(linkStack *ptr);
status printStack(linkStack *ptr);
status pop(linkStack **ptr);
status push(linkStack **ptr,datatype data);
status createStack(linkStack **ptr);

void main()
{
	linkStack *ptr;
	int i = 0;
	char str[15];
	createStack(&ptr);


	printf("������һ���ַ���\n");
	gets(str);

	while(str[i] != '\0')
	{
		if(str[i] == '[' || str[i] == '{' || str[i] == '(')
		{
				push(&ptr,str[i]);
				i++;

				if(str[i] == ']' || str[i] == '}' || str[i] == ')')
				{
			    	pop(&ptr);
					i++;
				}

		}
		else if(str[i] == ']' || str[i] == '}' || str[i] == ')')
		{
			printf("ƥ��ʧ��");
		}
		else{
			i++;
		}

	}




	/*
	push(&ptr,1);
	push(&ptr,2);
	push(&ptr,3);
	push(&ptr,4);
	push(&ptr,5);
	push(&ptr,6);
	pop(&ptr);
	pop(&ptr);

	printStack(ptr);
	printf("the length of the stack is %d\n",printLength(ptr));
	*/
}
