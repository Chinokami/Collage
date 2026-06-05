#include <iostream>
#include <random>
using namespace std;

int main() {
  int rows = 4;
  int cols = 4;

  int** matrix = new int*[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new int[cols];
  }

  srand(time(NULL));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 11;
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  int max_val = matrix[0][0];
  int max_row = 0;
  int max_col = 0;
  long long product = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] > max_val) {
        max_val = matrix[i][j];
        max_row = i;
        max_col = j;
      }
      if (j > i) {
        product *= matrix[i][j];
      }
    }
  }

  cout << "Індекс максимального елемента: [" << max_row << "][" << max_col << "]" << endl;
  cout << "Добуток елементів над головную діагоналлю: " << product << endl;

  for (int i = 0; i < rows; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;

  return 0;
}
