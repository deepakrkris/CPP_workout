#include <iostream>
#include <vector>

using namespace std;
 
auto pretty_print = [](vector<int>& nums) { std::for_each(nums.begin(), nums.end(), [](int& n) { std::cout << n << " "; }); std::cout << std::endl;};

void bubbleSort(vector<int>& numbers) {

    for (int end = numbers.size(); end > -1; --end) {
        for (int start = 1; start < end; ++start) {
            if (numbers[start - 1] > numbers[start]) {
                swap(numbers[start-1], numbers[start]);
            }
        }
    }
}

int main()
{
    cout << endl << endl << " START " <<  " HELLO !!! " << endl;
    cout << "------------------------------------------------------- " << endl;

    vector<int> numbers = { 33, 12, 24, 34, 2 };

    pretty_print(numbers);

    bubbleSort(numbers);
  
    cout << endl << endl << " After Sort :  " << endl;
  
    pretty_print(numbers);

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
