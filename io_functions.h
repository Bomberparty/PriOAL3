#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>

namespace iof
{
    void read_matrix_from_console(int **matrix, int *n);

    void read_matrix_from_file(int **matrix, int *n);
}

#endif