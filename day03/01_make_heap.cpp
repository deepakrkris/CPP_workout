#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

using namespace std;

void print_heap(std::vector<int>& v) {
    std::cout << endl << endl; 
    for (unsigned i=0; i<v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << endl << endl; 
}

int main () {
  cout << endl << endl << " START " <<  " Datastructures : Max Heap" << endl;
  cout << "------------------------------------------------------- " << endl;

  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  std::make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  print_heap(v);

  std::pop_heap (v.begin(),v.end());
 
  print_heap(v);

  v.pop_back();

  std::cout << "max heap after pop : " << v.front() << '\n';

  print_heap(v);

  v.push_back(99);

  print_heap(v);
 
  std::push_heap (v.begin(),v.end());

  std::cout << "max heap after push: " << v.front() << '\n';

  print_heap(v);

  std::sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";

  print_heap(v);

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
