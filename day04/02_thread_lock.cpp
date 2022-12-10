#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

class Spinlock{
  std::atomic_flag flag;

public:
  Spinlock(): flag(ATOMIC_FLAG_INIT){}

  void lock() {
    while( flag.test_and_set() );
  }

  void unlock() {
    flag.clear();
  }
};

Spinlock spin;

void workOnResource() {
  spin.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  spin.unlock();
  std::cout << " Work done :  " << std::this_thread::get_id() << std::endl;
}


int main() {
  cout << endl << endl << " START " <<  " Threads : Object locks" << endl;
  cout << "------------------------------------------------------- " << endl;

  std::thread t(workOnResource);
  std::thread t2(workOnResource);

  t.join();
  t2.join();

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
