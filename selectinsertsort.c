#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            swap(&arr[min], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[100];
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array after sorting: \n");
    printArray(arr, n);

    return 0;
}

/*

#include<stdio.h>

void insertion(int a[], int n){
    int i, temp, j;

    for(i=1; i<n; i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;


    }
}


void print(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void main(){
    int n;
    int a[100];
    printf("Enter the no. of Elements: ");
    scanf("%d",&n);

    printf("Enter %d Elements: ",n);
    for(int i=0; i<n; i++){
    scanf("%d",&a[i]);
    }
    printf("Unsorted Array:");
    print(a,n);

    insertion(a,n);

    printf("Sorted Array:");
    print(a,n);


}


*/