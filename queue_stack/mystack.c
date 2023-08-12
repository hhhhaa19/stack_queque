#define _CRT_SECURE_NO_WARNINGS 1
#include"queque.h"
#include"stack.h"
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
typedef struct {
	Queue *q1;
	Queue *q2;
} MyStack;


bool myStackEmpty(MyStack* obj)
{
	return (QueueEmpty(obj->q1) && QueueEmpty(obj->q2));

}
MyStack* myStackCreate()
{
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	ms->q1 = (Queue*)malloc(sizeof(Queue));
	ms->q2 = (Queue*)malloc(sizeof(Queue));
	QueueInit(ms->q1);
	QueueInit(ms->q2);

	return ms;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	if (QueueEmpty(obj->q1)==0)
		QueuePush(obj->q1, x);
	else
		QueuePush(obj->q2, x);

}

int myStackPop(MyStack* obj) {

	if (QueueEmpty(obj->q1) == 1)
	{
		int size = QueueSize(obj->q2);
		while (size > 1)
		{
			QueuePush(obj->q1, QueueFront(obj->q2));
			QueuePop(obj->q2);
			size--;
		}
		int tag = QueueFront(obj->q2);
		QueuePop(obj->q2);
		return  tag;
	}
	else
	{
		int size = QueueSize(obj->q1);
		while (size > 1)
		{
			QueuePush(obj->q2, QueueFront(obj->q1));
			QueuePop(obj->q1);
			size--;
		}
		int tag = QueueFront(obj->q1);
		QueuePop(obj->q1);
		return  tag;
	}
}

int myStackTop(MyStack* obj) {
	if (myStackEmpty(obj) == false)
	{
		if (QueueEmpty(obj->q1) != 0)
		{
			return QueueBack(obj->q2);
		}
		else
		{
			return QueueBack(obj->q1);
		}
	}
	else
		return 0;
}


void myStackFree(MyStack* obj) {
	QueueDestroy(obj->q1);
	QueueDestroy(obj->q2);
}