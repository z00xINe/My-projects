#include <iostream>
#include "BigReal.h"

int main()
{
    BigReal  b1("-9934560.1");
    BigReal  b2("+34560.99890008");
    BigReal b3(b1);
    if (b1==b2)
        cout << b1;
    else
        cout << b2-b1 << endl;
    if (b1 > b2)
        cout << "k" << endl;
    cout << b3.size();
    return 0;
}

#include "BigReal.cpp"
