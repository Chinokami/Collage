#include <iostream>
#include <random>
using namespace std;

int main() {
  int V[5][6];
  int M[5];
  
  srand(time(NULL));
  cout << "Матриця:" << endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 6; j++) {
      V[i][j] = rand() % 21 - 10;
      cout << V[i][j] << " ";
    }
    cout << endl;
  }
  
  for (int i = 0; i < 5; i++) {
    int temp = 0;
    for (int j = 0; j < 6; j++) {
      if (V[i][j] > temp) temp = V[i][j];
    }
    if (temp == 0) M[i] = -1; // немає додатніх елементів
    else M[i] = temp;
  }
  
  cout << "Масив максимальних чисел:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << M[i] << " ";
  }
  cout << endl;
  
  return 0;
}
