//
// Created by Erishkegal on 11.09.2021.
//

#include "Note.h"


Note::Note(string Name, int number, int *birthday) {
    this->Name = Name;
    this->number = number;
    for(int i=0;i<3;i++)
        this->birthday[i] = birthday[i];
}

void Note::setName(const string &name) {
    this->Name = name;
}


void Note::setNumber(int number) {
    Note::number = number;
}

const string &Note::getName() const {
    return Name;
}

int Note::getNumber() const {
    return number;
}

const int *Note::getBirthday() const {
    return birthday;
}

void Note::setBirthday(int *birthday) {
    this->birthday[0] = birthday[0];
    this->birthday[1] = birthday[1];
    this->birthday[2] = birthday[2];
}

Note::Note() = default;
