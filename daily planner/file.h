#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "collection_affairs.h"
#include "configurations.h"

using namespace std;

string path = "affairs.txt";
int count_aff = 0;

void save_aff(affairs aff) {
    
    ofstream fout;
    fout.open(path, ofstream::app);
        
    fout << aff.name << endl;
    fout << aff.priority << endl;
    fout << aff.description << endl;
    fout << aff.day << endl;
    fout << aff.month << endl;
    fout << aff.year << endl;
    fout << aff.hour << endl;
    fout << aff.minutes << endl;

    fout.close();
}

affairs* read_affs() {

    affairs* aff;
    string buf;
    ifstream fin;
    fin.open(path);

    affairs bufer;

    if (fin.is_open()) {
        cout << "File Open" << endl << endl;
    }
    fin >> ::count_aff;
    

    aff = new affairs[count_aff];

    for (int i = 0; i < count_aff; i++){

        buf = " ";
        getline(fin, buf);
        if (buf == "") {
            getline(fin, buf);
        }
        bufer.name = buf;
        fin >> bufer.priority;
        buf = " ";        
        getline(fin, buf);
        if (buf == "") {
            getline(fin, buf);
        }
        
        bufer.description = buf;
        fin >> bufer.day;
        fin >> bufer.month;
        fin >> bufer.year;
        fin >> bufer.hour;
        fin >> bufer.minutes;

        aff[i] = bufer;

    }

    fin.close();

    return aff;
}

void save_affs(affairs* aff, int count_aff) {

    ofstream fout;
    fout.open(path);

    fout << count_aff << endl;

    for (int i = 0; i < count_aff; i++) {
        fout << aff[i].name << endl;
        fout << aff[i].priority << endl;
        fout << aff[i].description << endl;
        fout << aff[i].day << endl;
        fout << aff[i].month << endl;
        fout << aff[i].year << endl;
        fout << aff[i].hour << endl;
        fout << aff[i].minutes << endl;
    }
    

    fout.close();

}