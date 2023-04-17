#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void FirstTask();
//void SecondTask();
//void ThirdTask();
void BubbleSortIverson(int *num, int size);
void PrintArray(int *arr, int size);
void BubbleSort(int *num, int size);

int main()
{
    int changeTask;
    cout << "Enter task number: " << std::endl;
    cin >> changeTask;
    switch (changeTask) {
        case 1:
            FirstTask();
            break;
        case 2:
            //SecondTask();
            break;
        case 3:
            //ThirdTask();
            break;
        default:
            cout << "Error!" << std::endl;
            return 0;
    }
}

void FirstTask()
{
    int n;

    cout << "Enter count of arr elements: " <<std::endl;
    cin >> n;

    int* arr = new int[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }

    auto start = chrono::steady_clock::now();
    BubbleSortIverson(arr, n);
    //BubbleSort(arr, n);
    auto end = chrono::steady_clock::now();
    PrintArray(arr, n);
    cout << "Elapsed time in milliseconds: " << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count();

}

void BubbleSortIverson(int *num, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        bool flag = true;

        for (int j = 0; j < size - (i + 1); j++)
        {
            if (num[j] > num[j + 1])
            {
                flag = false;
                swap(num[j], num[j + 1]);
            }
        }
        if (flag)
        {
            break;
        }
    }
}


void BubbleSort(int *num, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                int b = num[j];
                num[j] = num[j + 1];
                num[j + 1] = b;
            }
        }
    }
}



void PrintArray(int *arr, int size)
{
    cout << "Array output------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << "a [" << i << "] = " << arr[i] << std::endl;
    }
    cout << "End of output-----------------------------\n";
}