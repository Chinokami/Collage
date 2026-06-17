#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string inputPath, outputPath;

    if (argc >= 3) {
        inputPath = argv[1];
        outputPath = argv[2];
    } else {
        cout << "Введіть ім'я вхідного файлу: ";
        cin >> inputPath;
        cout << "Введіть ім'я вихідного файлу: ";
        cin >> outputPath;
    }

    ifstream inputFile(inputPath);
    if (!inputFile.is_open()) {
        cerr << "Помилка відкриття вхідного файлу!" << endl;
        return 1;
    }

    ofstream outputFile(outputPath);
    if (!outputFile.is_open()) {
        cerr << "Помилка створення вихідного файлу!" << endl;
        inputFile.close();
        return 1;
    }

    string line;
    int lineNum = 1;

    cout << "\n--- РЕЗУЛЬТАТ РОБОТИ ПРОГРАМИ ---" << endl;

    while (getline(inputFile, line)) {
        string resultLine = "Рядок " + to_string(lineNum) + ": ";

        bool hasTab = false;
        
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '\t') {
                hasTab = true;
            }
        }

        if (hasTab) {
            resultLine += line;
        } else {
            resultLine += "[Послідовностей з 20h, 09h, 0Ah не знайдено]";
        }

        outputFile << resultLine << endl;
        cout << resultLine << endl;

        lineNum++;
    }

    outputFile.flush();
    inputFile.close();
    outputFile.close();

    cout << "---------------------------------" << endl;
    cout << "Аналіз завершено. Результати записано у: " << outputPath << endl;

    return 0;
}
