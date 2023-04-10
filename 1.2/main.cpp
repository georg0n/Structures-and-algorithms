#include <iostream>
#include <ctime>
#include <chrono>


void FirstTask();
//void SecondTask();
//void ThirdTask();

void BubbleSort(int *num, int size);

using namespace std;

int main()
{
    int a;
    cout << "Print number of task(1-3): " << endl;

    cin >> a;
    switch (a) {
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
            cout << "Error" << endl;
            return 0;

    }
}

void FirstTask()
{

    int n; // count of elements

    cout << "Insert count of arr elements: " << endl;
    cin >> n;
    int* arr = new int[n];

    srand(time(NULL)); // randomize
    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }

    cout << "Before sort \n -----------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "a [" << i << "] = " << arr[i] << endl;
    }
    cout << "After sort \n ------------------------------" << endl;
    auto start = chrono::steady_clock::now();
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "a [" << i << "] = " << arr[i] << endl;
    }
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end-start).count();


}

void BubbleSort(int *num, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) //for all elements after i
        {
            if (num[j - 1] > num[j]) //if element < previous
            {
                int temp = num[j - 1]; // swapping places
                num[j - 1] = num[j];
                num[j] = temp;

            }
        }
    }
}

