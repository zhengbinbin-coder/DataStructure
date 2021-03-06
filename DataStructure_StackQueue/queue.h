#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _back; // 队尾
}Queue;

//初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}

//队尾入队列
void QueuePush(Queue* q, QUDataType x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (q->_back == NULL)
	{
		q->_front = q->_back = newnode;
	}
	else
	{
		q->_back->_next = newnode;
		q->_back = newnode;
	}
}

//队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
}

//获取队列头部元素
QUDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

//获取队列尾部元素
QUDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}

//获取队列中有效元素个数
int QueueSize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
	return n;
}

//检测队列是否为空，如果为空返回非零(1)，如果不为空返回0
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}

//销毁队列
void QueueDestroy(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = cur->_next;
	}
	q->_front = q->_back = NULL;
}

//创建一个队列节点
QueueNode* BuyQueueNode(QUDataType x);

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestroy(&q);
}