#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string S = "qw, e.!rty3 34sd?fg 3 we,3 4r";

    int sum = 0;
    long long mult = 1;
    bool hasDigits = false;

    for (char ch : S) {
        if (isdigit(static_cast<unsigned char>(ch))) {
            int digit = ch - '0';
            sum += digit;
            mult *= digit;
            hasDigits = true;
        }
    }

    if (!hasDigits) {
        mult = 0;
    }

    cout << "Sum = " << sum << ", mult = " << mult << endl;

    return 0;
}
