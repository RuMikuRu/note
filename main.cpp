#include <iostream>
#include "note/Note.h"
#include "note/Note.cpp"
#include <fstream>
#include <string>

using namespace std;

void Print(Note *basa_note, int N)
{
    for(int i = 0; i < N; i++) {
        cout << " Фаимилия и Имя: "         << basa_note[i].getName()     << endl;
        cout << "Телефон: "    << basa_note[i].getNumber()     << endl;
        cout << "Адрес: "      << basa_note[i].getBirthday()      << endl;

    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    char check;
    string fileName, rozdelitel, info_plateg, name;
    string name_plat;
    int d1, d2, d3, number,birthday[3];
    double input_sum = 0;
    unsigned int n, current_size = 0;
    Note input_of_keyboard;
    Note basa_note[1000];
    do {
        RETURN_MENU:
        cout << "1. Создать файл " << endl;
        cout << "2. Загрузить данные файла " << endl;
        cout << "3. Добавить запись в файл " << endl;
        cout << "4. Вывод на экран по упорядоченным записям  номера телефона" << endl;
        cout << "5. Информация о человеке " << endl;
        cout << "6. поиск всех людей, живущих на определенной улице" << endl;
        cout << "7. Поиск телефонов по фамилиям, начинающейся с определенной буквы" << endl;
        cout << "8. Выход " << endl;
        cin >> check;
        switch (check) {
            case '1': {
                cout << "Введите имя файла" << endl;
                cin >> fileName;
                fileName += ".txt";
                ofstream out(fileName.c_str());        // создание файла
                out.imbue(std::locale(
                        "rus_rus.1251"));// эта строчка означает что у файле может быть записан русский текст
                cout << "Введите количество записей " << endl;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << endl << endl;
                    // cin.get();
                    cout << "Введите фамилию и имя ";
                    cin >> name;
                    input_of_keyboard.setName(name);
                    cout << "Введите телефон ";
                    cin >> number;
                    input_of_keyboard.setNumber(number);
                    cout<<"Введите день рождения";
                    cin>>birthday[0]>>birthday[1]>>birthday[2];
                    input_of_keyboard.setBirthday(birthday);
                    cin.get();

                    out << input_of_keyboard.getName() << " " << input_of_keyboard.getNumber() << endl;
                }
                out.close(); // закрываем файл
                cout << "Файл " << fileName << " успешно создано " << endl;
            }
                break;
            case '2':
            {
                cout << "Введите имя файла для открытия " << endl; cin >> fileName;
                fileName += ".txt";
                ifstream in(fileName.c_str());          // открываем файл
                in.imbue(std::locale("rus_rus.1251"));  // указываем что там может быть русский текст
                if(!in.is_open()) {
                    cout << "Ошибка открытия файла! Проверьте имя и его расположение!";
                    goto RETURN_MENU;
                }
                while(!in.eof()) // пока не конец файла читаем данные
                {
                    in >> name;
                    basa_note[current_size].setName(name);
                    in >> number;
                    basa_note[current_size].setNumber(number);
                    getline(in,rozdelitel);
                    in>>birthday[0];
                    in>>birthday[1];
                    in>>birthday[2];
                    basa_note[current_size].setBirthday(birthday);
                    current_size++;
                }
                current_size--;
                in.close();
                Print(basa_note,current_size); // выводим на экран все данные
            }
                break;
            
        }
    }
    while(check!='0');
    return 0;
}
