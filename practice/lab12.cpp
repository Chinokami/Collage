#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void insert(Node*& head, int value) {
  Node* newNode = new Node;
  newNode->data = value;
  newNode->next = head;
  head = newNode;
}

void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

bool contains(Node* head, int value) {
  while (head != nullptr) {
    if (head->data == value) return true;
    head = head->next;
  }
  return false;
}

void sortDescending(Node* head) {
  if (head == nullptr) return;
  for (Node* i = head; i->next != nullptr; i = i->next) {
    for (Node* j = i->next; j != nullptr; j = j->next) {
      if (i->data < j->data) {
        int temp = i->data;
        i->data = j->data;
        j->data = temp;
        }
    }
  }
}

void clear(Node*& head) {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Node* listA = nullptr;
  Node* listB = nullptr;
  Node* listC = nullptr;

  insert(listA, 5);
  insert(listA, 12);
  insert(listA, 3);
  insert(listA, 8);

  insert(listB, 3);
  insert(listB, 9);
  insert(listB, 12);
  insert(listB, 1);

  cout << "Список A: ";
  printList(listA);
  cout << "Список B: ";
  printList(listB);

  Node* temp = listA;
  while (temp != nullptr) {
    if (!contains(listC, temp->data)) {
      insert(listC, temp->data);
    }
    temp = temp->next;
  }

  temp = listB;
  while (temp != nullptr) {
    if (!contains(listC, temp->data)) {
      insert(listC, temp->data);
    }
    temp = temp->next;
  }

  sortDescending(listC);

  cout << "Результуючий відсортований список C: ";
  printList(listC);

  clear(listA);
  clear(listB);
  clear(listC);

  return 0;
}
