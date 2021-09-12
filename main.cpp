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
    setlocale(0, "Rus");
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
            case '3':
            {
                current_size++;
                cin.get();

                cout << "Введите фамилию "; cin >> name;
                input_of_keyboard.setName(name);
                cout << "Введите телефон "; cin >> number;
                input_of_keyboard.setNumber(number);
                cin.get();
                cout << "Введите день рождения  ";
                cin>>birthday[0]>>birthday[1]>>birthday[2];
                input_of_keyboard.setBirthday(birthday);


                ofstream out(fileName.c_str(),ios::app);
                out.imbue(std::locale("rus_rus.1251"));
                out << input_of_keyboard.getName() << " " << input_of_keyboard.getNumber() << " ";
                out << input_of_keyboard.getBirthday()  << endl;

            } break;

            case '4':
            {
                // 123456789
                //  (123456789 / 100000000)  == 1
                //  (123456789 % 100000000) / 10000000 == 2
                //  (123456789 % 100000000) % 10000000 / 1000000 == 3

                for(int i = 0; i < current_size; i++)
                    for(int j = 0; j < current_size - 1; j++)
                        if(basa_note[j].getNumber() / 100000000  > basa_note[j+1].getNumber() / 100000000)
                        {
                            swap(basa_note[j],basa_note[j+1]);
                        } // || basa_note[j].tel_number % 100000000 / 10000000 > basa_note[j+1].tel_number % 100000000 / 10000000)
                        else if(basa_note[j].getNumber() / 100000000  == basa_note[j+1].getNumber() / 100000000 && basa_note[j].getNumber() % 100000000 / 10000000 > basa_note[j+1].getNumber() % 100000000 / 10000000)
                        {
                            swap(basa_note[j],basa_note[j+1]);
                        }
                Print(basa_note,current_size);
            }break;
            case '5':
            {
                bool yes = false;
                string fam;
                cout << "Введите фамилию для поиска "; cin >> fam;

                for(int i = 0; i < current_size; i++)
                    if(basa_note[i].getName() == fam)
                    {
                        cout << "Фамилия:  "   << basa_note[i].getName()     << endl;
                        cout << "Телефон: "    << basa_note[i].getNumber()     << endl;
                        cout << "Адрес: "      << basa_note[i].getBirthday()      << endl;
                        yes = true;
                    }
                if(!yes) cout << "Нету такого абонента" << endl;
            }break;

            case '6' : return 1;
            default:
                break;
        }
    }
    while(check!='0');
    return 0;
}
