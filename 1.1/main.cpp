#include <iostream>
#include <ctime>
using namespace std;


void MainTask();
void IndividTask();
void delFirstMetod(int* x, int n, int key);
void delOtherMetod(int* x, int n, int key);
void print_arr(int* mass, int len, string name);
void copy(int* tocopy, int copy_len, int final_len);


int main()
{
    setlocale(LC_ALL, "Russian");
    int changeTask;
    std::cout<<"Введите номер задания (1-2): "<< std::endl;
    std::cin>>changeTask;
    switch (changeTask) {
        case 1:
            MainTask();
            break;
        case 2:
            IndividTask();
            break;
    }
}

void MainTask()
{
    int mass;
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество элементов массива" << endl;
    cin >> mass;
    int* arr1 = new int[mass];
    int* arr2 = new int[mass];
    int sw;
    cout << "Введите режим работы программы:\n 1 - заполнение массива случайными значениями \n 2 - ручной ввод" << endl;
    cin >> sw;
    switch (sw) {
    case 1:
        srand(time(NULL)); // заполненение массива случайными значениями
        for (int i = 0; i < mass; i++) {
            int num = rand() % 20 + 1;
            arr1[i] = num;
            arr2[i] = num;
        }
        break;
    case 2:
        for (int i = 0; i < mass; i++) { // заполнение массива вручную
            int input;
            cout << "arr[" << i << "] = ";
            cin >> input;
            arr1[i] = input;
            arr2[i] = input;
        }
        break;
    }
    int buff;
    cout << "Введите число для удаления: " << endl;
    cin >> buff;

    print_arr(arr1, mass, "Изначальный массив \n");
    delFirstMetod(arr1, mass, buff);
    delOtherMetod(arr2, mass, buff);
    system("pause");

}

void delFirstMetod(int* x, int n, int key)
{
    int t1 = clock();
    int comparison = 0;
    int permutation = 0;
    int c_len = n;
    int i = 0;
    while (i <= n)
    {
        comparison += 1;
        if (x[i] == key)
        {
            //удаление
            for (int j = i; j <= n - 1; j++)
            {
                x[j] = x[j + 1];
                permutation++;
            }
            n--;
        }
        else
        {
            i++;
        }
    }
    copy(x, c_len, n);
    cout << "Затрачено перестановок на первый метод: " << permutation << " Проведено сравнений: " << comparison << endl;
    int t2 = clock();
    int final_time = t2 - t1;
    cout << "Время на выполнение первого метода (миллисекунды): " << final_time << endl << "\n";
}

void delOtherMetod(int* x, int n, int key)
{
    int t1 = clock();
    int comparison = 0;
    int permutation = 0;
    int c_len = n;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        x[j] = x[i];
        permutation++;
        comparison++;
        if (x[i] != key)
        {
            i++;
        }
    }
    n = j;
    copy(x, c_len, n);
    cout << "Затрачено перестановок на второй метод: " << permutation << " Проведено сравнений: " << comparison << endl;
    int t2 = clock();
    int final_time = t2 - t1;
    cout << "Время на выполнение второго метода (миллисекунды): " << final_time << endl << "\n";
}

void print_arr(int* mass, int len, string name)
{
    cout << "Вывод массива (начало) " << name << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "mass[" << i << "]=" << mass[i] << endl;

    }
    cout << "Вывод массива (конец)" << name << " " << endl;
}

void copy(int* tocopy, int copy_len, int final_len)
{
    int* temparr = new int[copy_len]; // массив куда мы копируем данные
    for (int i = 0; i < copy_len; i++)
    {
        temparr[i] = tocopy[i];
    }
    int* copy = new int[final_len];
    for (int i = 0; i < final_len; i++)
    {
        copy[i] = temparr[i];
    }
    delete[]temparr;
    print_arr(copy, final_len, "");
}



//Задание 2

void IndividTask() {
    setlocale(LC_ALL, "rus");
    const int n = 3;
    int i, j, k;
    double a[n][n];
    double b[n][n];
    double c[n][n];

    cout << "матрица а" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }

    }

    cout << "матрица b" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> b[i][j];
        }

    }

    cout << "матрица c = a*b" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                cout << c[i][j] << " ";
            }
            cout << endl;
        }



    }
}