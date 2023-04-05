#include "my_functions.h"
namespace myf
{

    int *compute_min_elements(int **arr, int n)
    {
        int *result = new int[n];
        for (int i = 0; i < n; i++)
        {
            int min = arr[i][0];
            for (int j = 1; j <= i; j++)
            {
                if (arr[i][j] < min)
                {
                    min = arr[i][j];
                }
            }
            result[i] = min;
        }
        return result;
    }

    int *find_first_positive(int **arr, int n)
    {
        int *result = new int[n];
        for (int i = 0; i < n; i++)
        {
            int first_positive = 1;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > 0)
                {
                    first_positive = arr[i][j];
                    break;
                }
            }
            result[i] = first_positive;
        }
        return result;
    }

    int *find_sum_after_negative(int **arr, int n)
    {
        int *result = new int[n];
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            bool negative_found = false;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] < 0)
                {
                    negative_found = true;
                }
                else if (negative_found)
                {
                    sum += arr[i][j];
                }
            }
            result[i] = negative_found ? sum : 100;
        }
        return result;
    }

    int *find_sum_before_negative(int **arr, int n)
    {
        int *result = new int[n];
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int last_negative_index = -1;
            for (int j = n - 1; j > -1; j--)
            {
                if (arr[i][j] < 0)
                {
                    last_negative_index = j;
                    break;
                }
            }
            if (last_negative_index == -1)
            {
                result[i] = -1;
                continue;
            }
            for (int j = 0; j < last_negative_index; j++)
            {
                sum += arr[i][j];
            }
            result[i] = sum;
        }
        return result;
    }
}