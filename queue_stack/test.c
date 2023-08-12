#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include"queque.h"
void test()
{
	stack stack ;
	initstack(&stack);
	pushstack(&stack, 2);
	pushstack(&stack, 3);
	pushstack(&stack, 4);
	pushstack(&stack, 5);
	pushstack(&stack, 6);
	popstack(&stack);
	destroystack(&stack);
}
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//右括号都有一个对应的相同类型的左括号。
//
bool isValid(char* s) 
{
	stack stack;
	initstack(&stack);

	while(*s)
	{//左括号入栈
		if (*s == '(' || *s == '[' || *s == '{')
			pushstack(&stack, *s);
		//右括号出栈，对应
		else
		{	//数量不匹配
			if (StackEmpty(&stack))
			{
				destroystack(&stack);
				return false;
			}
			char com = stacktop (&stack);
			popstack(&stack);
			if ((*s == '}' && com != '{')
				|| (*s == ')' && com != '(')
				|| (*s == ']' && com != '['))
			{
				destroystack(&stack);
				return false;
			}
		}
		s++;
	}
	bool ret = StackEmpty(&stack);
	destroystack(&stack);
	return ret;
}

//
void test2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	printf("%d", QueueBack(&q));
	printf("%d", QueueFront(&q));
	printf("%d", QueueSize(&q));
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d", QueueEmpty(&q));




}

int main()
{
	test();
	return 0;
}