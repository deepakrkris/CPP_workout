#include <iostream>
#include <algorithm>

using namespace std;

int main() {    
    cout << endl << endl << " START " <<  " Lambda Function " << endl;
    cout << "------------------------------------------------------- " << endl;

    int lastc = 0;
    char s[] = "i am going on a long ride to the moon";

    auto first_letter_caps = [&lastc](char c) -> char {
        char t = (lastc == 0 || lastc == ' ') ? toupper(c) : c;
        lastc = c;
        return t;
    };

    transform(s, s + strlen(s), s, first_letter_caps);

    cout << "tranformed string with lambda :  " << s;

    cout << endl << "------------------------------------------------------- " << endl << endl ;
    cout << endl << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
