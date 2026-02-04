#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  if (n > 400 || n <= 0)
    return 1;

  int* arr = new int[n];
  int* arr_unique = new int[n];
  int size_unique = 0;
  
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 21 - 10;
    cout << arr[i] << " ";
  }
  cout << endl;
  
  sort(arr, arr + n);
  
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    
  cout << endl;
  
  arr_unique[size_unique++] = arr[0];
  
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1])
      arr_unique[size_unique++] = arr[i];
  }

  for (int i = 0; i < size_unique; i++)
    cout << arr_unique[i] << " ";
  
  delete[] arr;
  delete[] arr_unique;
  
  return 0;
}
