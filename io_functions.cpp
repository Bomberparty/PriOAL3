#include "io_functions.h"
namespace iof
{

    void read_matrix_from_console(int** matrix, int* n) 
    {
        std::cout << "Введите размерность квадратной матрицы: ";
        while (!(std::cin >> *n) || *n <= 0) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Введите положительное целое число: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        matrix = new int*[*n];
        for (int i = 0; i < *n; i++) 
        {
            (matrix)[i] = new int[*n];
            std::cout << "Введите элементы " << i + 1 << "-й строки матрицы:" << std::endl;
            for (int j = 0; j < *n; j++) 
            {
                while (!(std::cin >> *(matrix + i)[j])) 
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Некорректный ввод. Введите целое число: ";
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    void read_matrix_from_file( int** matrix, int* n) 
    {
        std::ifstream file("input.txt");
        if (!file) 
        {
            throw std::runtime_error("Не удалось открыть файл ");
        }

        file >> *n;
        if (!file || *n <= 0) 
        {
            throw std::runtime_error("Некорректный формат данных в файле. Исправьте содержимое файла и перезапустите программу.");
        }

        matrix = new int*[*n];
        for (int i = 0; i < *n; i++) 
        {
            (matrix)[i] = new int[*n];
            for (int j = 0; j < *n; j++) 
            {
                if (!(file >> *(matrix + i)[j])) 
                {
                    throw std::runtime_error("Некорректный формат данных в файле. Исправьте содержимое файла и перезапустите программу.");
                }
            }
        }
    }

    void write_results_to_console(int* resultA, int* resultB, int* resultC, int* resultD , int* n)
    {
        using namespace std;

        cout << "А) ";
        for (int i = 0; i <= *n; i++)
            cout << resultA[i] << " ";
        cout << endl;
        cout << "Б) ";
        for (int i = 0; i <= *n; i++)
            cout << resultB[i] << " ";
        cout << endl;
        cout << "В) ";
        for (int i = 0; i <= *n; i++)
            cout << resultC[i] << " ";
        cout << endl;
        cout << "Г) ";
        for (int i = 0; i <= *n; i++)
            cout << resultD[i] << " ";
        cout << endl;
    }

    void wirte_results_to_file(int* resultA, int* resultB, int* resultC, int* resultD , int* n)
    {
        using namespace std;

        ofstream output("output.txt");

        output << "А) ";
        for (int i = 0; i <= *n; i++)
            output << resultA[i] << " ";
        output << endl;
        output << "Б) ";
        for (int i = 0; i <= *n; i++)
            output << resultB[i] << " ";
        output << endl;
        output << "В) ";
        for (int i = 0; i <= *n; i++)
            output << resultC[i] << " ";
        output << endl;
        output << "Г) ";
        for (int i = 0; i <= *n; i++)
            output << resultD[i] << " ";
        output << endl;

        output.close();
    }
}