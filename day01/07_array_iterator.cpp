#include <iostream>
#include <array>

using namespace std;

int main() {
    cout << endl << endl << " START " <<  " array iterator " << endl;
    cout << "------------------------------------------------------- " << endl;
    array<int, 4> arr = {1 , 2, 5, 8};

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << * it << " , ";
    }
    cout << endl << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0; 
}
