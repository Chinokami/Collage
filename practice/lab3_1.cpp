#include <iostream>
#include <random>
using namespace std;

int main() {
  int R[5][4];
  
  srand(time(NULL));
  cout << "Початкова матриця:" << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      R[i][j] = rand() % 11;
      cout << R[i][j] << " ";
    }
    cout << endl;
  }
  
  cout << "Змінена матриця:" << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      if (R[i][j] % 2 == 1) R[i][j] = 1;
      else R[i][j] = 0;
      cout << R[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
