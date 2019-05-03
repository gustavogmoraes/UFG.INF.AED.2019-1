#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &array)
{
    int i, j, key;

    for(i = 1; i < array.size(); i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array [j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

void PrintVector(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
}

bool IsPrime(int number)
{
    if(number == 1) return false;
    if(number == 2) return true;

    for(int i = 2; i < number + 1; i++)
    {
        if(i == number) continue;

        if(number % i == 0) return false;
    }

    return true;
}

int GetNextPrimeNumber(int number)
{
    number = number + 1;

    while(!IsPrime(number))
        number = GetNextPrimeNumber(number);

    return number;
}

int GetPrimeNumberInOrder(int order)
{
    if(order == 1) return 2;
    int contagem = 1;
    int number = 2;

    while(contagem < order)
    {
        number = GetNextPrimeNumber(number);
        contagem++;
    }

    return number;
}

bool IsIn(int number, vector<int> array)
{
    for(int i = 0; array.size(); i++)
    {
        if(array[i] == number) return true;
    }

    return false;
}

int main()
{
    int maxNumberQuantity, order;
    cin >> maxNumberQuantity;

    vector<int> primeNumbers;
    for(int i = 0; i < maxNumberQuantity; i++)
    {
        cin >> order;
        primeNumbers.push_back(GetPrimeNumberInOrder(order));
    }

    InsertionSort(primeNumbers);
    PrintVector(primeNumbers);
}