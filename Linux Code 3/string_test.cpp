//just wanted to see how exactly equalling strings worked

#include <iostream>
#include <string>

using namespace std;

int main()
{
  for(int i = 0; i < 3; i++)
  {
    string *in = new string[2];
    cout << "first one: ";
    cin >> in[0];
    cout << "second one: ";
    cin >> in[1];

    if(in[0] == in[1]) cout << "\nworks\n";
    cout << in[0] << " " << in[1] << endl;
    cout << &in[0] << " " << &in[1] <<endl;
   }
   string str = "12345678";
   string sub = str.substr(str.length() - 4, 4);
   cout << sub << endl;
  return 0;
}
