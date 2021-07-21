#include <stdio.h>
#include <stdlib.h>

float calculateLocation(int *arr, int size);

int sum_distance(int *arr, int size, int current_dist)
{
    int sum;
    int n;

    sum = 0;
    for (n = 0; n < size; n++)
    {
        sum += abs(current_dist - arr[n]);
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

void check_result(int *arr, int size, float found_val)
{
    float   max_val;
    float   min_sum_dist;
    float   val_with_min_sum_dist;
    float   curr_val;
    float   dist;

    if (size == 2)
        val_with_min_sum_dist = (float)(arr[0] + arr[1]) / 2;
    else
    {
        max_val = max_val_of_arr(arr, size);
        min_sum_dist = sum_distance(arr, size, 0);
        for (dist = 0; dist <= max_val; dist++) {
            curr_val = sum_distance(arr, size, dist);
            if (min_sum_dist > curr_val) {
                min_sum_dist = curr_val;
                val_with_min_sum_dist = dist;
            }
        }
    }
    if (val_with_min_sum_dist == found_val)
        printf("Calculated value is CORRECT\n");
    else
        printf("Calculated value is WRONG\n");
}

int main() {
    int     arr[11] = {9,3,4,6,8,7,10,5};
    int     size = sizeof(arr) / sizeof(int);
    float   found_val;

    found_val = calculateLocation(arr, size);
    printf("Calculated location of gas tube = %f\n", found_val);

    check_result(arr, size, found_val);
    return 0;
}
