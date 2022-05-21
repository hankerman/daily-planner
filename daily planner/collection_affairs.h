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
			cout << "������� ����� ��������:" << endl;
			getline(cin, aff.name);
		}
		else if (key == "editPriority") {
			cout << "-------------" << endl;
			cout << aff.priority << endl;
			cout << "-------------" << endl;
			cout << "������� ����� ���������:" << endl;
			cin >> aff.priority;
		}
		else if (key == "editDescription") {
			cout << "-------------" << endl;
			cout << aff.description << endl;
			cout << "-------------" << endl;
			cout << "������� ����� ��������:" << endl;
			getline(cin, aff.description);
		}
		else if (key == "editDate") {
			cout << "-------------" << endl;
			cout << aff.day << '.' << aff.month << '.' << aff.year << endl;
			cout << "-------------" << endl;
			cout << "������� ����� ����:" << endl;
			cout << "������� ���: ";
			cin >> aff.year;
			cout << "������� �����: ";
			cin >> aff.month;
			aff.month = check_month(aff);
			cout << "������� ����: ";
			cin >> aff.day;
			aff.day = check_day(aff);
		}
		else if (key == "editTime") {
			cout << "----------------------------" << endl;
			print_time(aff);
			cout << "----------------------------" << endl;
			cout << "������� ����� �����:" << endl;
			cout << "������� ���: ";
			cin >> aff.hour;
			check_hour(aff);
			cout << "������� ������: ";
			cin >> aff.minutes;
			check_minut(aff);
		}
		else if (key == "help") {
			cout << "-------------------------" << endl;
			cout << "�������� �������� ���� - editName" << endl;
			cout << "�������� ��������� - editPriority" << endl;
			cout << "�������� �������� - editDescription" << endl;
			cout << "�������� ���� - editDate" << endl;
			cout << "�������� ����� - editTime" << endl;
			cout << "��������� - help" << endl;
			cout << "����� ��������� - editEnd" << endl;
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
			cout << "help - ������ ������" << endl;
			cout << "find /name - ����� �� �����" << endl;
			cout << "find /priority - ����� �� ����������" << endl;
			cout << "find /description - ����� �� ��������" << endl;
			cout << "find / time - ����� �� ������� � ����" << endl;
			cout << "print - ����� ���� ���" << endl;
			cout << "end - ����� ������" << endl;
		}
		else if (res == "find /name") {
			cout << "������� ��� ��� ������" << endl;
			getline(cin, temp);
			find_name(aff, count_aff, temp);
		}
		else if (res == "find /priority") {
			cout << "������� ��������� ��� ������" << endl;
			cin >> buf;
			find_priority(aff, count_aff, buf);

		}
		else if (res == "find /description") {
			cout << "������� �������� ���� ��� ������" << endl;
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
			cout << "������� �� �������, help ��� �������" << endl;
		}

	} while (flag);

}