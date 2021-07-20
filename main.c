#include <stdio.h>
#include <stdlib.h>

int calculateLocation(int *arr, int size);

int sum_distance(int *arr, int size, int calc_val)
{
    int sum;
    int n;

    sum = 0;
    for (n = 0; n < size; n++)
    {
        sum += abs(calc_val - arr[n]);
    }
    return (sum);
}

int max_val_of_arr(int *arr, int size)
{
    int max;
    int n;

    max = 0;
    for (n = 0; n < size; n++)
    {
       if (max < arr[n])
       {
           max = arr[n];
       }
    }
    return (max);
}

int main() {
    int arr[13] = {9,1,0,2,3,4,6,8,7,10,5,20,30};
    int size = sizeof(arr) / sizeof(int);
    int found_val;
    int max_val;
    int min_sum_dist;
    int val_with_min_sum_dist;
    int curr_val;
    int dist;

    found_val = calculateLocation(arr, size);
    printf("Calculated location of gas tube = %d\n", found_val);

    //Check the result
    max_val = max_val_of_arr(arr, size);
    min_sum_dist = sum_distance(arr, size, 0);
    for (dist = 0; dist < max_val; dist++)
    {
        curr_val = sum_distance(arr, size, dist);
        if (min_sum_dist > curr_val)
        {
            min_sum_dist = curr_val;
            val_with_min_sum_dist = dist;
        }
    }
    if (val_with_min_sum_dist == found_val)
        printf("Calculated value is CORRECT\n");
    else
        printf("Calculated value is WRONG\n");

    return 0;
}
