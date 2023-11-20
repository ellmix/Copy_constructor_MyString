#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;




//�������� � ������ MyString (��. ���������� ��) ����������� �����������

class MyString {
private:
    char* data;
    int length;
    static int objectCount;

public:
    //� ����������� �� ���������, ����������� �������
    //  ������ ������ 80 ��������;
    MyString() : length(80) {
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = '\0';
        }
        ++objectCount;
    }

    //� �����������, ����������� ��������� ������ ������������� �������
    MyString(int size) : length(size) {
        data = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            data[i] = '\0';
        }
        ++objectCount;
    }

    //� �����������, ������� ������ ������ � �������������� � �������, ���������� � ���� ��������� ����� ������������;
    MyString(const char* str) : length(strlen(str)) {
        data = new char[length + 1];
        strcpy(data, str);
        ++objectCount;
    }

    // ����������� �����������
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        strcpy(data, other.data);
        ++objectCount;
    }

    // ����������� �����������
    MyString(MyString&& other)
        : data(nullptr), length(0) {
        cout << "����������� �����������" << endl;
        swap(data, other.data);
        swap(length, other.length);
        ++objectCount;
    }

    //������ ����� � ������
    void inputString() {
        cout << "������� ������: ";
        cin.getline(data, length + 1);
    }

    void outputString() const {
        cout << "������: " << data << endl;
    }

    // ����������
    ~MyString() {
        delete[] data;
        --objectCount;
    }

    // ����������� ������� ��� �������� ���������� ��������� �������� �����
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

    //����������� �����������
    MyString str5 = MyString("Temporary");
    str5.outputString();


    cout << "���������� ��������� ��������-�����: " << MyString::getObjectCount() << endl;

    return 0;
}