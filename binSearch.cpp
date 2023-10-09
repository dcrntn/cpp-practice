#include <iostream>

int binarySearch(int array[], int x, int low, int high)
{

    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = low + (high - low) / 2;

        if (x == array[mid])
        {
            return mid;
        }
        // X is on the left
        if (x < array[mid])
        {
            return binarySearch(array, x, low, mid - 1);
        }
        // X is on the right
        else if (x > array[mid])
        {
            return binarySearch(array, x, mid + 1, high);
        }
    }
}

int main()
{
    int arr[] = {12,
                 2,
                 341,
                 4,
                 524,
                 65,
                 72,
                 8};

    int searchedX = 72;

    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    int res = binarySearch(arr, searchedX, 0, sizeArr - 1);
    printf("The result is: %d \n", res);
}