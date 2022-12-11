#include <chrono>
#include <iostream>
#include <thread>
#include <stdlib.h> /* srand, rand */

using namespace std;

class ValueProcessor {

  public:
    ValueProcessor(int& i_):i{i_}{};

    void operator () (int k, int sleep_millis){

      /* create random seed and generate number between 1 and sleep_millis , add 100 to random number */  
      srand (time(NULL));
      int random_sleep_millis = rand() % sleep_millis + 100;

      std::cout << " Thread : " << std::this_thread::get_id() << " random_sleep_millis : " << random_sleep_millis << std::endl;

      for (unsigned int j= 0; j <= 5; ++j) {
        // sleep inbetween processing number
        std::this_thread::sleep_for(std::chrono::milliseconds(random_sleep_millis));

        i += k;
        // number processed
        std::cout << " Thread : " << std::this_thread::get_id() << " Value : " << i << std::endl;
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
  cout << endl << endl << " START " <<  " Threads " << endl;
  cout << "------------------------------------------------------- " << endl;

  std::cout << std::endl;

  int value = 1000;

  std::thread t1(ValueProcessor(value), 5, 50);
  std::thread t2(ValueProcessor(value), 5, 20);
  
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
