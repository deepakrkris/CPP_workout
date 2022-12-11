#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mut;

void workOnResource(){
  mut.lock();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  mut.unlock();
  std::cout << "Work done" << std::endl;
}

int main(){
  cout << endl << endl << " START " <<  " Threads : mutex" << endl;
  cout << "------------------------------------------------------- " << endl;

  std::thread t(workOnResource);
  std::thread t2(workOnResource);

  t.join();
  t2.join();

  cout << endl << "------------------------------------------------------- " << endl << endl ;
  cout << endl << "------------------------------------------------------- " << endl << endl ;
  return 0;
}
