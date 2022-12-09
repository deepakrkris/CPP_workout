#include <iostream>
using namespace std;

int main()
{
    cout << endl << endl << " START " <<  " auto keyword " << endl;
    cout << "------------------------------------------------------- " << endl;  
    int array[] = { 21, 12, 13, 94, 5 };

    cout << " array iteration ";

    for(auto i : array) {
        cout << i << " ";
    }
    cout << endl << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
