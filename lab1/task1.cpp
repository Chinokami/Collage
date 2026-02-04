#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int N = 10;
  int* A = new int[N];
  
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    A[i] = rand() % 201 - 100;
  }
  
  cout << "Start Array" << endl;
  for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }
  
  int sum_p = 0;
  int sum_n = 0;
  
  for (int i = 0; i < N; i++) {
    if (A[i] >= 0) 
      sum_p += A[i];
    else
      sum_n += A[i];
  }
  
  int result = sum_p - sum_n;
  
  cout << endl << "Result: " << result;
  
  delete[] A;
  return 0;
}
