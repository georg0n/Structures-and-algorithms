#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void FirstTask();
//void SecondTask();
//void ThirdTask();
void BubbleSortIverson(int *num, int size);
void PrintArray(int *arr, int size);

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
    auto end = chrono::steady_clock::now();
    PrintArray(arr, n);
    cout << "Elapsed time in milliseconds: " << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count();

}

void BubbleSortIverson(int *num, int size)
{
    //int k = 0;
    for (int i = 0; i < size - 1; i++)
    {
        //k = 0;
        for (int j = (size - 1); j > i; j--)
        {
            if (num[j - 1] > num[j])
            {
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
                //k = 1;
            }
            //if (k==0) return 0;
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