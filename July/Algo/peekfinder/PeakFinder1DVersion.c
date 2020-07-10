#include <stdio.h>
#include <stddef.h>

/*
 *
 * Peak definition : arr[0] arr[1] arr[2] arr[3] arr[4] arr[5] 
 * The position 'n' is peak when 'arr[n] >= a[n - 1] && arr[n] >= a[n + 1]'
 * The position 'n' is peak when 'arr[5] >= a[4]'
 */
int peakfinder1D_RecursionFuncion(int *p, size_t size)
{
    size_t n = size / 2;
    if (p[n - 1] > p[n])
    { // lelf search
        return peakfinder1D_RecursionFuncion(p, n - 1);
    }
    else if (p[n] < p[n + 1])
    {   // right search.
        return peakfinder1D_RecursionFuncion(p + n + 1, size - 1 - n);
    }

    return p[n];
}

static int getPeakElement_WhileLoop(int *arr, int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end)/2;
        if (arr[mid] < arr[mid - 1]) {
            end = mid;
        } else if (arr[mid] < arr[mid + 1]) {
            start = mid;
        } else {
           return arr[mid];
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    int arr[] = {1, 2, 5, 7, 2, 1, 7, 5};
    int peak;
    peak = peakfinder1D_RecursionFuncion(arr, 8);
    printf("1-D Peak is : %d\n", peak);


    peak = getPeakElement_WhileLoop(arr, 8);
    printf("1-D Peak is : %d\n", peak);

    return 0;
}