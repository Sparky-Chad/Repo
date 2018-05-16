//just wanted to see how exactly equalling strings worked

#include <iostream>
#include <string>

using namespace std;

int main()
{
  for(int i = 0; i < 3; i++)
  {
    string in1, in2;
    cout << "first one: ";
    cin >> in1;
    cout << "second one: ";
    cin >> in2;

    if(in1 == in2) cout << "\nworks";
  }
  return 0;
}
