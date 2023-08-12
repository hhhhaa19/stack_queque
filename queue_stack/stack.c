#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void initstack(stack* head)
{
	head->capacity = 0;
	head->top = 0;
	head->data = NULL;

}

void pushstack(stack* head,DATATYPE x)
{
	assert(head);
	if (head->capacity == head->top)
	{
		DATATYPE* temp = (DATATYPE*)realloc(head->data,(head->capacity+2) * sizeof(DATATYPE));//����*�����ֽڴ�С
		head->capacity = (head->capacity + 2);
		if(temp==NULL)
		{
			perror("malloc failed");
			exit(-1);
		}
		head->data = temp;
	}
	head->data[head->top] = x;
	head->top++;
}
void popstack(stack* head)
{
	assert(head);
	assert(head->top);
	head->top--;
}
DATATYPE stacktop(stack* head)
{
	assert(head);
	return head->data[head->top-1];//top��ָ����һ��ջ����
}
bool StackEmpty(stack* head)
{
	assert(head);
	if (head->top == 0)
	{
		return true;
	}
	else
		return false;
}
void destroystack(stack* head)
{
	assert(head);
	free(head->data);
	head->data = NULL;
	head->capacity = 0;
	head->top = 0;
}