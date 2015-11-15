#include<stdio.h>
#include<stdlib.h>
/*******************************************
	1、定义了堆栈的指针数据结构linkStack，包
括了top、count两个变量 top用来指向当前的数据
结，count对堆栈的数据结进行统计。
	2、定义了数据结这个数据结构stackNode，包
括了data和 struct* next
	3、数据结这个概念是自己定义的，相当于链表
中的结点。
	4、此链表数据结构包括了、createStack、
push()、pop()、print()、printlength()五个函数
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


	printf("请输入一个字符串\n");
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
			printf("匹配失败");
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
