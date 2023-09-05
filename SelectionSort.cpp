#include <iostream>
using namespace std;

void swapValues(int *_value1, int *_value2)
{
    int temp = *_value1;
    *_value1 = *_value2;
    *_value2 = temp;
}

void SelectionSort(int _array[], int _arraySize)
{
    for (int i = 0; i < _arraySize - 1; i++)
    {
        int tempMinimumValue = _array[i];
        int tempMinimumIndex = -1;
        for (int j = i; j < _arraySize - 1; j++)
        {
            if (_array[j] < tempMinimumValue)
            {
                tempMinimumIndex = j;
                tempMinimumValue = _array[j];
            }
        }
        (tempMinimumIndex > -1) ? swapValues(&_array[i], &_array[tempMinimumIndex]) : void();
    }
}

int main()
{
    int array[10] = {12, 54, 1, 5, 32, 7, 9, 10, 19, 13};
    int arraySize = sizeof(array) / sizeof(array[0]);

    cout << "The Unsorted array is: ";
    for (int i = 0; i < arraySize - 1; i++)
        cout << array[i] << " , ";

    SelectionSort(array, arraySize);

    cout << endl
         << "The Sorted array is: ";
    for (int i = 0; i < arraySize - 1; i++)
        cout << array[i] << " , ";

    return 0;
}