#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
    /*Array<int> newArray;
    Array<int> newArray2;
    newArray[0] = 1;
    newArray[1] = 2;
    newArray[2] = 3;
    newArray[3] = 4;
    newArray[4] = 5;
    newArray[5] = 6;

    cout << newArray[0] << endl;
    cout << newArray[1] << endl;
    cout << newArray[2] << endl;
    cout << newArray[3] << endl;
    cout << newArray[4] << endl;
    cout << newArray[5] << endl;*/
    
    Array<int>* a = new Array<int>();
    a->add(1);
    a->add(2);
    a->print(0);
    a->print(1);
    a->print(3);
    a->edit(0, 3);
    a->print(0);
    a->add(4);
    a->edit(3, 3);
    
}
