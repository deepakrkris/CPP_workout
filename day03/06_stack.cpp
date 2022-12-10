// stack::push/pop
#include <iostream>       // std::cout
#include <stack>          // std::stack

using namespace std;

int main ()
{
  cout << endl << endl << " START " <<  " Datastructures : stack " << endl;
  cout << "------------------------------------------------------- " << endl;

  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
