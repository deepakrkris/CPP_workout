#include <iostream>
#include <string>
using namespace std;

class Animal {
    std::string _name;
    std::string _type;
    // private constructor
    Animal() {};
   
    protected :
    Animal(const string & name, const string & type) : _name(name) , _type(type) {
        cout << " we have a pet " << name << " which is a " << type << endl;
    };

    public :
    virtual std::string speak() = 0;

    std::string getName() {
        return _name;
    }

    std::string move() {
        if (_type == "Bird") {
            return " Flys ";
        } else if (_type == "Fish") {
            return " Swims ";
        }
        return " Walks ";
    };
};

class Dog : public Animal {
    public :
    Dog(std::string name) : Animal(name, "Mammal") {
    };

    std::string speak() {
        return " BOW BOW "; 
    };
};

class Piranha : public Animal {
    public :
    Piranha(std::string name) : Animal(name, "Fish") {};

    std::string speak() {
        return " KREEECH ";
    };
};

int main() {
    cout << endl << endl << " START " <<  " math operator " << endl;
    cout << "------------------------------------------------------- " << endl;

    Dog d = Dog("juju");
    Piranha p = Piranha("pp");

    cout << d.getName() <<  "  " << d.move() << d.speak() << endl;
    cout << p.getName() <<  "  " << p.move() << p.speak() << endl;

    Animal *a;

    a = &d;
    cout << a->getName() <<  "  " << a->move() << a->speak() << endl;
    a = &p;
    cout << a->getName() <<  "  " << a->move() << a->speak() << endl;
 
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
