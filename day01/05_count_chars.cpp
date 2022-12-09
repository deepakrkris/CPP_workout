#include <iostream>
using namespace std;

int main() {
    cout << endl << endl << " START " <<  " Count chars " << endl;
    cout << "------------------------------------------------------- " << endl;  

    std::string s = "new string";

    int count = 0;
    while(s[count]) {
        ++count;
    }
    printf("The number of characters is: %d\n", count);

    count = 0;
    for(char c : s) {
        ++count;
    }
    printf("The number of characters is: %d\n", count);

    count = 0;
    for(count = 0; s[count]; ++count)
        ;
    printf("The number of characters is: %d\n", count);

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
}
