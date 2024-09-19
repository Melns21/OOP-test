#pragma once
#ifndef STRUCT_h
#define STRUCT_h
struct Flower {
	char name[40], type[40], color[40];
	int price, length;
};
#endif STRUCT_h

-------------------------------------------------------------

#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;
void menu()
{
	cout << "Меню:" << endl;
	cout << "1. Добавить запись" << endl;
	cout << "2. Просмотреть все записи" << endl;
	cout << "3. Поиск по записям" << endl;
	cout << "4. Выход" << endl;
	cout << "Выберите действие: ";
}
#endif MENU_H

-----------------------------------------------------------------

#pragma once
#ifndef EXIT_H
#define EXIT_H
#include <iostream>
using namespace std;
bool exit() {
	return false;
}
#endif EXIT_H

-----------------------------------------------------------------

#pragma once
#ifndef POISK_H
#define POISK_H
#include <iostream>
#include <string>
using namespace std;
void poisk(const char* doc, Flower flower)
{
	ifstream file;
	bool found = false;
	string name1, model2, type1, color1;
	double numb;
	int filter_option;
	cout << "Фильтры:\n"
		<< "\t1 - Поиск по названию цветка\n"
		<< "\t2 - Поиск по длине\n"
		<< "\t3 - Поиск по цвету\n"
		<< "\t4 - Поиск по цене\n"
		<< "\t5 - Поиск по типу\n";
	cout << "Какой фильтр применить? "; cin >> filter_option;
	switch (filter_option) // выбор фильтра поиска
	{
	case 1: // Поиск по названию цветка
		getchar();
		found = false;
		cout << "Введите название цветка для поиска: ";
		getline(cin, name1);
		file.open(doc, ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Название\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
			while (true)
			{
				file.read((char*)&flower, sizeof(Flower));
				if (!file.eof()) {
					if (flower.name == name1) {
						cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" << flower.type << endl;
						found = true;
					}
				}
				else
					break;
			}
			if (!found)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	case 2: // Поиск по длине
		getchar();
		found = false;
		int minDL, maxDL;
		cout << "Введите минимальную длину: ";
		cin >> minDL;
		cout << "Введите максимальную длину: ";
		cin >> maxDL;
		file.open(doc, ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Название\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
			while (true)
			{
				file.read((char*)&flower, sizeof(Flower));
				if (!file.eof()) {
					if (flower.length >= minDL && flower.length <= maxDL) {
						cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" << flower.type << endl;
						found = true;
					}
				}
				else
					break;
			}
			if (!found)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	case 3: // Поиск по цвету
		getchar();
		found = false;
		cout << "Введите цвет цветка для поиска: ";
		getline(cin, color1);
		file.open(doc, ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Название\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
			while (true)
			{
				file.read((char*)&flower, sizeof(Flower));
				if (!file.eof()) {
					if (flower.color == color1) {
						cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" << flower.type << endl;
						found = true;
					}
				}
				else
					break;
			}
			if (!found)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	case 4: // Поиск по цене
		getchar();
		int oper; // выбор подфильтра
		file.open(doc, ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Выберите операцию: \n1) =\n2) >=\n3) <=\n"; cin >> oper; // выбор подфильтра
			switch (oper) // поиск по подфильтру
			{
			case 1: // если введенное значние == заданному
				cout << "Введите цену: "; cin >> numb;
				cout << "Название\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
				while (true)
				{
					file.read((char*)&flower, sizeof(Flower));
					if (!file.eof()) {
						if (flower.price == numb)
						{
							cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" << flower.type << endl;
							found = true;
						}
					}
					else
						break;
				}
				if (!found)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			case 2: // если значние >= заданного
				cout << "Введите цену: "; cin >> numb;
				cout << "Название\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
				while (true)
				{
					file.read((char*)&flower, sizeof(Flower));
					if (!file.eof()) {
						if (flower.price >= numb)
						{
							cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" << flower.type << endl;
							found = true;
						}
					}
					else
						break;
				}
				if (!found)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			case 3: // если значние <= заданного
				cout << "Введите цену: "; cin >> numb;
				cout << "Название\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
				while (true)
				{
					file.read((char*)&flower, sizeof(Flower));
					if (!file.eof()) {
						if (flower.price <= numb)
						{
							cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" << flower.type << endl;
							found = true;
						}
					}
					else
						break;
				}
				if (!found)
					cout << "Записей не найдено.\n";
				file.close();
				break;
			default:
				break;
			}
		}
		break;
	case 5: // Поиск по типу
		getchar();
		found = false;
		cout << "Введите тип цветка для поиска: ";
		getline(cin, type1);
		file.open(doc, ios_base::in | ios_base::binary);
		if (!file.is_open())
			cout << "Файл не может быть открыт!\n";
		else {
			cout << "Название\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
			while (true)
			{
				file.read((char*)&flower, sizeof(Flower));
				if (!file.eof()) {
					if (flower.type == type1) {
						cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" << flower.type << endl;
						found = true;
					}
				}
				else
					break;
			}
			if (!found)
				cout << "Записей не найдено.\n";
			file.close();
			break;
		}
	default:
		break;
	}
}
#endif POISK_H

-------------------------------------------------------------------------------------------

#pragma once
#ifndef ADD_H
#define ADD_H
#include <iostream>
using namespace std;
void add(const char* doc, Flower flower)
{
	fstream file;
	file.open(doc, ios_base::app | ios_base::binary);
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		file.write((char*)&flower, sizeof(Flower));
	}
	file.close();
}
#endif ADD_H

-------------------------------------------------------------------------------------------------

#pragma once
#ifndef PROSMOTR_H
#define PROSMOTR_H
#include <iostream>
using namespace std;
void prosmotr(const char* doc, Flower flower)
{
	ifstream file;
	file.open(doc, ios_base::in | ios_base::binary);
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else {
		cout << "\tВсе записи:\nНазвание\tДлина\t\tЦвет\t\tЦена\t\tТип цветка\n";
		while (true)
		{
			file.read((char*)&flower, sizeof(Flower));
			if (!file.eof())
				cout << flower.name << "\t\t" << flower.length << "\t\t" << flower.color << "\t\t" << flower.price << "\t\t" <<
				flower.type << endl;
			else
				break;
		}
		file.close();
	}
}
#endif PROSMOTR_H

----------------------------------------------------------------------------


#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "data.h"
#include "Menu.h"
#include "error.h"
#include "Pro.h"
#include "Poi.h"
#include "Exit.h"
using namespace std;
Flower flower;
int main()
{
	setlocale(LC_ALL, "rus");
	fstream file;
	bool f = true;
	const char* doc = "C:\\Users\\shmon\\source\\repos\\Lin3\\flover2.txt";
	int choice;
	while (f) {
		menu(); // вызов меню
		cin >> choice;
		switch (choice)
		{
		case 1: // Добавление записи
			getchar();
			cout << "Введите название цветка: ";
			cin.getline(flower.name, 40);
			cout << "Введите тип цветка: ";
			cin.getline(flower.type, 40);
			cout << "Введите цену цветка: ";
			cin >> flower.price;
			cout << "Введите длину цветка: ";
			cin >> flower.length;
			cout << "Введите цвет цветка: ";
			cin >> flower.color;
			add(doc, flower);
			break;
		case 2: // Просмотр записей
			prosmotr(doc, flower); // Prosmotr.h
			break;
		case 3: // Поиск записей
			poisk(doc, flower); // Poisk.h
			break;
		case 4: // Выход
			f = exit();
			break;
		default:
			cout << "Такой команды не существует, убедитесь в правильном написании" << endl;
			break;
		}
	}
	return 0;
}

