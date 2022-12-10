#include <iostream>
#include <thread>

using namespace std;

void helloFunction(){
  std::cout << "Hello from a function." << std::endl;
}

class HelloFunctionObject{
  public:
    void operator()() const {
      std::cout << "Hello from a function object." << std::endl;
    }
};

int main(){
  cout << endl << endl << " START " <<  " Threads " << endl;
  cout << "------------------------------------------------------- " << endl;

  std::cout << std::endl;

  std::thread t1(helloFunction);

  HelloFunctionObject helloFunctionObject;
  std::thread t2(helloFunctionObject);

  std::thread t3([]{std::cout << "Hello from a lambda." << std::endl;});

  std::thread t4([]{std::cout << std::this_thread::get_id() << std::endl;});

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
};