#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "configurations.h"
#include "file.h"

using namespace std;



affairs* creat_affairs(affairs* aff, int& size) {

	aff = new affairs[size];

	for (int i = 0; i < size; i++) {
		aff[i] = creat_affairs();
	}

	return aff;
}

affairs* add_affairs(affairs* aff, int& size) {

	affairs* temp = new affairs[size + 1];

	for (int i = 0; i < size; i++) {
		temp[i] = aff[i];
	}

	temp[size] = creat_affairs();
	delete[] aff;
	size++;
	return temp;
}

void print_collection(affairs* aff, int size) {

	for (int i = 0; i < size; i++) {
		cout << "---------------------------------------" << endl;
		cout << i << ")" << endl;
		print_affairs(aff[i]);
		cout << "---------------------------------------" << endl;
	}

}

affairs* editing_affairs(affairs aff) {
			
	//enum key { editName, editPriority, editDescription, editDate, editTime, help, editEnd };
	int num = 1;
	string key;

	while (num != 0) {
		
		cout << "---------------------" << endl;
		getline(cin, key);

		if (key == "editName") {
			cout << "-------------" << endl;
			cout << aff.name << endl;
			cout << "-------------" << endl;
			cout << "Введите новое название:" << endl;
			getline(cin, aff.name);
		}
		else if (key == "editPriority") {
			cout << "-------------" << endl;
			cout << aff.priority << endl;
			cout << "-------------" << endl;
			cout << "Введите новый приоретет:" << endl;
			cin >> aff.priority;
		}
		else if (key == "editDescription") {
			cout << "-------------" << endl;
			cout << aff.description << endl;
			cout << "-------------" << endl;
			cout << "Введите новое описание:" << endl;
			getline(cin, aff.description);
		}
		else if (key == "editDate") {
			cout << "-------------" << endl;
			cout << aff.day << '.' << aff.month << '.' << aff.year << endl;
			cout << "-------------" << endl;
			cout << "Введите новую дату:" << endl;
			cout << "Введите год: ";
			cin >> aff.year;
			cout << "Введите месяц: ";
			cin >> aff.month;
			aff.month = check_month(aff);
			cout << "Введите день: ";
			cin >> aff.day;
			aff.day = check_day(aff);
		}
		else if (key == "editTime") {
			cout << "----------------------------" << endl;
			print_time(aff);
			cout << "----------------------------" << endl;
			cout << "Введите новое время:" << endl;
			cout << "Введите час: ";
			cin >> aff.hour;
			check_hour(aff);
			cout << "Введите минуты: ";
			cin >> aff.minutes;
			check_minut(aff);
		}
		else if (key == "help") {
			cout << "-------------------------" << endl;
			cout << "Изменить название дела - editName" << endl;
			cout << "Изменить приоретет - editPriority" << endl;
			cout << "Изменить описание - editDescription" << endl;
			cout << "Изменить дату - editDate" << endl;
			cout << "Изменить время - editTime" << endl;
			cout << "Подсказка - help" << endl;
			cout << "Конец изменений - editEnd" << endl;
		}
		else if (key == "editEnd") {
			num = 0;
		}

	}
	
	return 0;
}

void find_name(affairs* aff, int count_aff, string temp) {

	

	for (int i = 0; i < count_aff; i++) {
		if (aff[i].name == temp) {
			cout << i << ')' << endl;
			cout << aff[i].name << endl;
			cout << endl;
		}
	}

}

void find_priority(affairs* aff, int count_aff, int priority) {

	for (int i = 0; i < count_aff; i++) {
		if (aff[i].priority == priority) {
			cout << i << ')' << endl;
			print_affairs(aff[i]);
			cout << endl;
		}
	}
}

void find_description(affairs* aff, int count_aff, string temp) {

	string buf;

	for (int i = 0; i < count_aff; i++) {
		buf = aff[i].description;
		if (buf.find(temp)) {
			cout << i << ')' << endl;
			print_affairs(aff[i]);
			cout << endl;
		}
	}

}

void find(affairs* aff, int count_aff) {

	string res, temp;
	bool flag = true;
	int buf;

	do {

		if (res == "help") {
			cout << "help - список команд" << endl;
			cout << "find /name - поиск по имени" << endl;
			cout << "find /priority - поиск по приоретету" << endl;
			cout << "find /description - поиск по описанию" << endl;
			cout << "find / time - поиск по времени и дате" << endl;
			cout << "print - вывод всех дел" << endl;
			cout << "end - конец поиска" << endl;
		}
		else if (res == "find /name") {
			cout << "Введите имя для поиска" << endl;
			getline(cin, temp);
			find_name(aff, count_aff, temp);
		}
		else if (res == "find /priority") {
			cout << "Введите приоритет для поиска" << endl;
			cin >> buf;
			find_priority(aff, count_aff, buf);

		}
		else if (res == "find /description") {
			cout << "Введите описание дела для поиска" << endl;
			getline(cin, temp);
			find_description(aff, count_aff, temp);
		}
		else if (res == "find /time") {

		}
		else if (res == "end") {
			flag = false;
		}
		else if (res == "print") {
			print_collection(aff, count_aff);
		}
		else {
			cout << "Команда не найдена, help для справки" << endl;
		}

	} while (flag);

}