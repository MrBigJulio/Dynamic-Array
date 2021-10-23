#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
    Array<Record>* newArray = new Array<Record>();
    newArray->resize(*newArray);
}
