#include <iostream>
#include <random>
using namespace std;

int main() {
    int n = 3;

    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }

    srand(time(NULL));
    cout << "Матриця:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 11;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += A[i][j];
        }
    }
    double average = sum / (n * n);

    cout << "Кількість елементів у кожному рядку, менших за " << average << ":" << endl;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (A[i][j] < average) {
                count++;
            }
        }
        cout << "Рядок " << i << ": " << count << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
