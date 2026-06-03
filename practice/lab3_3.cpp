#include <iostream>
#include <random>
using namespace std;

int main() {
  int V[5][5];
  int arr[15];
  
  srand(time(NULL));
  cout << "Матриця:" << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      V[i][j] = rand() % 11;
      cout << V[i][j] << " ";
    }
    cout << endl;
  }
  
  int index = 0;
  cout << "Масив:" << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i + j >= 4) {
        arr[index] = V[i][j];
        cout << arr[index] << " ";
        index++;
      }
    }
  }
  cout << endl;
  
  return 0;
}
