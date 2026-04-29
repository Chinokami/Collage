#include <iostream>
#include <sstream>   
#include <string> 
#include <algorithm>
#include <cctype>
using namespace std;

bool isWordInText(string sentence, string looking_word) {
  string chars_to_remove = ",.?!";
  for (char c : chars_to_remove) {
      replace(sentence.begin(), sentence.end(), c, ' ');
  }
  
  transform(looking_word.begin(), looking_word.end(), looking_word.begin(), ::tolower);
  
  stringstream ss(sentence);
  string word;
  
  while (ss >> word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    if (word == looking_word)
      return true;
  }
  
  return false;
}

int main() {
  string sentence = "Hello, world! How are you?";
    
    if (isWordInText(sentence, "World")) {
        cout << "Знайдено!" << endl;
    } else {
        cout << "Не знайдено." << endl;
    }
  
  return 0;
}
