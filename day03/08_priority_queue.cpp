#include <iostream>
#include <queue>

using namespace std;

struct Event {
    int priorit {};
    char data {' '};

    friend bool operator < (Event const& l , Event const& r) {
        return l.priorit < r.priorit;
    }

    friend std::ostream& operator << (std::ostream& o, Event const& e) {
        return o << " { " << e.data << " , " << e.priorit << " } " ;
    }
};

int main() {
    cout << endl << endl << " START " <<  " Datastructures : Priority Queue " << endl;
    cout << "------------------------------------------------------- " << endl;

    priority_queue<int> q1;

    for (auto i : {20, 7, 9, 23, 99}) {
        q1.push(i);
    }

    while (q1.size()) {
        cout << q1.top() << " , ";
        q1.pop();
    }
    cout << endl << endl ;

    priority_queue<Event> events;
    Event event_list[] = { {20, 'B'} , {10 , 'A'}, {8, 'C'} , { 24 , 'Z' } , { 99 , 'Q' } };
  
    std::cout << "Fill the events queue:\n";
  
    for (const auto e : event_list) {
        cout << e << " , ";
        events.push(e);
    }

    std::cout << "\n" "Process events:\n";

    while (events.size()) {
        cout << events.top() << " , ";
        events.pop();
    }
    cout << endl << endl ;

    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
