#include <iostream>
#include <sstream>    
#include <string>  
#include <algorithm>
#include <cctype>

using namespace std;

string cleanWord(string word) {
    string result = "";
    for (char c : word) {
        if (!ispunct((unsigned char)c)) {
            result += (char)tolower((unsigned char)c);
        }
    }
    return result;
}

bool isWordInText(string sentence, string looking_word) {
    looking_word = cleanWord(looking_word);
    if (looking_word.empty()) return false;

    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        if (cleanWord(word) == looking_word)
            return true;
    }
    return false;
}

string generateNewText(string text1, string text2) {
    string result = "";
    string word;

    stringstream ss1(text1);
    while (ss1 >> word) {
        string cleaned = cleanWord(word);
        if (!cleaned.empty() && !isWordInText(text2, cleaned)) {
            result += cleaned + " ";
        }
    }

    stringstream ss2(text2);
    while (ss2 >> word) {
        string cleaned = cleanWord(word);
        if (!cleaned.empty() && !isWordInText(text1, cleaned)) {
            result += cleaned + " ";
        }
    }

    return result;
}

int main() {
    string t1, t2;
    
    getline(cin, t1);
    getline(cin, t2);

    string result = generateNewText(t1, t2);
    cout << result << endl;

    return 0;
}
