#include <iostream>
#include <random>
using namespace std;

int* func(int arr[], int size) {
  int count = 0;
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > 1000 && arr[i] < 5000) {
      sum += arr[i];
      count++;
    }
  }
  static int result[2];
  result[0] = count;
  result[1] = sum;
  return result;
}

int main() {
  int n = 10;
  int* y = new int[n];
  
  srand(time(NULL));
  cout << "Масив:" << endl;
  for (int i = 0; i < n; i++) {
    y[i] = rand() % 7000;
    cout << y[i] << " ";
  }
  
  int* result = func(y, n);
  cout << endl << "Кількість: " << result[0] << " | Сума: " << result[1] << endl;
  
  delete[] y;
  return 0;
}
