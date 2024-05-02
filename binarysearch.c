#include <stdio.h>

int Binary(int a[], int l, int r, int k) {
    int mid = (l + r) / 2;
    if (l <= r) {
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            return Binary(a, mid + 1, r, k);
        else
            return Binary(a, l, mid - 1, k);
    }
    return -1;
}

void main() {
    int n, i, k;
    
    printf("Enter the no. of Elements into the array: ");
    scanf("%d", &n);
    
    int a[n]; // Declare array after reading the size
    
    printf("Enter %d Elements in Sorted manner: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the key to search: ");
    scanf("%d", &k);
    
    int result = Binary(a, 0, n - 1, k);
    
    if (result == -1)
        printf("Element not found in array");
    else
        printf("Element Found at %d index", result);
}


// Enter the no. of Elements into the array: 7
// Enter 7 Elements in Sorted manner: 10 20 30 40 50 60 70
// Enter the key to search: 40
// Element Found at 3 index