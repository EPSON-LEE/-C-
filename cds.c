/********************************
���������һ���û�����һ���ַ���
���ݸ����ú��������ú�����Ŀ���ַ���
���в�����Ȼ�����������
*********************************/
#include<stdio.h>
#include<string.h>

void ReversalString(char string[]);

void main(void)
{
	char string[15];

	printf("Please input a string:\n");
	gets(string);

	ReversalString(string);

	printf("%s\n",string);

}


void ReversalString(char string[])
{
	unsigned int length,i;
	unsigned char temp;

	length = strlen(string);
	printf("The length of the string is %d\n",length);

	for(i = 0; i < length/2; i++)
	{
		temp = string[i];
		string[i] = string[length-1-i];
		string[length-1-i] = temp;
	}
}