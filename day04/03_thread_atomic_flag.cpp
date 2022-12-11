#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

/*
Create ten workers with each owning a number from 1...10
Print following pattern where each thread prints one number per line

use spin lock

1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 5 4 6 7 8 9 10
1 2 3 5 4 6 7 8 9 10
1 2 3 5 4 6 7 8 9 10
*/

class Spinlock{
  std::atomic_flag flag;

public:
  Spinlock(): flag(ATOMIC_FLAG_INIT){}

  void lock() {
      // acquire lock
      while (flag.test_and_set(std::memory_order_acquire)) {
          while (flag.test(std::memory_order_relaxed));
      }
  }

  void unlock() {
    // release lock
    flag.clear(std::memory_order_release);
  }
};

Spinlock spin;

void workOnResource(int num) {
  std::this_thread::sleep_for(std::chrono::milliseconds(10 * num));
  static int out{};

  for (int cnt = 0; cnt < 10; ++cnt) {
      spin.lock();
      std::cout << num << ((++out % 10) == 0 ? '\n' : ' ');
      spin.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << " Work done :  " << num << std::endl;
}

int main() {
  cout << endl << endl << " START " <<  " Threads : atomic locks" << endl;
  cout << "------------------------------------------------------- " << endl;

  std::vector<std::thread> v;
  for (int n = 1; n <=10; ++n) {
      v.emplace_back(workOnResource, n);
  }
  for (auto& t : v) {
      t.join();
  }

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
