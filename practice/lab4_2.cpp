#include <iostream>
#include <random>
using namespace std;

int main() {
  int n = 4;
  int m = 5;
  int** A = new int*[n];
  
  for (int i = 0; i < n; i++) {
    A[i] = new int[m];
  }
  
  srand(time(NULL));
  cout << "Матриця:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = rand() % 11;
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  
  cout << "Рядки в яких є число 0:" << endl;
  for (int i = 0; i < n; i++) {
    bool zero = false;
    for (int j = 0; j < m; j++) {
      if (A[i][j] == 0)
        zero = true;
    }
    if (zero) {
      for (int j = 0; j < m; j++)
        cout << A[i][j] << " ";
      cout << endl;
    }
  }
  
  for (int i = 0; i < n; ++i) {
      delete[] A[i];
  }
  delete[] A; 
  return 0;
}
