#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Divide array by considering the last element as pivot
// and moves all smaller element to left of
// it and greater elements to right
int divide_arr(int *arr, int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// Return element value of arr[]
// To have O = O(N) we use recursive search
int get_value_at_pos(int *arr, int left, int right, int pos)
{
    // If pos is smaller than number of elements
    if (pos > 0 && pos <= right - left + 1)
    {
        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int index = divide_arr(arr, left, right);

        // If current position is same as pos
        // Needed value is found, return it
        if (index - left == pos - 1)
            return arr[index];

        // If position is more, call func again for left subarray
        if (index - left > pos - 1)
            return get_value_at_pos(arr, left, index - 1, pos);

        // Else call it for right subarray
        return get_value_at_pos(arr, index + 1, right, pos - index + left - 1);
    }
}

// Function calculates closest location of gas tube
// This location it's the median value of arr[]
float calculateLocation(int *arr, int size)
{
    int median_pos;

    if (size == 2)
        return  ((float)(arr[0] + arr[1]) / 2);
    if (size % 2 == 0)
        median_pos = size / 2;
    else
        median_pos = size / 2 + 1;
    return(get_value_at_pos(arr, 0, size - 1, median_pos));
}