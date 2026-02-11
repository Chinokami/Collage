#include <iostream>
using namespace std;

int factorial(int num) {
  if (num > 1)
    return num * factorial(num - 1);
  else
    return 1;
}

int ordering(int m, int n) {
  if (m > 1) {
    return n * ordering(m - 1, n - 1);
  } else {
    return n;
  }
}

int combination(int m, int n) {
  return ordering(m, n) / factorial(m);
}

int main() {
  int m, n;
  cin >> m >> n;
  
  int result;
  
  if ((m == 0 && n > 0) || (m == n && n >= 0)) {
    result = 1;
  } else if (m > n && n >= 0) {
    result = 0;
  } else {
    result = combination(m - 1, n - 1) + combination(m, n - 1);
  }
  
  cout << result << endl;
  
  return 0;
}
