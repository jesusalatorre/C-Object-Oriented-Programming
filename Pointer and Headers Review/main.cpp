#include <iostream>
#include "header.h"

using namespace std;


int main()
{
int y=15, *p, *q;
p=new int (10);
q=&y;
cout << *p << " " << *q << endl;
*q=6;
q=p;
*p=2;
cout << *p << " " << *q <<endl;
cout << y << endl;
q= new int (11);
y++;
*p=*p-1;
cout << *p << " " << *q << endl;
cout << y << endl;

return 0;
}
