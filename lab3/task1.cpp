#include <iostream>
#include <cmath>
using namespace std;

int factorial(int num) {
  if (num > 0) {
    return num * factorial(num - 1);
  } else {
    return 1;
  }
}

float equation(float num) {
  if (num > 1) {
    return sqrt(pow(2, num) + equation(num - 1));
  } else {
    return sqrt(2);
  }
}

int main() {
    int m;
    float n;
    cin >> m;
    cin >> n;
    
    float result = factorial(m) / equation(n);
    
    cout << result << endl;
    
    return 0;
}
