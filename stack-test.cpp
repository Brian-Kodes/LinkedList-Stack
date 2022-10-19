#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;


int main(int argc, char* argv[])
{
  Stack<int> intStack;
  intStack.pop();
  intStack.push(4);
  intStack.push(5);
  intStack.pop();
  intStack.top();
  cout << intStack.top() << endl;
  //template <typename T> Stack();
    return 0;

}
