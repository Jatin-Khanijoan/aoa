#include <stdio.h>
#include <limits.h>
void merge(int arr[], int str, int mid, int end)
{
    int s1 = mid - str + 1;
    int s2 = end - mid;
    int left[s1 + 1];
    int right[s2 + 1];
    left[s1] = INT_MAX;
    right[s2] = INT_MAX;
    for (int i = str; i <= mid; i++)
    {
        left[i - str] = arr[i];
    }
    for (int i = mid + 1; i <= end; i++)
    {
        right[i - (mid + 1)] = arr[i];
    }
    for (int i = str, j = 0, p = 0; i <= end; i++)
    {
        if (left[j] > right[p])
        {
            arr[i] = right[p++];
        }
        else
        {
            arr[i] = left[j++];
        }
    }
}
void mergeSort(int arr[], int str, int end)
{
    if (str >= end)
        return;
    int mid = (end - str) / 2 + str;
    mergeSort(arr, str, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, str, mid, end);
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void get(int arr[], int size)
{
    printf("Enter Element of array\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}
int main()
{
    printf("Enter size of array\n");
    int size;
    scanf("%d", &size);
    int arr[size];
    get(arr, size);
    mergeSort(arr, 0, size - 1);
    printf("Sorted array - ");
    print(arr, size);
    return 0;
}


// Enter size of array
// 5
// Enter Element of array
// 200
// 20
// 3
// 32
// 99
// Sorted array - 3 20 32 99 200 