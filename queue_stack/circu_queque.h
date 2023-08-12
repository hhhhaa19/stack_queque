#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#define DATATYPE int
//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）
//原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
typedef struct MyCircularQueue 
{
	DATATYPE* data;
	int first;
	int rear;
	int k;//容量
} MyCircularQueue;
//构造器，设置队列长度为 k
MyCircularQueue* myCircularQueueCreate(int k);
// 从循环队列中删除一个元素。如果成功删除则返回真。
bool myCircularQueueDeQueue(MyCircularQueue* obj);
//enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
//Front: 从队首获取元素。如果队列为空，返回 -1 。
int myCircularQueueFront(MyCircularQueue* obj);
//Rear: 获取队尾元素。如果队列为空，返回 -1 
int myCircularQueueRear(MyCircularQueue* obj);
//isEmpty(): 检查循环队列是否为空。
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//isFull(): 检查循环队列是否已满。
bool myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);