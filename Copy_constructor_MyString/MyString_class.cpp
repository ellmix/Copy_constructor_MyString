#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;




//Добавить к классу MyString (см. предыдущие ДЗ) конструктор перемещения

class MyString {
private:
    char* data;
    int length;
    static int objectCount;

public:
    //• Конструктор по умолчанию, позволяющий создать
    //  строку длиной 80 символов;
    MyString() : length(80) {
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = '\0';
        }
        ++objectCount;
    }

    //• Конструктор, позволяющий создавать строку произвольного размера
    MyString(int size) : length(size) {
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = '\0';
        }
        ++objectCount;
    }

    //• Конструктор, который создаёт строку и инициализирует её строкой, полученной в виде параметра этого конструктора;
    MyString(const char* str) : length(strlen(str)) {
        data = new char[length + 1];
        strcpy(data, str);
        ++objectCount;
    }

    // Конструктор копирования
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        strcpy(data, other.data);
        ++objectCount;
    }

    // Конструктор перемещения
    MyString(MyString&& other)
        : data(nullptr), length(0) {
        cout << "Конструктор перемещения" << endl;
        swap(data, other.data);
        swap(length, other.length);
        ++objectCount;
    }

    //методы ввода и показа
    void inputString() {
        cout << "Введите строку: ";
        cin.getline(data, length + 1);
    }

    void outputString() const {
        cout << "Строка: " << data << endl;
    }

    // Деструктор
    ~MyString() {
        delete[] data;
        --objectCount;
    }

    // Статическая функция для возврата количества созданных объектов строк
    static int getObjectCount() {
        return objectCount;
    }
};

int MyString::objectCount = 0;

int main() {
    setlocale(LC_ALL, "");
    MyString str1;
    str1.outputString();

    MyString str2(100);
    str2.inputString();
    str2.outputString();

    MyString str3("dffdffgdf  dfdf");
    str3.outputString();

    MyString str4 = str3;
    str4.outputString();

    //Конструктор перемещения
    MyString str5 = MyString("Temporary");
    str5.outputString();


    cout << "Количество созданных объектов-строк: " << MyString::getObjectCount() << endl;

    return 0;
}