#include "io_functions.cpp"
#include "my_functions.cpp"

int main()
{
    while (true)
    {
        using namespace std;

        int *n;
        
        int** arr;

        bool isreloadable = true;

        string *input_method = new string;

        cout << "Какой метод ввода вы предпочитаете? [файл/консоль]: ";
        getline(cin, *input_method);
        if (*input_method == "файл" || *input_method == "Файл")
        {
            iof::read_matrix_from_file(arr, n);
            isreloadable = false;
        }
        else if (*input_method == "консоль" || *input_method == "Консоль")
            iof::read_matrix_from_console(arr, n);

        delete input_method;

        int *resultA = myf::compute_min_elements(arr, *n);
        int *resultB = myf::find_first_positive(arr, *n);
        int *resultC = myf::find_sum_after_negative(arr, *n);
        int *resultD = myf::find_sum_before_negative(arr, *n);

        cout << "Какой метод вывода вы предпочитаете? [файл/консоль]: ";

        string *output_method = new string;

        getline(cin, *output_method);

        if (*input_method == "файл" || *input_method == "Файл")
            iof::wirte_results_to_file(resultA, resultB, resultC, resultD, n);
        else if (*input_method == "консоль" || *input_method == "Консоль")
            iof::write_results_to_console(resultA, resultB, resultC, resultD, n);

        delete output_method;

        if (isreloadable)
        {
            cout << "Желаете повторить процесс? [Да/Нет]: ";
            string *answer = new string;
            getline(cin, *answer);
            bool correct_ans = false;
            while (!correct_ans)
            {
                if (*answer == "Да" || *answer == "да")
                {
                    correct_ans = true;
                    continue;
                }
                else if (*answer == "Нет" || *answer == "нет")
                {
                    for(int i = 0; i < *n; i++)
                    {
                        delete[] arr;
                    }
                    delete[] arr;
                    delete n;
                    delete resultA;
                    delete resultB;
                    delete resultC;
                    delete resultD;
                    delete answer;
                    correct_ans = true;
                    return 0;
                }
                else
                    cout << "Некорректный ответ на вопрос." << endl;
            }
        }
    }
}
