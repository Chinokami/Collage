#include <iostream>
#include <random>
using namespace std;

int main() {
  int k = 6;
  int n = 5;
  int** matrix = new int*[k];
  
  for (int i = 0; i < k; i++) {
    matrix[i] = new int[n];
  }
  
  srand(time(NULL));
  cout << "\t\t\t\tКандидати:" << endl; 
  for (int i = 0; i < k; i++) {
    cout << "Нас. пункт №" << i + 1 << ": ";
    for (int j = 0; j < n; j++) {
      matrix[i][j] = rand() % (10 * 11 + 50);
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  
  int num = 0;
  int id = 0;
  for (int i = 0; i < k; i++) {
    if (matrix[i][2] > num) {
      id = i;
      num = matrix[i][2];
    }
  }
  cout << "3-й кандидат набрав найбільше\nголосів в населеному пункті №"<< id + 1 << endl;
  
  return 0;
}
