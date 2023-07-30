#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{

    int temp[high - low + 1];

    int i;

    int left = low;
    int right = high;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[i] = arr[left];
            left++;
        }
        else
        {
            temp[i] = arr[right];
            right++;
        }
    }
    i++;

    while (left <= mid)
    {
        temp[i] = arr[left];
        left++;
        i++;
    }

    while (right <= high)
    {
        temp[i] = arr[right];
        right++;
        i++;
    }

    for (int x = low, j = 0; x <= high; x++, j++)
    {
        arr[x] = temp[j];
    }
}

void ms(int arr[], int high, int low)
{
    if (low>=high){
        return;
    }
    int mid = (high + low) / 2;

    ms(arr, mid, low);
    ms(arr, high, low + 1);

    merge(arr, low, mid, high);
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

    ms(arr, 0, n - 1);

    cout << endl
         << "After Using quick sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}