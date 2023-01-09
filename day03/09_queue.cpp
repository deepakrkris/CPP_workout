#include <iostream>
#include <queue>
  
using namespace std;
  
// Print the queue
void print_queue(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
    cout << '\n';
}
  
// Driver Code
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
  
    cout << "The queue is : ";
    print_queue(q1);
    
    cout<<q1.empty();  //returns false since q1 is not empty
  
    return 0;
}
