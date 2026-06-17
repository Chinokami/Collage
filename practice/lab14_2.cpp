#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

bool startsWithTargetLetter(const string& word) {
    if (word.empty()) return false;
    
    char firstChar = tolower(static_cast<unsigned char>(word[0]));
    return (firstChar == 'e' || firstChar == 'f' || firstChar == 'g' || firstChar == 'q');
}

int main(int argc, char* argv[]) {
    string inputPath, outputPath;

    if (argc >= 3) {
        inputPath = argv[1];
        outputPath = argv[2];
    } else {
        cin.clear();
        cout << "Введіть ім'я вхідного файлу: ";
        cin >> inputPath;
        cout << "Введіть ім'я вихідного файлу: ";
        cin >> outputPath;
    }

    ifstream inputFile(inputPath);
    if (!inputFile.is_open()) {
        cerr << "Помилка: Не вдалося відкрити вхідний файл!" << endl;
        return 1; 
    }

    ofstream outputFile(outputPath);
    if (!outputFile.is_open()) {
        cerr << "Помилка: Не вдалося створити вихідний файл за шляхом: " << outputPath << endl;
        inputFile.close();
        return 1;
    }

    string line;
    int lineNum = 1;

    cout << "\n--- РЕЗУЛЬТАТ РОБОТИ ПРОГРАМИ ---" << endl;

    while (getline(inputFile, line)) {
        string resultLine = "Рядок " + to_string(lineNum) + ": ";
        
        stringstream ss(line);
        string word;
        bool foundInLine = false;

        while (ss >> word) {
            if (startsWithTargetLetter(word)) {
                resultLine += word + " ";
                foundInLine = true;
            }
        }

        if (!foundInLine) {
            resultLine += "[Слів не знайдено]";
        }
        
        outputFile << resultLine << endl;
        cout << resultLine << endl; 
        
        lineNum++;
    }

    outputFile.flush();
    inputFile.close();
    outputFile.close();

    cout << "Аналіз завершено. Результати записано у: " << outputPath << endl;

    return 0;
}
