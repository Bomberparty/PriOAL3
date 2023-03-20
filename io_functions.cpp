#include "io_functions.h"
namespace iof
{
    bool isInt(std::string nval)
    {
        char *endptr;
        try
        {
            std::strtol(nval.c_str(), &endptr, 10);
        }
        catch(const std::exception& e)
        {
            return false;
        }
        return (*endptr == '\0');
    }

    int **read_matrix_from_console(int *n)
    {
        std::cout << "Введите размерность квадратной матрицы: ";
        while (!(std::cin >> *n) || *n <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Введите положительное целое число: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        int **matrix = new int*[*n];
        for (int i = 0; i < *n; i++)
        {
            matrix[i] = new int[*n];
            std::cout << "Введите элементы " << i + 1 << "-й строки матрицы (После каждого значения переносите строку): " << std::endl;
            for (int j = 0; j < *n; j++)
            {
                while (true)
                {
                    std::string * nval = new std::string;
                    std::getline(std::cin, *nval);
                    if(isInt(*nval))
                    {
                        matrix[i][j] = stoi(*nval);
                        break;
                    }
                    else
                    {
                        std::cout << "Введено неверное значение! Повторите ввод." << std::endl;
                        continue;   
                    }
                }
            }
        }

        return matrix;
    }

    int **read_matrix_from_file(int *n)
    {
        std::ifstream file("input.txt");
        if (!file)
        {
            throw std::runtime_error("Не удалось открыть файл. Создайте файл и перезапустите программу.");
        }

        file >> *n;
        if (!file || *n <= 0)
        {
            throw std::runtime_error("Некорректный формат данных в файле. Исправьте содержимое файла и перезапустите программу.");
        }

        int **matrix = new int*[*n]; 
        for (int i = 0; i < *n; i++)
        {
            matrix[i] = new int[*n];
            for (int j = 0; j < *n; j++)
            {
                std::string * nval = new std::string;
                std::getline(file, *nval);
                if(isInt(*nval))
                {
                    matrix[i][j] = stoi(*nval);
                    break;
                }
                else
                {
                    throw std::runtime_error("Некорректный формат данных в файле. Исправьте содержимое файла и перезапустите программу."); 
                }
                delete nval;
            }
        }

        return matrix;
    }

    void write_results_to_console(int *resultA, int *resultB, int *resultC, int *resultD, int *n)
    {
        using namespace std;

        cout << "А) ";
        for (int i = 0; i < *n; i++)
            cout << resultA[i] << " ";
        cout << endl;
        cout << "Б) ";
        for (int i = 0; i < *n; i++)
            cout << resultB[i] << " ";
        cout << endl;
        cout << "В) ";
        for (int i = 0; i < *n; i++)
            cout << resultC[i] << " ";
        cout << endl;
        cout << "Г) ";
        for (int i = 0; i < *n; i++)
            cout << resultD[i] << " ";
        cout << endl;
    }

    void wirte_results_to_file(int *resultA, int *resultB, int *resultC, int *resultD, int *n)
    {
        using namespace std;

        ofstream output("output.txt");

        output << "А) ";
        for (int i = 0; i < *n; i++)
            output << resultA[i] << " ";
        output << endl;
        output << "Б) ";
        for (int i = 0; i < *n; i++)
            output << resultB[i] << " ";
        output << endl;
        output << "В) ";
        for (int i = 0; i < *n; i++)
            output << resultC[i] << " ";
        output << endl;
        output << "Г) ";
        for (int i = 0; i < *n; i++)
            output << resultD[i] << " ";
        output << endl;

        output.close();
    }
}