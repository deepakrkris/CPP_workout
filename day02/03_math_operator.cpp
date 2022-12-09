#include <iostream>
#include <string>
using namespace std;

class Math {
    int num = 0;

public :
    Math(int value) : num(value) {};

    Math(const Math & m) : num(m.num) {
      cout << endl << "copy constructor : " << num << endl;
    };

    std::string string() const;     // return a formatted STL string
    std::string raw_string() const;     // return a non-reduced STL string

    int get_value() const {
        return num;
    };

    // Math operator + (const Math & ) const;
    // Math operator - (const Math & ) const;
    // Math operator / (const Math & ) const;
    // Math operator * (const Math & ) const;
};

std::string Math::string() const {
    return std::to_string(num);
}

std::string Math::raw_string() const {
    return std::to_string(num);
}

/*
Math Math::operator * (const Math& rs) const {
   cout << endl << " MULTIPLY " ;
   return Math(num * rs.num);
}

Math Math::operator / (const Math& rs) const {
   cout << endl << " DIVIDE " ;
   return Math(num / rs.num);
}

Math Math::operator + (const Math& rs) const {
   cout << endl << " ADD " ;
   return Math(num + rs.num);
}

Math Math::operator - (const Math& rs) const {
   cout << endl << " SUBTRACT " ;
   return Math(num - rs.num);
}
*/

std::ostream & operator << (std::ostream & o, const Math & m) {
    return o << m.string();
}

Math operator * (const Math& ls, const Math& rs) {
   cout << " ( Multiplication ) " ;
   return Math(ls.get_value() * rs.get_value());
}

Math operator / (const Math& ls, const Math& rs) {
   cout << " ( Division ) " ;
   return Math(ls.get_value() / rs.get_value());
}

Math operator + (const Math& ls, const Math& rs) {
   cout << " ( Addition ) " ;
   return Math(ls.get_value() + rs.get_value());
}

Math operator - (const Math& ls, const Math& rs) {
   cout << " ( Subtraction ) " ;
   return Math(ls.get_value() - rs.get_value());
}

int main() {
    cout << endl << endl << " START " <<  " math operator " << endl;
    cout << "------------------------------------------------------- " << endl;

    Math a = Math(20);

    std::cout << a << " + " << 20 << " = " << a + 20 << std::endl;
    std::cout << a << " - " << 20 << " = " << a - 20 << std::endl;
    std::cout << a << " * " << 20 << " = " << a * 20 << std::endl;
    std::cout << a << " / " << 20 << " = " << a / 20 << std::endl;

    std::cout << std::endl;
    
    std::cout << 20 << " + " << a << " = " << 20 + a << std::endl;
    std::cout << 20 << " - " << a << " = " << 20 - a << std::endl;
    std::cout << 20 << " * " << a << " = " << 20 * a << std::endl;
    std::cout << 20 << " / " << a << " = " << 20 / a << std::endl;
 
    cout << endl << "------------------------------------------------------- " << endl << endl ; 
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0; 
}
