#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define DATATYPE int
//栈这种数据结构由于常常需要尾插，尾删，用顺序表实现效率更高
typedef struct stack
{
	int top;//栈顶,类似于size
	int capacity;
	DATATYPE* data;
}stack;

//初始化
stack* initstack(void);
//push
void pushstack(stack* head,DATATYPE x);
//pop
void popstack(stack* head);
//获取栈顶元素
DATATYPE stacktop(stack* head);
void destroystack(stack* head);
int StackEmpty(stack* head);
