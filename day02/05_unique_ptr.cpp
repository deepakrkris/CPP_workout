#include <iostream>
#include <memory> // for std::unique_ptr

using namespace std;

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n" << endl; }
	~Resource() { std::cout << "Resource destroyed\n" << endl; }
	friend std::ostream& operator<<(std::ostream& out, const Resource &res)
	{
		out << "I am a resource" << endl;
		return out;
	}
};

std::unique_ptr<Resource> createResource()
{
     return std::make_unique<Resource>();
}

std::unique_ptr<Resource> inner_scope() {
    cout << "Inner Scope : Begins " << endl << endl;

    auto ptr{ createResource() };

    cout << "Inner Scope : Ends " << endl << endl;
    return ptr;
}

void outer_scope() {
    cout << "Outer Scope : Begins "  << endl << endl;

    auto ptr = inner_scope();
  
    cout << "after call to inner scope  : " << *ptr << endl;

    cout << "Outer Scope : Ends "  << endl << endl;
}

int main()
{
    cout << endl << endl << " START " <<  " unique pointer " << endl;
    cout << "------------------------------------------------------- " << endl;

    outer_scope();
 
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}