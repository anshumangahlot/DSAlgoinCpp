#include <stdio.h>
int k = 1;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i + 1], &nums[high]);
    return i + 1;
}

void quickSort(int nums[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(nums, low, high);

        printf("\nPass %d (Pivot-> %d) : ", k++,nums[pi]);
        for (int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }

        quickSort(nums, low, pi - 1, n);
        quickSort(nums, pi + 1, high, n);
    }
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1, n);

    printf("\n\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
