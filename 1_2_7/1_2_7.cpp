// 1_2_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "Queue.h"
#include <ctime>
#include <windows.h> 
#include <conio.h>


int main()
{
	setlocale(LC_ALL, "RU");
	Queue* pFirst;
	Queue* pLast;

	init(pFirst, pLast);


	char key = 'k';
	int how_many;
	while (key != 'q')
	{
		int random = rand() % 100 + 1;
		if (random % 2 != 0)
		{
			std::cout << "\tОперация удаления." << std::endl;

			how_many = rand() % 3 + 1;
			how_many = removeElements(pFirst, pLast, how_many);
			
			if (how_many)
			{
				std::cout << "Было удалено элементов: " << how_many << std::endl;
			}

		}
		else
		{
			std::cout << "\tОперация добавления" << std::endl;
			how_many = rand() % 3 + 1;
			AddElements(pFirst, pLast, how_many);
			std::cout << "Было добавлено элементов: " << how_many << std::endl;
		}

		show(pFirst, pLast);
		Sleep(2000);
		std::cout << std::endl;
		std::cout << "\t\t\t\tНажмите q для выхода " << std::endl;

		if (_kbhit()) { key = _getch(); }
	}

	std::cout << "\nЗавершение работы\n";
	clear_memory(pFirst);
}
