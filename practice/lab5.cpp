#include <iostream>
#include <random>
using namespace std;

int main() {
  int n = 6;
  int* arr = new int[n];
  
  srand(time(NULL));
  cout << "Масив:" << endl;
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 21 - 10;
    cout << arr[i] << " ";
  }
  
  int* temp = new int[n * 2];
  int id = 0;
  int start = 0;
  for (int i = 0; i < n; i++) {
    temp[id] = arr[i];
    id++;
    if (arr[i] % 5 == 0) {
      int num = 0;
      for (int j = start; j <= id; j++) {
        num += temp[j];
      }
      start = i + 1;
      temp[id] = num;
      id++;
    }
  }
  
  cout << endl << "Змінений масив:" << endl;
  for (int i = 0; i < id; i++) {
    cout << temp[i] << " ";
  }
  
  return 0;
}
