#include <iostream>
#include <random>
using namespace std;

struct Person {
  double weight;
  char gender;
};

int main() {
  const int COUNT = 20;
  Person people[COUNT];
  double total_men_weight = 0;

  srand(time(NULL));
  for (int i = 0; i < COUNT; ++i) {
    people[i].weight = rand() % 60 + 50;
    int choice = rand() % 2;
    if (choice == 0) people[i].gender = 'M';
    else people[i].gender = 'F';
    cout << people[i].weight << " " << people[i].gender << endl;

    if (people[i].gender == 'M') {
      total_men_weight += people[i].weight;
    }
  }

  cout << "Загальна маса чоловіків: " << total_men_weight << " кг" << endl;

  return 0;
}
