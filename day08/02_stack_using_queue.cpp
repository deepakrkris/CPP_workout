#include <iostream>
#include <queue>

using namespace std;

class StackWithQueue {
    queue<int> original;
    queue<int> backup;

   public:

   int size() {
      return original.size();
   }

  /**
   * @brief
   * 
   *  alternartive approach:
   *                  FIFO 
   *  5    4  3  2  1  0
   *                   ^
   *  ^ LIFO
   * 
   *  push ()
   *   
   *   q1 5
   *
   *   q2 4  3  2  1  0
   *                  ^
   *                  FIFO
   * 
   *   current approach - O(1)
   *   alternative - O(N)
   */
    void push(int x) {
        return original.push(x);
    }


  /**
   * @brief
   *                  FIFO 
   *  5    4  3  2  1  0
   *                   ^
   *  ^ LIFO
   * 
   *  pop ()
   *   q1 5   
   *      ^  
   *      FIFO
   *   
   *   q2 4  3  2  1  0
   *                  ^
   * 
   *  current approach - O(N)
   */
    int pop() {
    
        while (original.size() > 1) {
            backup.push(original.front());
            original.pop();
        }

        auto e = original.front();
        original.pop();

        while (backup.size() > 0) {
            original.push(backup.front());
            backup.pop();
        }

        return e;
    }


    /**
     * @brief 
     * 
     *  Use single queue
     *  
     *  O(N)
     * 
     * @return int 
     */
    int pop_v2() {
    
        int stack_size = original.size();

        while (stack_size > 1) {
            original.push(original.front());
            original.pop();
            --stack_size;
        }

        auto e = original.front();
        original.pop();

        return e;
    }
};

int main() {
  std::cout << std::endl << std::endl << " START " <<  " Stack using queue !!! " << std::endl;
  std::cout << "------------------------------------------------------- " << std::endl;

  StackWithQueue stack;

  for (int i = 0; i < 10; i++) stack.push(i);

  /**
   * @brief
   *                  FIFO 
   *  5    4  3  2  1  0
   *                   ^
   *   
   * 
   */

  while (stack.size() > 0) cout << stack.pop_v2() << " , ";

  std::cout << endl;

  std::cout << "------------------------------------------------------- " << std::endl << std::endl ; 
  std::cout << "------------------------------------------------------- " << std::endl << std::endl ;
  return 0;
}
