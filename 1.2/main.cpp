#include <iostream>
#include <ctime>
#include <chrono>

//void Test();




void PrintArray(int *arr, int size);


void BubbleSortTask(int n);
void BubbleSort(int *num, int size);

void InsertionSortTask(int n);
void InsertionSort(int *num, int size);




void ReversedBubble(int *num, int size);



using namespace std;

int main()
{
    int n;
    cout << "Insert count of elements: " << endl;
    cin >> n;


    int a;
    cout << "Change sort:\n1 - BubbleSort\n2 - InsertionSort" << endl;

    cin >> a;
    switch (a) {
        case 1:
            BubbleSortTask(n);
            break;
        case 2:
            InsertionSortTask(n);
            break;
        default:
            cout << "Error" << endl;
            return 0;

    }
}





void BubbleSortTask(int n)
{

    int* arr = new int[n];
    int changeMode;



    srand(time(NULL)); // randomize
    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }

    cout << "Change mode:\n1 - Reverse arr;\n2 - Sort arr;\n0 - Do nothing" << endl;
    cin >> changeMode;
    switch (changeMode) {
        case 1:
            ReversedBubble(arr, n);
            break;
        case 2:
            BubbleSort(arr, n);
            break;
        case 0:
            break;
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



void InsertionSortTask(int n)
{

    int changeMode;
    int* arr = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }

    cout << "Change mode:\n1 - Reverse arr;\n2 - Sort arr;\n0 - Do nothing" << endl;
    cin >> changeMode;
    switch (changeMode) {
        case 1:
            ReversedBubble(arr, n);
            break;
        case 2:
            BubbleSort(arr, n);
            break;
        case 0:
            break;
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





