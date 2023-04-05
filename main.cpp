#include "io_functions.cpp"
#include "my_functions.cpp"

int main()
{
    while (true)
    {
        using namespace std;

        int n;

        int **arr;

        bool isreloadable = true;

        string * input_method = new string;

        bool correct_input = false;
        while (!correct_input)
        {
            cout << "Какой метод ввода вы предпочитаете? [файл/консоль]: ";
            getline(cin, *input_method);
            if (*input_method == "файл" || *input_method == "Файл")
            {
                correct_input = true;
                arr = iof::read_matrix_from_file(n);
                isreloadable = false;
            }
            else if (*input_method == "консоль" || *input_method == "Консоль")
            {
                correct_input = true;    
                arr = iof::read_matrix_from_console(n);
            }
            else
                cout << "Обеспечьте корректный ввод." << endl;
        }

        delete input_method;
        int *resultA = myf::compute_min_elements(arr, n);
        int *resultB = myf::find_first_positive(arr, n);
        int *resultC = myf::find_sum_after_negative(arr, n);
        int *resultD = myf::find_sum_before_negative(arr, n);

        string *output_method = new string;

        correct_input = false;
        while (!correct_input)
        {
            cout << "Какой метод вывода вы предпочитаете? [файл/консоль]: ";
            getline(cin, *output_method);

            if (*output_method == "файл" || *output_method == "Файл")
            {
                iof::wirte_results_to_file(arr, resultA, resultB, resultC, resultD, n);
                correct_input = true;
            }
            else if (*output_method == "консоль" || *output_method == "Консоль")
            {
                correct_input = true;
                iof::write_results_to_console(arr, resultA, resultB, resultC, resultD, n);
            }
            else
                cout << "Обеспечьте корректный ввод." << endl;
        }

        delete output_method;

        if (isreloadable)
        {
            bool correct_ans = false;
            while (!correct_ans)
            {
                cout << "Желаете повторить процесс? [Да/Нет]: ";
                string *answer = new string;
                getline(cin, *answer);
                if (*answer == "Да" || *answer == "да")
                {
                    correct_ans = true;
                    continue;
                }
                else if (*answer == "Нет" || *answer == "нет")
                {
                    correct_ans = true;
                    for(int i = 0; i < n; i++)
                    {
                        delete[] arr[i];
                    }
                    delete[] arr;
                    return 0;
                }
                else
                    cout << "Некорректный ответ на вопрос." << endl;
            }
        }else {
            return 0;
        }
    }
}
