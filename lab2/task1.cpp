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
  string sentence2 = "Hello my friend, you cool";
  string result = "";
  
  string chars_to_remove = ",.?!";
  for (char c : chars_to_remove) {
    replace(sentence.begin(), sentence.end(), c, ' ');
  }
  
  stringstream ss(sentence);
  string word;
  bool temp;
  
  while (ss >> word) {
    temp = isWordInText(sentence2, word);
    if (temp) {
      result += word + " ";
    }
  }
   
  cout << result;
    
  return 0;
}
