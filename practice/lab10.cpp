#include <iostream>
#include <string>
using namespace std;

struct Voter {
    string fullName;
    string street;
    int house;
    int apartment;
    string passport;
    int birthYear;
    bool hasVoted;
};

double getVotedUnder35Percentage(Voter arr[], int size) {
    int currentYear = 2026;
    int totalUnder35 = 0;
    int votedUnder35 = 0;

    for (int i = 0; i < size; i++) {
        if (currentYear - arr[i].birthYear < 35) {
            totalUnder35++;
            if (arr[i].hasVoted) {
                votedUnder35++;
            }
        }
    }

    if (totalUnder35 == 0) return 0.0;
    return (double)votedUnder35 / totalUnder35 * 100.0;
}

int getZegeleyVotedCount(Voter arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].street == "Зегеля" && arr[i].hasVoted) {
            count++;
        }
    }
    return count;
}

int main() {
    const int SIZE = 4;
    Voter list[SIZE] = {
        {"Іванов І. І.", "Зегеля", 10, 5, "АМ123456", 1995, true},
        {"Петров П. П.", "Соборна", 22, 14, "АН654321", 2000, false},
        {"Сидоров С. С.", "Зегеля", 12, 1, "АВ789012", 1988, true},
        {"Васильєв В. В.", "Зегеля", 5, 82, "АЕ345678", 2002, true}
    };

    double percent = getVotedUnder35Percentage(list, SIZE);
    int zegeleyCount = getZegeleyVotedCount(list, SIZE);

    cout << "Відсоток виборців молодших 35 років, які проголосували: " << percent << "%" << endl;
    cout << "Кількість виборців з вулиці Зегеля, які проголосували: " << zegeleyCount << endl;

    return 0;
}
