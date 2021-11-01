#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
    Array* a = new Array();
    /*a->add(1);
    a->add(2);
    a->print(0);
    a->print(1);
    a->print(3);
    a->edit(0, 3);
    a->print(0);
    a->add(4);
    a->edit(3, 3);
    a->clear();*/
    

    a->add(5);
    a->add(3);
    a->add(4);
    a->add(1);
    a->add(2);
    a->print(0);
    a->print(1);
    a->print(2);
    a->print(3);
    a->print(4);
    a->sort();
    a->print(0);
    a->print(1);
    a->print(2);
    a->print(3);
    a->print(4);
    a->print(5);
    a->info();
}
