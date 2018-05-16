//chad Lape
//pointtest.cpp
//testing if a point can point to specific parts of an array

#include <iostream>
using namespace std;
int main()
{
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *ab = &a[5];
  cout << "pointer test\n";
  cout << "a[5] = " << a[5] << "*ab (a[5])= " << *ab << endl;
  cout << "a[7] = " << a[7] << "*(ab + 2) = " << *(ab+2) << endl;
   return 0;
}
