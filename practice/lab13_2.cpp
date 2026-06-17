#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isSeparator(char ch) {
    return isspace(static_cast<unsigned char>(ch)) || ispunct(static_cast<unsigned char>(ch));
}

int main() {
    string targetWord, replacementWord;
    
    if (!(cin >> targetWord >> replacementWord)) {
        return 1;
    }
    
    cin.ignore();

    string text;
    getline(cin, text);

    string result = "";
    string currentWord = "";

    for (size_t i = 0; i <= text.length(); ++i) {
        if (i < text.length() && !isSeparator(text[i])) {
            currentWord += text[i];
        } else {
            if (!currentWord.empty()) {
                if (currentWord == targetWord) {
                    result += replacementWord;
                } else {
                    result += currentWord;
                }
                currentWord = "";
            }
            if (i < text.length()) {
                result += text[i];
            }
        }
    }

    cout << result << endl;

    return 0;
}
