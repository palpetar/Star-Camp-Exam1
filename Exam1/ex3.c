#include <stdio.h>

void subseq(int arr[], int n, int dest[], int *new_n);


int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    }
    int dest[n];
    int new_n = 0;
    subseq(arr, n, dest, &new_n);
    printf("%d\n", new_n);
    for (int i = 0; i < new_n; i++) {
        printf("%d ", dest[i]);
    }
    return 0; 
}

void subseq(int arr[], int n, int dest[], int *new_n) {
    int counter = 1; 
    int startindex = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1] + 1) {
            counter++;
        } else {
            if (*new_n < counter) {
                *new_n = counter;
                startindex = i - *new_n + 1; 
                counter = 1; 
            }
        }
    }
    if (*new_n < counter) {
        *new_n = counter;
        startindex = n - counter; 
    }
    for (int i = 0; i < *new_n; i++) {
        dest[i] = arr[startindex + i];
    }
}