#include <iostream>

using namespace std;

class Log {
    int _base;
  
    public:
    Log(int base) : _base(base) {};

    int operator () (int num);
};

int Log::operator () (int num) {
    int result = 0;

    while (num > 1) {
        num = num / _base;
        ++result;
    }

    return result;
}

int main() {
    cout << endl << endl << " START " <<  " math operator " << endl;
    cout << "------------------------------------------------------- " << endl;

    Log log2(2);

    cout << " Log base 2 of 8 " << log2(8) << endl;
 
    Log log3(3);

    cout << " Log base 3 of 27 " << log3(27) << endl;

    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
