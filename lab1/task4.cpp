#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  if (n < 3)
    return 1;
    
  int* rating = new int[n];
  
  srand(time(NULL));
  cout << "Rating:" << endl;
  for (int i = 0; i < n; i++) {
    rating[i] = rand() % 10;
    cout << rating[i] << " ";
  }
  
  cout << endl;
  
  int max = -1;
  int min = -1;
  
  for (int i = 0; i < n; i++) {
    if (rating[i] > max || max == -1)
      max = rating[i];
    if (rating[i] < min || min == -1)
      min = rating[i];
  }
  
  int sum = 0;
  
  for (int i = 0; i < n; i++)
    sum += rating[i];

  sum -= max + min;
  cout << "Result:" << endl;
  float result = sum * 100 / (n - 2);
  result /= 100;
  
  cout << result << endl;
  delete[] rating;

  return 0;
}
