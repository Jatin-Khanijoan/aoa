#include <stdio.h>
#include <limits.h>
int partition(int arr[], int str, int end)
{
    int val = arr[str];
    int ind = str;
    for (int i = str + 1; i <= end; i++)
    {
        if (arr[i] < val)
        {
            ++ind;
            int temp = arr[ind];
            arr[ind] = arr[i];
            arr[i] = temp;
        }
    }
    arr[str] = arr[ind];
    arr[ind] = val;
    return ind;
}
void quicksort(int arr[], int str, int end)
{
    if (str >= end)
        return;
    int p = partition(arr, str, end);
    quicksort(arr, str, p - 1);
    quicksort(arr, p + 1, end);
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
    quicksort(arr, 0, size - 1);
    printf("Sorted array - ");
    print(arr, size);
    return 0;
}

// Enter size of array
// 5
// Enter Element of array
// 10
// 30
// 25
// 11
// 2
// Sorted array - 2 10 11 25 30