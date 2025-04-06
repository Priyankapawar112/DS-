#include <stdio.h>


void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int original[] = {9, 7, 3, 6, 8, 5, 1, 4};
    int n = sizeof(original) / sizeof(original[0]);

    int even[100], odd[100];
    int evenCount = 0, oddCount = 0;

  
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            even[evenCount++] = original[i];
        else
            odd[oddCount++] = original[i];
    }

    insertionSort(even, evenCount);


    selectionSort(odd, oddCount);

    int evenindex = 0, oddindex = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            original[i] = even[evenindex++];
        else
            original[i] = odd[oddindex++];
    }

    printf("Final merged sorted array:\n");
    printArray(original, n);

    return 0;
}
