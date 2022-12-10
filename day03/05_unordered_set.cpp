// unordered_set::insert
#include <iostream>
#include <string>
#include <array>
#include <unordered_set>

using namespace std;

typedef std::unordered_set<std::string> stringset;

int main ()
{
  cout << endl << endl << " START " <<  " Datastructures : Unordered set " << endl;
  cout << "------------------------------------------------------- " << endl;

  std::unordered_set<std::string> myset = {"yellow","green","blue"};
  std::array<std::string,2> myarray = {"black","white"};
  std::string mystring = "red";

  stringset::hasher fn = myset.hash_function();

  std::cout << "current bucket_count: " << myset.bucket_count() << std::endl;

  std::cout << "yellow : " << fn ("yellow") << std::endl;
  std::cout << "black : " << fn ("black") << std::endl;

  myset.rehash(2);

  std::cout << "current bucket_count: " << myset.bucket_count() << std::endl;

  fn = myset.hash_function();

  std::cout << "yellow : " << fn ("yellow") << std::endl;
  std::cout << "black : " << fn ("black") << std::endl;

  myset.insert (mystring);                        // copy insertion
  myset.insert (mystring+"dish");                 // move insertion
  myset.insert (myarray.begin(), myarray.end());  // range insertion
  myset.insert ( {"purple","orange"} );           // initializer list insertion

  std::cout << "myset contains:";
  for (const std::string& x: myset) std::cout << " " << x;
  std::cout <<  std::endl;

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
