#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

// Test push_back
  list.push_back("A");
  list.push_back("B");
  list.push_back("C");

  std::cout << "After push_back: ";
  for (size_t i = 0; i < list.size(); i++) {
    std::cout << list.get(i) << " ";
  }
  std::cout << "\n";

  // Test push_front
  list.push_front("Front");

  std::cout << "After push_front: ";
  for (size_t i = 0; i < list.size(); i++) {
    std::cout << list.get(i) << " ";
  }
  std::cout << "\n";

  // Test front and back
  std::cout << "Front: " << list.front() << "\n";
  std::cout << "Back: " << list.back() << "\n";

  // Test pop_front and pop_back
  list.pop_front();
  list.pop_back();

  std::cout << "After popping: ";
  for (size_t i = 0; i < list.size(); i++) {
    std::cout << list.get(i) << " ";
  }
  std::cout << "\n";

  // Test set
  list.set(0, "Changed");
  std::cout << "After set: " << list.get(0) << "\n";

  std::cout << "Size: " << list.size() << "\n";

  return 0;
}
