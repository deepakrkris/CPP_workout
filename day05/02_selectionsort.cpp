#include <iostream>
#include <vector>

using namespace std;
 
auto pretty_print = [](vector<int>& nums) { std::for_each(nums.begin(), nums.end(), [](int& n) { std::cout << n << " "; }); std::cout << std::endl;};

void selectionSort(vector<int>& numbers) {

    for (int i = 0; i < numbers.size(); ++i) {
        int minId = i;
        for (int j = i + 1; j < numbers.size(); ++j) {
            if (numbers[j] < numbers[minId]) {
                minId = j;
            }
        }
        swap(numbers[i], numbers[minId]);
    }
}

int main()
{
    cout << endl << endl << " START " <<  " HELLO !!! " << endl;
    cout << "------------------------------------------------------- " << endl;

    vector<int> numbers = { 33, 12, 24, 34, 2 };

    pretty_print(numbers);

    selectionSort(numbers);
  
    cout << endl << endl << " After Sort :  " << endl;
  
    pretty_print(numbers);

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
