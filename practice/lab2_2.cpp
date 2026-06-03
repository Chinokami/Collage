#include <iostream>
#include <random>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
  int X[10], Y[10];
  
  srand(time(NULL));
  cout << "X: ";
  for (int i = 0; i < size(X); i++) {
    X[i] = rand() % 11;
    cout << X[i] << " ";
  }
  
  cout << endl << "Y: ";
  for (int i = 0; i < size(Y); i++) {
    Y[i] = rand() % 10 - 10;
    cout << Y[i] << " ";
  }
  
  int Z[size(X) + size(Y)];
  for (int i = 0; i < size(Z); i++) {
    if (i <= size(X) - 1) {
      Z[i] = X[i];
    } else {
      Z[i] = Y[i - size(X)];
    }
  }
  
  quickSort(Z, 0, size(Z) - 1);
  
  cout << endl << "Z: ";
  for (int i = 0; i < size(Z); i++) {
    cout << Z[i] << " ";
  }
  cout << endl;
  
  return 0;
}
