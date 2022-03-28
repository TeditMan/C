#include <iostream>

int main()
{
    int a = 10;
    int b = 6;

    int *p = 0;     // указатель
    int *&pRef = p;     // ссылка на указатель
    pRef = &a;          // через ссылку указателю p присваивается адрес переменной a
    std::cout << "p value=" << *p << std::endl;   // 10
    *pRef = 70;         // изменяем значение по адресу, на который указывает указатель
    std::cout << "a value=" << a << std::endl;    // 70

    pRef = &b;          // изменяем адрес, на который указывает указатель
    std::cout << "p value=" << *p << std::endl;   // 6

    return 0;
}