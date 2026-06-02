#include <iostream>
using namespace std;

bool func(float x, float y) {
  if (x >= -2 and x <= 1)
    if (y >= -2 and y <= 0) return true;
  if (x >= -2 and x <= -1)
    if (y >= 0 and y <= 1) return true;
  if (x >= -1 and x <= 0)
    if (y <= -x) return true;
  
  return false;
}

int main() {
  double x, y;
  
  cin >> x >> y;
  
  bool result = func(x, y);
  // 1 - Точка попадає в заштриховану область, 2 - Не попадає
  cout << result;
  
  return 0;
}
