#include <iostream>
#include <ctime>
#include <chrono>

//void Test();

void FirstTask();
void SecondTask();
void ThirdTask();

void PrintArray(int *arr, int size);

void BubbleSort(int *num, int size);

void InsertionSort(int *num, int size);

void Reverse(int *num, int size);


void ReversedBubble(int *num, int size);



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
            SecondTask();
            break;
        case 3:
            ThirdTask();
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
        auto start = chrono::steady_clock::now();
        BubbleSort(arr, n);
        auto end = chrono::steady_clock::now();


    PrintArray(arr, n);
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

void PrintArray(int *arr, int size)
{
        cout << "Array output--------------------------------- \n";
        for (int i = 0; i < size; i++)
    {
        cout << "a [" << i << "] = " << arr[i] << endl;
    }
        cout << "End of output-----------------------------\n";

}

void SecondTask()
{
    int n;
    int sort;
    int choice;

    cout << "Insert count of elements: " << endl;
    cin >> n;
    int* arr = new int[n];


    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }


    BubbleSort(arr, n);
    //ReversedBubble(arr, n);


    auto start= chrono::steady_clock::now();
    BubbleSort(arr, n);
    auto end = chrono::steady_clock::now();

    PrintArray(arr, n);
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end-start).count();


}

void ThirdTask()
{
    int n;
    cout << "Insert count of elements: " << endl;
    cin >> n;
    int* arr = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }


    auto start = chrono::steady_clock::now();
    InsertionSort(arr, n);
    auto end = chrono::steady_clock::now();

    PrintArray(arr, n);


    cout << "Elapsed time in milliseconds: "<< chrono::duration_cast<chrono::milliseconds>(end-start).count();


}

void InsertionSort(int *num, int size)
{
    int key, i, k, j;

    for (i = 1; i < size; i++)
    {
        key = num[i];
        j = i - 1;

        while (j >= 0 && num[j] > key)
        {

            num[j + 1] = num[j];
            j = j - 1;
        }

        num[j + 1] = key;
    }


}

void Reverse(int *num, int size)
{
    int i, b;

    for (i = 0; i < size/2; i++)
    {
        b = num[i];
        num[i] = num[size-i-1];
        num[size-i-1] = b;
    }
}

void ReversedBubble(int *num, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) //for all elements after i
        {
            if (num[j - 1] < num[j]) //if element < previous
            {
                int temp = num[j - 1]; // swapping places
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}





