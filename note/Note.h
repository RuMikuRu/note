//
// Created by Erishkegal on 11.09.2021.
//
#include <iostream>
using namespace std;
#ifndef NOTE_NOTE_H
#define NOTE_NOTE_H


class Note {
private:
    string Name;
    int number{};
    int birthday[3]{};

public:
    Note(string Name, int number, int birthday[]);

    void setName(const string &name);

    void setNumber(int number);

    void setBirthday(int *birthday);

    const string &getName() const;

    int getNumber() const;

    const int *getBirthday() const;

    Note();
};


#endif //NOTE_NOTE_H
