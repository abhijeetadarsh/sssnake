#include <iostream>
#include <queue>

int main()
{
  std::deque<int> deque;

  deque.push_front(2);
  deque.push_front(3);
  deque.push_front(4);
  deque.push_front(5);
  
  deque.pop_back();
  deque.pop_back();
  deque.pop_back();
  deque.pop_back();
  deque.pop_back();
  deque.pop_back();

  std::cout << static_cast<int>(deque.size()) << "\n";

  return 0;
}