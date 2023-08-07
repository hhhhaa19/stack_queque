#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define DATATYPE int
//ջ�������ݽṹ���ڳ�����Ҫβ�壬βɾ����˳���ʵ��Ч�ʸ���
typedef struct stack
{
	int top;//ջ��,������size
	int capacity;
	DATATYPE* data;
}stack;

//��ʼ��
stack* initstack(void);
//push
void pushstack(stack* head,DATATYPE x);
//pop
void popstack(stack* head);
//��ȡջ��Ԫ��
DATATYPE stacktop(stack* head);
void destroystack(stack* head);
int StackEmpty(stack* head);
