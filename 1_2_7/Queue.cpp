#include <iostream>
#include "Queue.h"

void init(Queue*& pFirst, Queue*& pLast)
{
	pFirst = new Queue;
	pFirst->data = NULL;
	pFirst->pNext = nullptr;
	pLast = pFirst;

	srand(time(NULL)); std::cout << "Отсчет времени пошёл!\n";
}

void Add(Queue* pFirst, Queue*& pLast, char data)
{
	if (pFirst == pLast)
	{
		pFirst->pNext = pLast;

	}

	pLast->pNext = new Queue;
	pLast->pNext->data = data;
	pLast = pLast->pNext;
}



void AddElements(Queue* pFirst, Queue*& pLast, int how_many)
{
	for (size_t i = 0; i < how_many; i++)
	{
		char data = static_cast<char>(65 + rand() % 26);
		Add(pFirst, pLast, data);
	}

}

bool remove(Queue* pFirst, Queue*& pLast)
{
	if (pFirst == pLast)
	{
		return false;
	}
	Queue* temp = pFirst->pNext;
	pFirst->pNext = temp->pNext;
	delete temp;

	if (!(pFirst->pNext)) { pLast = pFirst; }

	return true;
}

int removeElements(Queue* pFirst, Queue*& pLast, int how_many)
{
	for (size_t i = 0; i < how_many; i++)
	{
		if (!(remove(pFirst, pLast)))
		{
			std::cout << "Очередь пустая!\n";
			return i;
		}
	}
}

void show(Queue* pFirst, Queue* pLast)
{
	if (pFirst == pLast) { return; }

	int i = 1;
	while (pFirst->pNext)
	{
		std::cout << i++ << "-й элемент очереди, данные: " << pFirst->pNext->data << std::endl;
		pFirst = pFirst->pNext;
	}
}

void clear_memory(Queue* pFirst)
{
	while (pFirst->pNext)
	{
		Queue* temp = pFirst->pNext;
		pFirst->pNext = temp->pNext;
		delete temp;
	}
	delete pFirst;
}