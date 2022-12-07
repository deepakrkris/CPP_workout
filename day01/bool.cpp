#include <iostream>
using namespace std;

int main()
{
  cout << endl << endl << " START " <<  " Bool " << endl;
  cout << "------------------------------------------------------- " << endl;  
  bool b = 32;
  int i = false;
  cout << endl <<  " bool init with int value ,   bool b  :  " <<  b << endl;
  cout << endl <<  " int init with bool value ,   int i :  " <<  i << endl;
  int j = b + b;
  bool k = b + b;
  cout << endl <<  " int assigned with bool addition    ,  int j : " <<  j << endl;
  cout << endl <<  " bool assigned with bool addition   ,  bool k :  " <<  k << endl;
  cout << "------------------------------------------------------- " << endl << endl ; 
  cout << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
