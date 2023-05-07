#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // 임시 배열 동적 할당
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 임시 배열에 데이터 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // 임시 배열 합병
    i = 0;   // 왼쪽 배열 인덱스
    j = 0;   // 오른쪽 배열 인덱스
    k = left;   // 병합된 배열 인덱스

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 왼쪽 배열에 남은 요소들 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 오른쪽 배열에 남은 요소들 복사
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 동적 할당된 메모리 해제
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // 왼쪽 부분 배열 정렬
        mergeSort(arr, left, middle);

        // 오른쪽 부분 배열 정렬
        mergeSort(arr, middle + 1, right);

        // 정렬된 두 배열 병합
        merge(arr, left, middle, right);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
