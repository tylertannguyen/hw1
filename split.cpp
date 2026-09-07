/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  // Base case: if the input list is empty, return
  if (in == nullptr){
    return;
  }
  // Saves current node to a temporary variable
  Node* current = in;
  // Move the input list pointer to the next node
  in = in->next; 
  // Recursive case: check if the current node's value is odd or even
  // Recursively split list
  split(in, odds, evens);
  if (current->value % 2 == 0){
    // If value is even, add it to evens list
    current->next = evens;
    // Update the evens head pointer to the current node
    evens = current;
  } else {
    // If value is odd, add it to odds list
    current->next = odds;
    // Update the odds head pointer to current node
    odds = current;
  }
}


/* If you needed a helper function, write it here */
