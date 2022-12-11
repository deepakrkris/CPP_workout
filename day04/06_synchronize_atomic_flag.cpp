#include <chrono>
#include <iostream>
#include <thread>
#include <stdlib.h> /* srand, rand */

using namespace std;

class Processlock{
  std::atomic_flag flag;

public:
  Processlock(): flag(ATOMIC_FLAG_INIT){}

  void lock() {
    while( flag.test_and_set() );
  }

  void unlock() {
    flag.clear();
  }
};

Processlock spin;

class ValueProcessor {

  public:
    ValueProcessor(int& i_):i{i_}{};

    void operator () (int k) {
      for (unsigned int j= 0; j <= 5; ++j) {
        spin.lock();
        std::cout << "Lock acquired by Thread : " << std::this_thread::get_id() << std::endl;
        i += k;
        // number processed
        std::cout << " Thread : " << std::this_thread::get_id() << " Value : " << i << std::endl;
        spin.unlock();

        // sleep inbetween processing number
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  private:
    int& i;
};

/**
 * @brief 
 *    Challenge: Fix following main method from unintended thread behaviour, result should include counts from all thread workers
 * 
 * 
 * @return int 
 */
int main() {
  cout << endl << endl << " START " <<  " Thread : locks " << endl;
  cout << "------------------------------------------------------- " << endl;

  std::cout << std::endl;

  int value = 1000;

  std::thread t1(ValueProcessor(value), 5);
  std::thread t2(ValueProcessor(value), 5);
  
  // Problem : detach separates child thread and causes unintended behaviour - FIX This
  // t1.detach();
  // FIX : change detach to join
  t1.join();
  t2.join();

  std::cout << std::endl << std::endl << "Final Value = " << value << std::endl;

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
