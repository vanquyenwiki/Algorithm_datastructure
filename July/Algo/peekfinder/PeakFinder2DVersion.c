#include <stdio.h>
#include <stddef.h>

/*
 *
 * Peak definition 
 *  1-D version : arr[0] arr[1] arr[2] arr[3] arr[4] arr[5] 
 *      The position 'n' is peak when 'arr[n] >= a[n - 1] && arr[n] >= a[n + 1]'
 *      The position 'n' is peak when 'arr[5] >= a[4]'
 * 
 *  2-D version : b is peak if only if b >= a, b >= e, b >= c, b >= f
 *
 *                 x a x
 *                 e b f
 *                 x c x
 * 
 * 
 */

int FindGlobalMaximunColum(int arr[4][4], int col, int row) {
    int i, idx = 0;
    int val = arr[0][col];

    for (i = 0; i < row; i++) {
        if (arr[i][col] > val) {
            idx = i;
            val = arr[i][col];
        }
    }

    return idx;
}

int FindPeak2DVersion(int arr[4][4], int col, int row) {
    int start = 0;
    int end = col;
    int col_mid, row_mid;
    
    while (start <= end) {
        col_mid = (start + end)/2;
        row_mid = FindGlobalMaximunColum(arr, col_mid, row);
        
        if (arr[row_mid][col_mid] < arr[row_mid][col_mid - 1]) {
            end = col_mid - 1;
        } else if (arr[row_mid][col_mid] < arr[row_mid][col_mid + 1]) {
            start = col_mid + 1;
        }
        else {
            return arr[row_mid][col_mid];
        }
    }

    return -1;
}

int main(int argc, char **argv)
{
    int arr2d[4][4] = {
                        {10,  8, 10, 10},
                        {14, 13, 12, 11},
                        {15,  9, 11, 21},
                        {16, 17, 19, 20},
                    };
    int peak;    
    for (int i = 0; i < 4; i++)  {
        for (int j = 0; j < 4; j++) {
            printf("%d, ", arr2d[i][j]);            
        }
        printf("\n");
    }

    peak = FindPeak2DVersion(arr2d, 4, 4);
    printf("2-D Peak is : %d\n", peak);
    return 0;
}