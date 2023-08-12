#define _CRT_SECURE_NO_WARNINGS		
#include"circu_queque.h"

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if ((obj->rear) == (obj->first))
		return true;
	else
		return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->rear + 1) % (obj->k + 1) == (obj->first))
	{
		return true;
	}
	else
		return false;
}
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	queue->data = (DATATYPE*)malloc(sizeof(DATATYPE) * (k + 1));
	queue->first = queue->rear = 0;
	queue->k = k;
	return queue;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	else
	{
		obj->data[obj->rear] = value;
		obj->rear = (obj->rear + 1) % (obj->k + 1);
		return true;
	}
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	else
	{
		obj->first = (obj->first + 1) % (obj->k + 1);
		return true;

	}
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
		return obj->data[obj->first];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	else
		return obj->data[((obj->rear) - 1 + obj->k + 1) % (obj->k + 1)];
}



void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}