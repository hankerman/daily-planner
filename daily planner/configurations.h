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

	cout << "�������� ����: " << aff.name << endl;
	cout << "���������(1-10): " << aff.priority << endl;
	cout << "��������: " << aff.description << endl;
	cout << "����: " << aff.day << "." << aff.month << "." << aff.year << endl;
	cout << "�����: ";
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
			cout << "�� �������� �������� ���������, ������� ��� ���" << endl;
			cout << "������� ��������� ����: ";
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
			cout << "�� �������� �������� ���� ����, ����� �� 1 �� 31, ������� ��� ���" << endl;
			cout << "������� ���� ����: ";
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
				cout << "�� �������� �������� ���� ����, ����� �� 1 �� 31, ������� ��� ���" << endl;
				cout << "������� ���� ����: ";
				cin >> temp;
			}
			
		}
		else if (temp2 == 4 || temp2 == 6 || temp2 == 9 || temp2 == 11) {
			if (temp > 0 && temp < 31) {
				n = 0;
			}
			else {
				cout << "�� �������� �������� ���� ����, ����� �� 1 �� 30, ������� ��� ���" << endl;
				cout << "������� ���� ����: ";
				cin >> temp;
			}
		}
		else if (temp2 == 2) {

			if (temp > 0 && temp < 29) {
				n = 0;
			}
			cout << "�� �������� �������� ���� ����, ����� �� 1 �� 29, ������� ��� ���" << endl;
			cout << "������� ���� ����: ";
			cin >> temp;
		}
		else {
			cout << "�� �������� ��������� �����." << endl;
			cout << "������� �� 1 �� 12" << endl;
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
			cout << "�� ���������� ������, ������� ������" << endl;
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
			cout << "�� ���������� ������, ������� ������" << endl;
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

	cout << "������� �������� ����: ";
	_getch();
	getline(cin, aff.name);
	cout << "������� ��������� ����: ";
	cin >> aff.priority;
	aff.priority = check_priority(aff);
	cout << "������� �������� ����: " << endl;
	getline(cin, aff.description);
	getline(cin, aff.description);
	cout << "������� ����: " << endl;	
	cout << "������� ���: ";
	cin >> aff.year;
	cout << "������� �����: ";
	cin >> aff.month;
	aff.month = check_month(aff);
	cout << "������� ����: ";
	cin >> aff.day;
	aff.day = check_day(aff);	
	cout << "������� �����:" << endl;
	cout << "������� ���: ";
	cin >> aff.hour;
	check_hour(aff);
	cout << "������� ������: ";
	cin >> aff.minutes;
	check_minut(aff);

	return aff;
}

