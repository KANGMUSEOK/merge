#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // �ӽ� �迭 ���� �Ҵ�
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // �ӽ� �迭�� ������ ����
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // �ӽ� �迭 �պ�
    i = 0;   // ���� �迭 �ε���
    j = 0;   // ������ �迭 �ε���
    k = left;   // ���յ� �迭 �ε���

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

    // ���� �迭�� ���� ��ҵ� ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ������ �迭�� ���� ��ҵ� ����
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // ���� �Ҵ�� �޸� ����
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // ���� �κ� �迭 ����
        mergeSort(arr, left, middle);

        // ������ �κ� �迭 ����
        mergeSort(arr, middle + 1, right);

        // ���ĵ� �� �迭 ����
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
