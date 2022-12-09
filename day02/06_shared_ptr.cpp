#include <iostream>
#include <memory>

using namespace std;

class Data {
    std::string _s;
    public :
    Data(const std::string & s) : _s(s) {};
    ~Data() {
        cout << "Resource " << _s << " is destroyed";
    };
    std::string get_value() {
        return _s;
    };
};

void handlePointer(shared_ptr<Data> p) {
    cout << "inside function " << p->get_value() << endl;
}

void scope_function() {
    auto p = std::make_shared<Data>("One");
    handlePointer(p);
    cout << "after function " << p->get_value() << endl;
}

int main() {
    cout << endl << endl << " START " <<  " shared pointer " << endl;
    cout << "------------------------------------------------------- " << endl;

    scope_function();

    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
