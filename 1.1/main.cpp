#include <iostream>
#include <ctime>
using namespace std;


void MainTask();
int IndividTask();


//void Multiply(int A,int  B,int  C,int  n);

void delFirstMetod(int* x, int n, int key);
void delOtherMetod(int* x, int n, int key);
void print_arr(int* mass, int len, string name);
void copy(int* tocopy, int copy_len, int final_len);




int main()
{
    setlocale(LC_ALL, "Russian");
    int changeTask;
    std::cout<<"Change Task (1-2): "<< std::endl;
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
    cout << "Insert count of arr elements" << endl;
    cin >> mass;
    int* arr1 = new int[mass];
    int* arr2 = new int[mass];
    int sw;
    cout << "Change operation mode:\n 1 - Randomize values \n 2 - Manual input" << endl;
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
    cout << "Enter the number to delete: " << endl;
    cin >> buff;

    print_arr(arr1, mass, "The original array \n");
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
    cout << "Spent permutations on the first method: " << permutation << "| Comparisons have been made: " << comparison << endl;
    int t2 = clock();
    int final_time = t2 - t1;
    cout << "Time to execute the first method (milliseconds): " << final_time << endl << "\n";
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
    cout << "Spent permutations on the second method: " << permutation << "| Comparisons have been made: " << comparison << endl;
    int t2 = clock();
    int final_time = t2 - t1;
    cout << "Time to execute the second method (milliseconds): " << final_time << endl << "\n";
}

void print_arr(int* mass, int len, string name)
{
    cout << "Array output (beginning) " << name << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "mass[" << i << "]=" << mass[i] << endl;

    }
    cout << "Array output (end)" << name << " " << endl;
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

int IndividTask() {

   int const N = 3;
    double A[N][N], B[N][N], C[N][N];
    int i, j, k;




    cout << "-------------------------------------------------------------" << endl;
    cout << "Matrix A" << endl;
    for (i = 0; i < N; i++)
     {
        for (j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "-------------------------------------------------------------" << endl;

    cout << "Matrix B" << endl;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> B[i][j];
        }
    }

    cout << "---------------------------------------------------------------" << endl;

    cout << "Matrix C = A * B" << endl;

    for (i = 0; i < N; i++) {

        for (j = 0; j < N; j++) {

            C[i][j] = 0;
            for (k = 0; k < N; k++)

                C[i][j] += A[i][k] * B[k][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
   }












