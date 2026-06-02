#include <iostream>
#include <random>
using namespace std;

int main() {
  int Z[11];
  
  cout << "Оригінальний масив" << endl;
  srand(time(NULL));
  for (int i = 0; i < 11; i++) {
    Z[i] = rand() % 10 + 1;
    cout << Z[i] << " ";
  }
  cout << endl;
  
  int temp[11];
  for (int i = 0; i < size(Z) / 2; i++) {
    temp[i * 2] = Z[i * 2 + 1];
    temp[i * 2 + 1] = Z[i * 2];
  }
  
  if (sizeof(Z) / sizeof(Z[0]) % 2 != 0)
    temp[size(Z) - 1] = Z[size(Z) - 1];
  copy(begin(temp), end(temp), begin(Z));
  
  cout << "Змінений масив" << endl;
  for (int i = 0; i < size(Z); i++) {
    cout << Z[i] << " ";
  }
  
  return 0;
}
