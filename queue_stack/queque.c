#define _CRT_SECURE_NO_WARNINGS 1
#include"queque.h"
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->rear = q->front=NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, DATATYPE data)
{
	assert(q);
	QListNode* newnode = NULL;
	QListNode* temp = (QListNode*)malloc(sizeof(QListNode));
	if (temp == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	newnode = temp;
	newnode->data = data;
	newnode->next = NULL;
	if (q->front != NULL)
	{

		q->rear->next = newnode;
		q->rear = newnode;
	}
	else
	{
		q->rear=q->front = newnode;
	}
	temp = NULL;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front && q->rear);
	if (q->front == q->rear)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QListNode* temp = q->front->next;
		free(q->front);
		q->front = temp;
	}
}
// 获取队列头部元素 
DATATYPE QueueFront(Queue* q)
{
	assert(q);
	assert(q->front && q->rear);
	return q->front->data;
}
// 获取队列队尾元素 
DATATYPE QueueBack(Queue* q)
{
	assert(q);
	assert(q->front && q->rear);
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QListNode* cur = q->front;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return 1;
	else
		return 0;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QListNode* cur = q->front;
	while (cur != NULL)
	{
		QListNode* del = cur;
		cur = cur->next;
		free(del);
	}
}