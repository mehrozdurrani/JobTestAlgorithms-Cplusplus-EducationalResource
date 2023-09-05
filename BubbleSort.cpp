#include <iostream>

using namespace std;

void SwapValues(int *_value1, int *_value2)
{
    int temp = *_value1;
    *_value1 = *_value2;
    *_value2 = temp;
}

void BubbleSort(int _array[], int _arraySize)
{
    for (int i = 0; i < _arraySize - 1; i++)
    {
        for (int j = 0; j < _arraySize - 1 - i; j++)
        {
            if (_array[j + 1] < _array[j])
                SwapValues(&_array[j + 1], &_array[j]);
        }
    }
}

int main()
{
    int array[10] = {12, 54, 1, 5, 32, 7, 9, 10, 19, 13};
    int arraySize = sizeof(array) / sizeof(array[0]);

    cout << "The Unsorted array is: ";
    for (int i = 0; i < arraySize - 1; i++)
        cout << array[i] << " , ";

    BubbleSort(array, arraySize);

    cout << endl
         << "The Sorted array is: ";
    for (int i = 0; i < arraySize - 1; i++)
        cout << array[i] << " , ";

    return 0;
}
