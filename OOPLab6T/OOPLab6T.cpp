#include <iostream>
#include <Task3.h>
#include <Task2.h>
#include <Task1.h>
int main()
{
    std::cout << " Lab #6  !\n";

    std::cout << "Task 1: Virtual inheritances" << std::endl;
    std::cout << "Task 2: Virtual functions and classes" << std::endl;
    std::cout << "Task 3: Multiple inheritances" << std::endl;
    std::cout << "Input what task to run - " << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice == 1)
        task1();
    if (choice == 2)
        task2();
    if (choice == 3)
        task3();
}