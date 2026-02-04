#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  if (n < 2)
    return 1;
    
  int** matrix = new int*[n];
  
  for (int i = 0; i < n; i++)
    matrix[i] = new int[n];
  
  srand(time(NULL));
  cout << "Matrix:" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = rand() % 11;
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  
  int* result = new int[n];
  
  for (int i = 0; i < n; i++) {
    int min = 0;
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] >= min)
        min = matrix[i][j];
      else {
        min = -1;
        break;
      }
    }
    
    if (min != -1)
      result[i] = 1;
  }
  
  cout << "Result:" << endl;
  for (int i = 0; i < n; i++)
    cout << result[i] << " ";
  
  
  delete[] matrix;
  delete[] result;
  
  return 0;
}
