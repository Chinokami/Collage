#include <iostream>
#include <cmath>
#include <random>
using namespace std;

double distance(int x1, int x2, int y1, int y2) {
  double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  
  return d;
}

double area(double a, double b, double c, double P) {
  double p = P / 2;
  double S = sqrt(p * (p - a) * (p - b) * (p - c));
  
  return S;
}

int main() {
  int x1, x2, x3;
  int y1, y2, y3;
  
  srand(time(NULL));
  x1 = rand() % 6;
  x2 = rand() % 6;
  x3 = rand() % 6;
  
  y1 = rand() % 6;
  y2 = rand() % 6;
  y3 = rand() % 6;
  
  double a = distance(x2, x3, y2, y3);
  double b = distance(x1, x3, y1, y3);
  double c = distance(x1, x2, y1, y2);
  
  double P = a + b + c;
  double S = area(a, b, c, P);
  
  cout << "a = " << a << "; b = " << b << "; c = " << c << ';' << endl;
  
  cout << "P = " << P << endl;
  cout << "S = " << S << endl;
  
  return 0;
}
