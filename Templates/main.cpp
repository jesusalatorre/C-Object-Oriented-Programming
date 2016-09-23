#include <iostream>
#include "class.h"

using namespace std;

int main()
{
    Cochinito<int> coch(100);
    Cochinito <int> cochi(50);


    cout << coch.getDinero();

    coch+cochi;

    return 0;
}
