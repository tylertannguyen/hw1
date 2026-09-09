#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
// push_back() adds a new value to the back of the list
void ULListStr::push_back(const std::string& val)
{
  // If list is empty, create a new node and set head and tail to it
  if(empty()){
    head_ = new Item();
    tail_ = head_;
  }
  // If the last node is full, create a new node 
  else if (tail_->last == ARRSIZE){
    Item* newItem = new Item();
    // Link the new node to the tail
    newItem->prev = tail_;
    tail_->next = newItem;
    // Move the tail pointer to the new node
    tail_ = newItem;
  }
  // Add the new value to the last position
  tail_->val[tail_->last] = val; 
  // Increment the last index & size
  tail_->last++; 
  size_++;
}
// push_front() adds a new value to the front of the list
void ULListStr::push_front(const std::string& val)
{
  // If list empty, create a new node and set head and tail to it
  if(empty()){
    head_ = new Item();
    tail_ = head_;
    // Make new node's empty space start at right end of array
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }
  // If the first node is full, create a new node
  else if (head_->first == 0){
    Item* newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    // Make new node's empty space start at right end of array
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }
  // Move first left and store the new value there
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}
// pop_back() removes the last value from the list
void ULListStr::pop_back()
{
  // Do nothing if the list is empty
  if(empty()){
    return;
  }
  // Remove the last value and decrement size
  tail_->last--;
  size_--;
  // If the last node is now empty, delete it
  if(tail_->first == tail_->last){
    Item* temp = tail_;
    tail_ = tail_->prev;
    // If the list is now empty, set head to NULL
    if(tail_ == NULL){
      head_ = NULL;
    } else {
      tail_->next = NULL;
    }
    delete temp;
  }
}
// pop_front() removes the first value from the list
void ULListStr::pop_front()
  {
    // empty list, do nothing
    if (empty()){
      return;
    }
    // remove the first value and decrement size
    head_->first++;
    size_--;
    // if the first node is now empty, delete it
    if (head_->first == head_->last){
      Item* temp = head_;
      head_ = head_->next;
      // if the list is now empty, set tail to NULL
      if (head_ == NULL){
        tail_ = NULL;
      } else {
        head_->prev = NULL;
      }
      delete temp;
    }

  }
// back() returns the last value in the list
std::string const& ULListStr::back() const
{
  // access the last value in the last node
  return tail_->val[tail_->last - 1];
}
// front() returns the first value in the list
std::string const& ULListStr::front() const
{
  // access the first value in the first node
  return head_->val[head_->first];
}
// getValAtLoc() returns a pointer to the value at the given location
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  // If the location is out of bounds, return NULL
  if (loc >= size_){
    return NULL;
  }
  // Traverse  list to find the node containing the value at the given location
  Item* current = head_;
  while (current != NULL){
    // Calculate the number of occupied elements in the current node
    size_t itemSize = current->last - current->first;
    // If the location is within the current node, return a pointer to the value
    if (loc < itemSize){
      return &(current->val[current->first + loc]);
  }
    // If the location is not within the current node, move to the next node and adjust the location accordingly
    loc -= itemSize;
    current = current->next;
  }
  // If the location is not found in any node, return NULL
  return NULL;
}
