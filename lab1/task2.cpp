#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int k;
  cin >> k;
  
  int* arr = new int[n];
  
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 201 - 100;
    cout << arr[i] << " ";
  }
  
  int result = 0;
  
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      break;
    }
    
    if (arr[i] % k == 0 && arr[i] > result) {
      result = arr[i];
    }
  }
  
  if (result > 0)
    cout << endl << result << endl;
  else
    cout << endl << "Not found";
  
  delete[] arr;
  return 0;
}
