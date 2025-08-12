#include <stdio.h>
int k = 1;

void merge(int nums[], int low, int mid, int high) {
  int n1 = high - low + 1;
  int arr[n1];

  int i = low, j = mid + 1, k = 0;

  while (i <= mid && j <= high) {
    if (nums[i] < nums[j]) {
      arr[k++] = nums[i++];
    } else {
      arr[k++] = nums[j++];
    }
  }

  while (i <= mid) {
    arr[k++] = nums[i++];
  }

  while (j <= high) {
    arr[k++] = nums[j++];
  }

  for (int m = 0; m < n1; m++) {
    nums[low + m] = arr[m];
  }
}

void mergeSort(int nums[], int low, int high,int n) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergeSort(nums, low, mid,n);
    mergeSort(nums, mid + 1, high,n);
    merge(nums, low, mid, high);
    printf("\nPass %d: ",k++);
    for (int i = 0; i < n; i++) {
      printf("%d ", nums[i]);
    }
  }
}

int main(){
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter elements of array: ");
    for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }

    printf("Original array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    mergeSort(arr,0,n-1,n);

    printf("\nSorted array: ");
    for(int i=0;i<n;i++){
      printf("%d ",arr[i]);
    }
  return 0;
}
