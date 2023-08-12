#define _CRT_SECURE_NO_WARNINGS 1
#include"queque.h"
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->rear = q->front=NULL;
}
// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
DATATYPE QueueFront(Queue* q)
{
	assert(q);
	assert(q->front && q->rear);
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
DATATYPE QueueBack(Queue* q)
{
	assert(q);
	assert(q->front && q->rear);
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL)
		return 1;
	else
		return 0;
}
// ���ٶ��� 
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