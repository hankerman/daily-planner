#include <iostream>
#include <fstream>
#include <string>
#include "collection_affairs.h"
#include "file.h"

using namespace std;

int main()
{
    
    setlocale(LC_ALL, "ru");
    
    affairs* aff = nullptr;
    aff = read_affs();
    bool flag = true;
    string actions;
    

    while (flag) {

        getline(cin, actions);

        if (actions == "help") {
            cout << "help - список команд;" << endl;
            cout << "exit - выход;" << endl;
            cout << "addaff - добавить дело;" << endl;
            cout << "save - перезаписать дела;" << endl;
            cout << "print - вывести дела;" << endl;
            cout << "editaff - редактировать дело" << endl;
            cout << "find - поиск по списку дел" << endl;
        }
        else if (actions == "exit") {
            flag = false;
        }
        else if (actions == "addaff") {
            add_affairs(aff, count_aff);
        }
        else if (actions == "save") {
            save_affs(aff, count_aff);
        }
        else if (actions == "print") {
            print_collection(aff, count_aff);
        }
        else if (actions == "editaff") {
            int n;
            cout << "Введите номер дела: ";
            cin >> n;
            editing_affairs(aff[n]);
        }
        else if (actions == "find") {
            find(aff, count_aff);
        }
        else {
            cout << "Не верная команда, попробуйте еще раз или введите help." << endl;
        }

    }

    delete[] aff;

}

