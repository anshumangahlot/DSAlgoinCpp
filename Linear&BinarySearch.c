//
// Created by ANSHUMAN GAHLOT on 09/07/25.
//
#include <stdio.h>

void linearsearch(int nums[], int nums_size, int target) {
    int flag = 0;
    for (int i = 0; i < nums_size; i++) {
        if (nums[i] == target) {
            flag = 1;
            printf("Element was found at position %d\n", i);
        }
    }
    if (flag == 0)
        printf("Sorry, Element was not found\n");
}

int binarysearchiterative(int nums[], int nums_size, int target) {
    int left = 0;
    int right = nums_size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int binarysearchrecursive(int nums[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return binarysearchrecursive(nums, left, mid - 1, target);
        } else {
            return binarysearchrecursive(nums, mid + 1, right, target);
        }
    }
    return -1;
}

int main() {
    int nums_size;
    printf("Input Array size: ");
    scanf("%d", &nums_size);

    int nums[100];  

    printf("Input array elements:\n");
    for (int i = 0; i < nums_size; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Input target element: ");
    scanf("%d", &target);

    int choice;
    printf("Select searching method:\n 1.Linear Search \n 2.Binary search (iterative) \n 3.Binary search (recursive)\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            linearsearch(nums, nums_size, target);
            break;

        case 2: {
            int pos = binarysearchiterative(nums, nums_size, target);
            if (pos != -1) {
                printf("Element found at index %d\n", pos);
            } else {
                printf("Element not found.\n");
            }
            break;
        }

        case 3: {
            int left = 0;
            int right = nums_size - 1;
            int flag = binarysearchrecursive(nums, left, right, target);
            if (flag != -1) {
                printf("Element found at index %d\n", flag);
            } else {
                printf("Element not found.\n");
            }
            break;
        }

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
