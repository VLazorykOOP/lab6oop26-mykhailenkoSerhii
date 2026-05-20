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

    std::cout << "Class structure size : " << sizeof(class7) << std::endl;
    std::cout << "VirtualClass structure size : " << sizeof(virtual7) << std::endl;
}