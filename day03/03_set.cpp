// set::find
#include <iostream>
#include <set>
#include <map>

using namespace std;

std::map<string, string> pet_names = {{"Pete", "Dog"}, 
              {"Chuck", "Dog"}, 
              {"Bebe", "Cat"}};

int main ()
{
  cout << endl << endl << " START " <<  " Datastructures : Set " << endl;
  cout << "------------------------------------------------------- " << endl;

  std::set<std::string> pet_types;

  for (auto const& x : pet_names) {
    pet_types.insert(x.second);
  }

  std::cout << "name_set contains :  " << endl;

  for(auto it = pet_types.begin(); it != pet_types.end(); ++it) {
    cout << *it << endl;
  }

  auto dog = pet_types.find("Dog");
  pet_types.erase(dog);
  pet_types.erase("Cat");

  std::cout << "pet_types size after erase : " << pet_types.size() << endl;

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
