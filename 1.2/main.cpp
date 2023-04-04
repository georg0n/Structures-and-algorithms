#include <iostream>
#include <chrono>
//#include <iomanip>


using namespace std;

void TaskSwitcher();
void Chrono();
void FirstTask();
void SimpleTradeSort();
void InsertionSort();
void ShiftRight();
void PrintArray();




int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Практическая работа 1.2" << endl;
    //TaskSwitcher();
    cout << "Выберите задание:\n 1 - Задание 1\n 2 - Задание 2\n 3 - Задание 3" << endl;



}

void PrintArray(unique_ptr<int[]> &arr, int N, const string& name = "")
{
    cout << "Вывод массива (начало) " << name << endl;
    for (int i(0); i < N; i++)
    {
        cout << endl;
        cout << "Вывод массива (конец)" << name << endl;
    }
}

void ShiftRight(int *a, int startKey, int s, int size, unsigned long long int &Mf)
{
    for (int i = size-1; i-s >= startKey; i--)
    {
        a[i] = a[i-s];
        Mf++;
    }
    for (int i = (startKey + s) - 1; i >= startKey; i--)
    {
        a[i] = 0;
    }
}


//void TaskSwitcher() {

//    int a;
//    cout << "Введите номер задания" << endl;
//    cin >> a;
//    switch (a) {
//        case 1:
//
//
//    }
//
//}

//void FirstTask() {
//
//}



void Chrono() {
    auto begin = chrono::steady_clock::now();
    getchar();
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast <chrono::milliseconds>(end - begin);
    cout << "The time: " << elapsed_ms.count() << endl;
}




void InsertionSort(unique_ptr<int[]> &arr, int size) {
    unsigned long long int Cf = 0;
    unsigned long long int Mf = 0;

    int *result = new int [size];
    for (int i(0); i < size; i++) {
        result[i] = INT32_MAX;
        }

    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < size; i++){
        int j = i;
        for (; result[j] > arr[i] && j >= 0; j--){
            Cf++;
        }
        Cf++;

        ShiftRight(result, j + 1, 1, size, Mf);
        result[j + 1] = arr[i];
    }

    arr.reset(result);

    unsigned long long int Tp = Cf + Mf;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast < chrono::milliseconds>(end - begin);
    cout << "Количество операций сравнения Cf = " << Cf << endl;
    cout << "Фактическое количество операций перемещения Mf = " << endl;
    cout << "Тп(n) = Сф + Мф: " << Tp << endl;
    cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
    }




void SimpleTradeSort(unique_ptr<int[]>&arr, int size){
    unsigned long long int Cf = 0;
    unsigned long long int Mf = 0;

    auto begin = chrono::steady_clock::now();


    for (int i = size-1; i > 0; i--){
        Cf++;

        for (int j = 0; j < i; j++){
            Cf++;

            Cf++;
            if(arr[j] > arr[j + 1]){
                Mf += 3;
                std::swap(arr[j], arr[j + 1]);

            }
        }
        Cf++;
    }
    Cf++;
    unsigned long long int Tp = Cf + Mf;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast< chrono::milliseconds>(end - begin);
    cout << "Количество операций  сравнения Cf = " << Cf << endl;
    cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;

}

void SelectSort(unique_ptr<int[]> &arr, int size)
{
    unsigned long long int Cf = 0;
    unsigned long long int Mf = 0;

    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < size - 1; i++)
    {
        int minKey = i;
        for (int j = i + 1; j < size; j++)
        {
            Cf++;
            if (arr[j]  ,arr[minKey])
            {
                minKey = j;
            }
        }
        if (minKey != i)
        {
            Mf++;
            std::swap(arr[i], arr[minKey]);
        }
    }
    unsigned long long int Tp = Cf + Mf;
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast< chrono::milliseconds>(end - begin);
    cout << "Количество операций  сравнения Cf = " << Cf << endl;
    cout << "Фактическое количество операций перемещения Mf = " << Mf << endl;
    cout << "Тп(n)=Cф+Mф: " << Tp << endl;
    cout << "Время выполнения T(n) = " << elapsed_ms.count() << endl;
}







