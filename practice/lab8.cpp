#include <iostream>
using namespace std;

bool hasRoots(double coeff1, double coeff2, double coeff3) {
    double discriminant = (coeff2 * coeff2) - (4 * coeff1 * coeff3);
    return discriminant >= 0;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    double c = 1.0;

    cout << "a) ";
    if (hasRoots(a, b, c)) {
        cout << "Рівняння має дійсні корені!" << endl;
    } else {
        cout << "Рівняння не має дійсних коренів!" << endl;
    }

    cout << "б) ";
    if (hasRoots(b, a, c)) {
        cout << "Рівняння має дійсні корені!" << endl;
    } else {
        cout << "Рівняння не має дійсних коренів!" << endl;
    }

    cout << "в) ";
    if (hasRoots(c, b, a)) {
        cout << "Рівняння має дійсні корені!" << endl;
    } else {
        cout << "Рівняння не має дійсних коренів!" << endl;
    }

    return 0;
}
