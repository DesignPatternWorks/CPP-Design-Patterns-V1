#include <stack>

int main() {
  // Stack from the STL is just an adapter of a vector.
  // Stack has an underlying container (by default deque).
  // Stack uses methods of underlying container
  // e.g. push_back, pop_back, back, ...
  // to implement stack specific methods like push, pop, top, ...
  std::stack<int> stack;
  stack.push(123);
  int x = stack.top();
  stack.pop();

  return 0;
}
