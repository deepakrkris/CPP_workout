#include <iostream>
#include <array>
#include <iterator>
#include <vector>

using namespace std;

void pretty_print (int input [], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << input[i] << ' ';
    }
    std::cout << '\n';
}

void merge(int array [], int const begin, int const mid, int const end) {
    int leftPsize = mid - begin + 1;
    int rightPsize = end - mid;

    // cout << " begin " << begin << " leftPsize " << leftPsize << endl;
    // cout << " mid " << mid << " end " << end << " rightPsize " << rightPsize << endl;

    int L[leftPsize], R[rightPsize];

    for (int i = 0; i < leftPsize; i++)
        L[i] = array[begin + i];
    for (int j = 0; j < rightPsize; j++)
        R[j] = array[mid + 1 + j];

    int left = 0;
    int right = 0;

    for (int index = begin; index <= end; index ++) {
        if (left == leftPsize) {
            array[index] = R[right];
            right++;
        } else if (right == rightPsize) {
            array[index] = L[left];
            left++;
        } else if (L[left] < R[right]) {
            array[index] = L[left];
            left++;
        } else if (L[left] > R[right]) {
            array[index] = R[right];
            right++;
        }
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    // cout << " begin " << begin << endl;
    // cout << " end " << end << endl;

    if (begin >= end)
        return;
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 
int main()
{
    cout << endl << endl << " START " <<  " Merge Sort !!! " << endl;
    cout << "------------------------------------------------------- " << endl;

    int numbers[] = { 33, 12, 24, 34, 2 };

    pretty_print(numbers, sizeof(numbers)/sizeof(numbers[0]));

    mergeSort(numbers, 0, sizeof(numbers)/sizeof(numbers[0]) - 1);
  
    cout << endl << endl << " After Sort :  " << endl;
  
    pretty_print(numbers, sizeof(numbers)/sizeof(numbers[0]));

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}
