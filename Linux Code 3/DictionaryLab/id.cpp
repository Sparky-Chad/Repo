#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream ifile ("Dic.txt");
  string str;
  if (ifile) {
    while(getline(ifile, str)) {
      cout << str << endl;
      system("pause");
    }
    ifile.close();
  }
  else cout << "no";

  return 0;
}
