#include <iostream>
#include "header.h"

//каждый класс создается по следующему шаблону
//1. структура базовая, конструкторы
//2. основные методы работы с классом
//некоторые могут остаться пустые
//3. перегрузка операций
//4. завершение работы и оформление класса
//размещение комментариев по функционалу
//5. пример работы с классом

int main()
{
    std::cout << "Hello World!\n";
    SingleLinkedList<std::string> list;
    list.PrintToConsole();
    list.Append("5");
    list.PrintToConsole();
    list.Append("5");
    list.PrintToConsole();
    list.Append("5");
    list.PrintToConsole();
    list.Append("5");
    list.PrintToConsole();
    list.Clear();
    list.PrintToConsole();

    LinkedList<int> doblist;
    doblist.PrintToConsole();
    doblist.Append(12);
    doblist.PrintToConsole();
    doblist.Append(84);
    doblist.PrintToConsole();
    doblist.Append(1);
    doblist.Clear();
    doblist.PrintToConsole();

    std::cout << (list.IsContain("5") ? "True" : "False") << std::endl;
}


