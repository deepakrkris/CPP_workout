/**
 * @file swap_with_reference.cpp
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * Let us c++
 * 
 */

#include <iostream>
using namespace std;

// prototype declarations
void swapv (int, int);
void swapr (int &, int &);
void swapa (int *, int *);

bool testCallByValue() {
  int a =10, b = 20;
  swapv (a, b); // call by value
  cout << endl << " call by value:  " << a << "\t" << b;
  return b < a;
}

bool testCallByAddress() {
  int a =10, b = 20;
  swapa (&a, &b); // call by address
  cout << endl << " call by address " << a << "\t" << b;
  return b < a;
}

bool testCallByReference() {
  int a =10, b = 20;
  swapr (a, b); // call by reference
  cout << endl << " call by reference " << a << "\t" << b << endl;
  return b < a;
}

int main()
{
  cout << endl << endl << " START " <<  " Call by reference " << endl;
  cout << "------------------------------------------------------- " << endl;  

  assert( testCallByValue() == false );
  assert( testCallByAddress() == true );
  assert( testCallByReference() == true );

  cout << "------------------------------------------------------- " << endl << endl ; 
  cout << "------------------------------------------------------- " << endl << endl ;
  return 0;
}

void swapv (int i, int j)
{
  int t;
  t = i;
  i = j;
  j = t;
}

void swapa (int *i, int *j)
{
  int t;
  t = *i;
  *i = *j;
  *j = t;
}

void swapr (int &i, int &j)
{
  int t;
  t = i;
  i = j;
  j = t;
}
