#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>

namespace iof
{
    bool isInt(std::string nval);

    int **read_matrix_from_console(int *n);

    int **read_matrix_from_file(int *n);

    void write_results_to_console(int **arr, int *resultA, int *resultB, int *resultC, int *resultD, int *n);

    void wirte_results_to_file(int **arr, int *resultA, int *resultB, int *resultC, int *resultD, int *n);
}

#endif