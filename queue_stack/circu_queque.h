#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define DATATYPE int
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���
//ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
typedef struct MyCircularQueue 
{
	DATATYPE* data;
	int first;
	int rear;
	int k;//����
} MyCircularQueue;
//�����������ö��г���Ϊ k
MyCircularQueue* myCircularQueueCreate(int k);
// ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
bool myCircularQueueDeQueue(MyCircularQueue* obj);
//enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
int myCircularQueueFront(MyCircularQueue* obj);
//Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 
int myCircularQueueRear(MyCircularQueue* obj);
//isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//isFull(): ���ѭ�������Ƿ�������
bool myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);