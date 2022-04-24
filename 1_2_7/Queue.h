#pragma once
#include <iostream>

struct Queue
{
	char data;
	Queue* pNext = nullptr;
};


void init(Queue*& pFirst, Queue*& pLast);

void AddElements(Queue* pFirst, Queue*& pLast, int how_many);

int removeElements(Queue* pFirst, Queue*& pLast, int how_many);

void show(Queue* pFirst, Queue* pLast);

void clear_memory(Queue* pFirst);