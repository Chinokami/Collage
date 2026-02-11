#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  stack <int> l;
  int len = 8;
  
  srand(time(NULL));
  for (int i = 0; i < len; i++) {
    l.push(rand() % 10);
  }
  
  stack <int> temp(l);
  int countdown = 0;
  
  cout << "Stack" << endl;
  while (!temp.empty()) {
    cout << temp.top() << " ";
    temp.pop();
    
    if (++countdown % 5 == 0)
      cout << endl;
  }
  countdown = 0;
  
  stack <int> mod_l;
  
  for (int i = 0; i < (len * 2); i++) {
    if (i % 2 == 1) {
      mod_l.push(l.top());
      l.pop();
    } else {
      mod_l.push(rand() % 11 + 10);
    }
  }
  
  stack <int> mod_temp;
  
  while (!mod_l.empty()) {
    mod_temp.push(mod_l.top());
    mod_l.pop();
  }
  
  
  cout << "\nModifity Stack" << endl;
  while (!mod_temp.empty()) {
    cout << mod_temp.top() << " ";
    mod_temp.pop();
    
    if (++countdown % 5 == 0)
      cout << endl;
  }
  
  return 0;
}
