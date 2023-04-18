#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void BubbleIversonTask(int n);
void BubbleTask(int n);
void MergeSortTask(int n);


void PrintArray(int *arr, int size);
void ReversedBubble(int *num, int size);


void mergesort(int arr[], int aux[], int low, int high);
void Merge(int arr[], int aux[], int low, int mid, int high);
void BubbleSort(int *num, int size);
void BubbleSortIverson(int *num, int size);




int main()
{
    int changeTask;
    int count;
    cout << "Insert count of arr elements: " << endl;
    cin >> count;
    cout << "Enter type sort:\n1 - BubbleIverson\n2 - Bubble\n3 - MergeSort" << std::endl;
    cin >> changeTask;
    switch (changeTask) {
        case 1:
            BubbleIversonTask(count);
            break;
        case 2:
            BubbleTask(count);
            break;
        case 3:
            MergeSortTask(count);
            break;
        default:
            cout << "Error!" << std::endl;
            return 0;
    }
}

void BubbleIversonTask(int n)
{
    int* arr = new int[n];

    int change;

    srand(time(NULL));


    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }

    cout << "1 - Reverse mass\n2 - Sort mass\n0 - Do nothing with mass" << endl;
    cin >> change;
    switch (change) {
        case 1:
            ReversedBubble(arr, n);
            break;
        case 2:
            BubbleSort(arr, n);
            break;
        case 0:
            break;

    }


    //ReversedBubble(arr, n);

    auto start = chrono::steady_clock::now();
    BubbleSortIverson(arr, n);
    auto end = chrono::steady_clock::now();
    PrintArray(arr, n);
    cout << "Elapsed time in milliseconds: " << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count();

}


void BubbleTask(int n)
{

    int* arr = new int[n];

    int change;

    srand(time(NULL));


    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
    }

    cout << "1 - Reverse mass\n2 - Sort mass\n0 - Do nothing with mass" << endl;
    cin >> change;
    switch (change) {
        case 1:
            ReversedBubble(arr, n);
            break;
        case 2:
            BubbleSort(arr, n);
            break;
        case 0:
            break;

    }


    //ReversedBubble(arr, n);

    auto start = chrono::steady_clock::now();
    BubbleSort(arr, n);
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

void MergeSortTask(int n)
{
    int* arr = new int[n];
    int* aux = new int[n];

    int change;

    srand(time(NULL));


    for (int i = 0; i < n; i++)
    {
        int num = rand() % n + 1;
        arr[i] = num;
        aux[i] = num;
    }

    cout << "1 - Reverse mass\n2 - Sort mass\n0 - Do nothing with mass" << endl;
    cin >> change;
    switch (change) {
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
    mergesort(arr, aux, 0, n - 1);
    auto end = chrono::steady_clock::now();
    PrintArray(arr, n);
    cout << "Elapsed time in milliseconds: " << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count();

}



void mergesort(int arr[], int aux[], int low, int high)
{
    if (high == low)
    {
        return;
    }

    int mid = (low + ((high - low) >> 1));

    mergesort(arr, aux, low, mid); //left
    mergesort(arr, aux, mid + 1, high); //right

    Merge(arr, aux, low, mid, high);

}

void Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        aux[k++] = arr[i++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = aux[i];
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