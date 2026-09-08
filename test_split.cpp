/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

void printList(Node* head)
{
  while (head != nullptr) {
    std::cout << head->value << " ";
    head = head->next;
  }
  std::cout << "\n";
}

void deleteList(Node* head)
{
  while (head != nullptr) {
    Node* next = head->next;
    delete head;
    head = next;
  }
}

int main(int argc, char* argv[])
{
  // Create the sorted list: 1 -> 2 -> 3 -> 4
  Node* input = new Node(1, nullptr);
  input->next = new Node(2, nullptr);
  input->next->next = new Node(3, nullptr);
  input->next->next->next = new Node(4, nullptr);

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(input, odds, evens);

  std::cout << "Odds: ";
  printList(odds);

  std::cout << "Evens: ";
  printList(evens);

  deleteList(odds);
  deleteList(evens);

  return 0;
}
