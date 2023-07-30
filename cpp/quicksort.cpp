#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int high, int low)
{

    int pivot = low;
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= arr[pivot] && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > arr[pivot] && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int PI = partition(arr, high, low);

        qs(arr, low, PI - 1);
        qs(arr, PI + 1, high);
    }
}

void quickSort(int arr[], int n)
{
    qs(arr, 0, n - 1);
}

int main()
{

    int arr[50];

    int n;
    cout << "eneter the numebr of elemtents in the array : ";
    cin >> n;

    cout << "enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "the array before sorting is : ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }

    quickSort(arr, n);

    cout << endl
         << "After Using quick sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}