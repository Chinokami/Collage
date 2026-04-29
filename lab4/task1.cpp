#include <iostream>
#include <cmath>
#include <random>
using namespace std;

int main() {
  int n = 15;
  double a, b, c;
  
  srand(time(NULL));
  for (int i = 1; i <= n; i++) {
    a = rand() % 11 - 5;
    b = rand() % 11 - 5;
    c = rand() % 11 - 5;
    
    
    double R = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
    
    if (R == 3) {
      double S = 4 * pow(R, 2);
      double V = (4.0 / 3.0) * pow(R, 3);
      
      cout << "Number: " << i << endl;
      cout << a << "² + " << b << "² + " << c << "² = " << R << "²" << endl;
      cout << "S = " << S << "π" << endl;
      cout << "V = " << V << "π" << endl;
    }
  }
  
  return 0;
}
