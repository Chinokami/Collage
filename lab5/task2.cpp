#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  stack <int> steck;
  int num = 10;
  
  srand(time(NULL));
  cout << "Stack:" << endl;
  for (int i = 0; i < num; i++) {
    steck.push(rand() % 11);
    cout << steck.top() << " ";
  }
  cout << endl;
  
  stack <int> odd;
  stack <int> even;
  
  for (int i = 0; i < num; i++) {
    if (steck.top() % 2 == 1)
      odd.push(steck.top());
    else
      even.push(steck.top());
    steck.pop();
  }
  
  cout << "Stack odd:" << endl;
  while (!odd.empty()) {
    cout << odd.top() << " ";
    odd.pop();
  }
  cout << endl;
  
  cout << "Stack even:" << endl;
  while (!even.empty()) {
    cout << even.top() << " ";
    even.pop();
  }
  
  return 0;
}
