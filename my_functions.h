#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <iostream>

namespace myf
{
    int *compute_min_elements(int **arr, int n);

    int *find_first_positive(int **arr, int n);

    int *find_sum_after_negative(int **arr, int n);

    int *find_sum_before_negative(int **arr, int n);
}

#endif