#include "Task1.h"

#include <iostream>

class VirtualClass1 { int data1; };
class VirtualClass2 { int data2; };
    
class VirtualClass3 : virtual public VirtualClass1, virtual public VirtualClass2 { int data3; };
    
class VirtualClass4 : virtual public VirtualClass3, virtual public VirtualClass2 { int data4; };
class VirtualClass5 : virtual public VirtualClass3 { int data5; };
class VirtualClass6 : virtual public VirtualClass2 { int data6; };
    
class VirtualClass7 : virtual public VirtualClass4, virtual public VirtualClass5, virtual public VirtualClass6 { int data7; };

class Class1 { int data1; };
class Class2 { int data2; };

class Class3 : public Class1, public Class2 { int data3; };

class Class4 : public Class3, public Class2 { int data4; };
class Class5 : public Class3 { int data5; };
class Class6 : public Class2 { int data6; };

class Class7 : public Class4, public Class5, public Class6 { int data7; };

void task1()
{
    Class7 class7 = Class7();
    VirtualClass7 virtual7 = VirtualClass7();

    std::cout << "Non-Virtual Class" << std::endl;
    std::cout << "Size of Class1: " << sizeof(Class1) << std::endl;
    std::cout << "Size of Class2: " << sizeof(Class2) << std::endl;
    std::cout << "Size of Class3: " << sizeof(Class3) << std::endl;
    std::cout << "Size of Class4: " << sizeof(Class4) << std::endl;
    std::cout << "Size of Class5: " << sizeof(Class5) << std::endl;
    std::cout << "Size of Class6: " << sizeof(Class6) << std::endl;
    std::cout << "Size of Class7: " << sizeof(Class7) << std::endl;
    std::cout << "Class structure size : " << sizeof(class7) << std::endl;

    std::cout << std::endl << "VirtualClass" << std::endl;
    std::cout << "Size of VirtualClass1: " << sizeof(VirtualClass1) << std::endl;
    std::cout << "Size of VirtualClass2: " << sizeof(VirtualClass2) << std::endl;
    std::cout << "Size of VirtualClass3: " << sizeof(VirtualClass3) << std::endl;
    std::cout << "Size of VirtualClass4: " << sizeof(VirtualClass4) << std::endl;
    std::cout << "Size of VirtualClass5: " << sizeof(VirtualClass5) << std::endl;
    std::cout << "Size of VirtualClass6: " << sizeof(VirtualClass6) << std::endl;
    std::cout << "Size of VirtualClass7: " << sizeof(VirtualClass7) << std::endl;
    std::cout << "VirtualClass structure size : " << sizeof(virtual7) << std::endl;
}