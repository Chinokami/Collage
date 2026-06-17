#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");

    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    string word;
    int count = 0;

    while (file >> word) {
        if (!word.empty() && (word[0] == 's' || word[0] == 'S')) {
            count++;
        }
    }

    cout << "Кількість слів, що починаються на літеру 's': " << count << endl;

    file.close();
    return 0;
}
