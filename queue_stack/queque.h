#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define DATATYPE int
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* next;
	DATATYPE data;
}QListNode;

// ���еĽṹ 
typedef struct Queue
{
	QListNode* front;
	QListNode* rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, DATATYPE data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
DATATYPE QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
DATATYPE QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);