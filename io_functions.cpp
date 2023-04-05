#include "io_functions.h"
namespace iof
{
    bool isInt(std::string nval)
    {
        if(nval == "")
            return false;
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

    int **read_matrix_from_console(int &n)
    {
        while(true) {
            std::string * ans = new std::string;
            std::cout << "Введите размерность квадратной матрицы: ";
            std::getline(std::cin, *ans);
            if (isInt(*ans)) {
                n = stoi(*ans);
                if (n <= 0) {
                    std::cout << "Ошибка. Число должно быть положительным!" << std::endl;
                    delete ans;
                    continue;
                } else {
                    delete ans;
                    break;
                }
            }
        }

        int **matrix = new int*[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
            std::cout << "Введите элементы " << i + 1 << "-й строки матрицы (После каждого значения переносите строку): " << std::endl;
            for (int j = 0; j < n; j++)
            {
                while (true)
                {
                    std::string * nval = new std::string;
                    std::getline(std::cin, *nval);
                    if(isInt(*nval))
                    {
                        try
                        {
                            matrix[i][j] = stoi(*nval);
                            delete nval;
                            break;
                        }
                        catch(const std::exception& e)
                        {
                            std::cout << "Введено некорректное значение! Повторите ввод." << std::endl;
                            continue;   
                        }
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

    int **read_matrix_from_file(int &n)
    {
        std::ifstream file("input.txt");
        if (!file)
        {
            throw std::runtime_error("Не удалось открыть файл. Создайте файл и перезапустите программу.");
        }

        file >> n;
        if (n <= 0)
        {
            throw std::runtime_error("Некорректный формат данных в файле. Исправьте содержимое файла и перезапустите программу.");
        }

        int **matrix = new int*[n]; 
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                try
                {
                    file >> matrix[i][j];
                }
                catch(const std::exception& e)
                {
                    throw std::runtime_error("Некорректное содержание файла. Проверьте файл и перезапустите программу");
                }
            }
        }

        return matrix;
    }

    void write_results_to_console(int **arr, int *resultA, int *resultB, int *resultC, int *resultD, int &n)
    {
        using namespace std;

        cout << "Исходная матрица:" << endl << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;

        cout << "А) ";
        for (int i = 0; i < n; i++)
            cout << resultA[i] << " ";
        cout << endl;
        cout << "Б) ";
        for (int i = 0; i < n; i++)
            cout << resultB[i] << " ";
        cout << endl;
        cout << "В) ";
        for (int i = 0; i < n; i++)
            cout << resultC[i] << " ";
        cout << endl;
        cout << "Г) ";
        for (int i = 0; i < n; i++)
            cout << resultD[i] << " ";
        cout << endl;
    }

    void wirte_results_to_file(int **arr, int *resultA, int *resultB, int *resultC, int *resultD, int &n)
    {
        using namespace std;

        ofstream output("output.txt");

        output << "Исходная матрица:" << endl << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                output << arr[i][j] << " ";
            }
            output << endl;
        }
        output << endl;

        output << "А) ";
        for (int i = 0; i < n; i++)
            output << resultA[i] << " ";
        output << endl;
        output << "Б) ";
        for (int i = 0; i < n; i++)
            output << resultB[i] << " ";
        output << endl;
        output << "В) ";
        for (int i = 0; i < n; i++)
            output << resultC[i] << " ";
        output << endl;
        output << "Г) ";
        for (int i = 0; i < n; i++)
            output << resultD[i] << " ";
        output << endl;

        output.close();
    }
}