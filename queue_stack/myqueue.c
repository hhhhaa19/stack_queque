#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
typedef struct MyQueue
{
	stack input;
	stack ouput;
}MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* tag = (MyQueue*)malloc(sizeof(MyQueue));

	initstack(&tag->input);
	initstack(&tag->ouput);
	return tag;

}

void myQueuePush(MyQueue* obj, int x) 
{
	pushstack(&obj->input, x);
}
//把input转到output
void reverse(MyQueue* obj)
{
	while (!StackEmpty(&obj->input))
	{
		pushstack(&obj->ouput, stacktop(&obj->input));
		popstack(&obj->input);
	}
}
int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->ouput))
	{
		reverse(obj);
		DATATYPE ret =stacktop(&obj->ouput);
		popstack(&obj->ouput);
		return ret;
	}
	else
	{
		DATATYPE ret = stacktop(&obj->ouput);
		popstack(&obj->ouput);
		return ret;
	}
}

int myQueuePeek(MyQueue* obj) 
{
	if (StackEmpty(&obj->ouput))
	{
		reverse(obj);
		DATATYPE ret = stacktop(&obj->ouput);
		return ret;
	}
	else
	{
		DATATYPE ret = stacktop(&obj->ouput);
		return ret;
	}
}
//如果队列为空，返回 true ；否则，返回 false
bool myQueueEmpty(MyQueue* obj) {
	if (StackEmpty(&obj->input) && StackEmpty(&obj->ouput))
		return true;
	else
		return false;
}

void myQueueFree(MyQueue* obj) 
{
	destroystack(&obj->input);
	destroystack(&obj->ouput);
	free(obj);

}