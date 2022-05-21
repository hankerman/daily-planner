#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;



struct affairs {

	string name;
	int priority;
	string description;
	int day;
	int month;
	int year;
	int hour;
	int minutes;

};

void print_time(affairs aff) {
	if (aff.hour < 10 && aff.minutes < 10) {
		cout << '0' << aff.hour << ':' << '0' << aff.minutes << endl;
	}
	else if (aff.hour < 10 && aff.minutes > 9) {
		cout << '0' << aff.hour << ':' << aff.minutes << endl;
	}
	else if (aff.hour > 9 && aff.minutes < 10) {
		cout << aff.hour << ':0' << aff.minutes << endl;
	}
	else {
		cout << aff.hour << ':' << aff.minutes << endl;
	}
}

void print_affairs(affairs aff) {

	cout << "Название дела: " << aff.name << endl;
	cout << "Приоретет(1-10): " << aff.priority << endl;
	cout << "Описание: " << aff.description << endl;
	cout << "Дата: " << aff.day << "." << aff.month << "." << aff.year << endl;
	cout << "Время: ";
	print_time(aff);

}

int check_priority(affairs aff) {
	int temp = aff.priority;
	int n = 1;
	while (n != 0) {
		if (temp < 11) {
			if (temp > 0) {
				n = 0;
			}
			
		}
		else {
			cout << "Не коректно введеный приоретет, введите еще раз" << endl;
			cout << "Введите приоретет дела: ";
			cin >> temp;
		}
	}
	return temp;
}

int check_month(affairs aff) {

	int temp = aff.month;
	int n = 1;

	while (n != 0)
	{
		if (temp > 0 && temp < 13) {
			n = 0;
		}
		else {
			cout << "Не коректно введеный день даты, нужно от 1 до 31, введите еще раз" << endl;
			cout << "Введите день дела: ";
			cin >> temp;
		}
	}
	return temp;
}

int check_day(affairs &aff) {

	int temp = aff.day;
	int n = 1;
	int temp2 = aff.month;

	while (n != 0) {

		if (temp2 == 1 || temp2 == 3 || temp2 == 5 || temp2 == 7 || temp2 == 8 || temp2 == 10 || temp2 == 12) {
			if (temp > 0 && temp < 32) {
				n = 0;
			}
			else {
				cout << "Не коректно введеный день даты, нужно от 1 до 31, введите еще раз" << endl;
				cout << "Введите день дела: ";
				cin >> temp;
			}
			
		}
		else if (temp2 == 4 || temp2 == 6 || temp2 == 9 || temp2 == 11) {
			if (temp > 0 && temp < 31) {
				n = 0;
			}
			else {
				cout << "Не коректно введеный день даты, нужно от 1 до 30, введите еще раз" << endl;
				cout << "Введите день дела: ";
				cin >> temp;
			}
		}
		else if (temp2 == 2) {

			if (temp > 0 && temp < 29) {
				n = 0;
			}
			cout << "Не коректно введеный день даты, нужно от 1 до 29, введите еще раз" << endl;
			cout << "Введите день дела: ";
			cin >> temp;
		}
		else {
			cout << "Не коректно введенный месяц." << endl;
			cout << "Введите от 1 до 12" << endl;
			cin >> temp2;
			aff.month = temp2;
		}
	}

	return temp;
}

int check_hour(affairs aff) {
	int temp = aff.hour;
	int num = 1;

	while (num) {
		if (temp < 0 || temp > 23) {
			cout << "не правильный формат, введите заново" << endl;
			cin >> temp;
		}
		else {
			num = 0;
		}
	}
	return temp;
}

int check_minut(affairs aff) {

	int temp = aff.minutes;
	int num = 1;

	while (num) {
		if (temp < 0 || temp > 60) {
			cout << "не правильный формат, введите заново" << endl;
			cin >> temp;
		}
		else {
			num = 0;
		}
	}
	return temp;
}

affairs creat_affairs() {

	affairs aff;

	cout << "Введите название дела: ";
	_getch();
	getline(cin, aff.name);
	cout << "Введите приоретет дела: ";
	cin >> aff.priority;
	aff.priority = check_priority(aff);
	cout << "Введите описание дела: " << endl;
	getline(cin, aff.description);
	getline(cin, aff.description);
	cout << "Введите дату: " << endl;	
	cout << "Введите год: ";
	cin >> aff.year;
	cout << "Введите месяц: ";
	cin >> aff.month;
	aff.month = check_month(aff);
	cout << "Введите день: ";
	cin >> aff.day;
	aff.day = check_day(aff);	
	cout << "Введите время:" << endl;
	cout << "Введите час: ";
	cin >> aff.hour;
	check_hour(aff);
	cout << "Введите минуты: ";
	cin >> aff.minutes;
	check_minut(aff);

	return aff;
}

