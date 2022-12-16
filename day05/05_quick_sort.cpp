#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void pretty_print (vector<int>& array) {
    for (auto e : array)
        std::cout << e << ", ";
    std::cout << endl;
}

/**
 * @brief 
 * 
 * take pivot value as value@ pEnd
 *      declare start : to move from start to end of window
 *      declare partition : set to pEnd , this is where we would insert the pivot value finally for this partition
 *      declare end : to keep track of left of partition
 * 
 * contract window start <-> end
 *      beginning of iteration partition index is guaranteed to hold value <= pivot value
 *      end of iteration partition index should be holding value <= pivot value
 * 
 * if value@ start > pivot value
 *         move value@ start to partition index
 *         move value@ end to start index
 *         reduce end index
 *         reduce partition index
 * 
 * @param array
 * @param pStart
 * @param pEnd
 */
void quick_sort(vector<int>& array, int pStart, int pEnd) {
    if (pStart < 0 || pEnd > array.size() || (pEnd - pStart) <= 0 ) return; 

    cout << "pStart   :   " << pStart << "   pEnd   :    " << pEnd << endl;

    int partition = pEnd;
    int pivotValue = array[partition];
    int start = pStart;
    int end = pEnd - 1;

    while (start <= end) {
        if (array[start] > pivotValue) {
            array[partition] = array[start];
            array[start] = array[end];
            --partition;
            --end;
        } else {
            ++start;
        }
    }

    array[partition] = pivotValue;

    quick_sort(array, pStart, partition - 1);
    quick_sort(array, partition + 1, pEnd);
}

/**
 * @brief 
 * 
 * V2 : different approach to quick sort
 *   For a partition, start moving smaller elements (when compared to pivot value) to left
 *   
 *   declare a pointer, insertIndex - set to pStart : this is where we would insert the pivot value finally for this partition
 *                      * all values left of insertIndex in the partition is asserted to be lesser than pivot value
 *                      * all values between right of insertIndex and index - 1 is asserted to be greater than pivot value 
 * 
 *   declare a pointer , index - which moves across the partition checking if its lesser than the pivot value
 *   
 * if value@ index < pivot value :
 *       move value@index to insertIndex , and value@ insertIndex to index , increment insertIndex
 *               since index has moved ahead of insertIndex, value@ insertIndex is greater than pivot value anyway
 * 
 * can insertIndex be same as index at any time ?
 *      if all elements in the partition so far had been lesser than the pivot value,
 *          then it is possible for insertIndex to be equal to index for an iteration
 * 
 * Final step is to swap the value at pEnd ie the pivot value with the value@ insertIndex
 *      this is because value@ insertIndex > pivot value
 *           * index has either moved ahead of insertIndex by pushing all smaller values to insertIndex - 1
 *           * insertIndex == pEnd , all values so far has been smaller, we ended up swapping every element with itself
 *                          and hence moved the insertIndex alongside the index value
 * 
 * @param array 
 * @param pStart 
 * @param pEnd 
 */
void quick_sort_v2(vector<int>& array, int pStart, int pEnd) {
    if (pStart < 0 || pEnd > array.size() || (pEnd - pStart) <= 0 ) return; 

    cout << "pStart   :   " << pStart << "   pEnd   :    " << pEnd << endl;

    int pivotValue = array[pEnd];
    int insertIndex = pStart;

    for (int index = pStart ; index < pEnd; ++index) {
        if (array[index] < pivotValue) {
            swap(array[index], array[insertIndex]);
            ++insertIndex;
        }
    }

    swap(array[insertIndex], array[pEnd]);

    quick_sort(array, pStart, insertIndex - 1);
    quick_sort(array, insertIndex + 1, pEnd);
}

int main()
{
    cout << endl << endl << " START " <<  " Quick Sort !!! " << endl;
    cout << "------------------------------------------------------- " << endl;

    vector<int> array = { 34, 2, 24, 12, 33 };

    pretty_print(array);

    quick_sort_v2(array, 0, array.size() - 1);

    cout << endl << endl << " After Quick Sort :  " << endl;

    pretty_print(array);

    cout << "------------------------------------------------------- " << endl << endl ; 
    cout << "------------------------------------------------------- " << endl << endl ;
    return 0;
}

