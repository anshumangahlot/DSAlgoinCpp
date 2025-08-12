#include <stdio.h>

void display(int arr[],int n){
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[],int n) {
  for(int i=0;i<n-1;i++){
    printf("Pass %d\n",i+1);
    for(int j=0;j<n-(i+1);j++){
      if(arr[j]>arr[j+1]) {
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
    display(arr,n);
  }
  printf("\nSorted Array:");
  display(arr,n);
}

void selectionSort(int arr[],int n) {
  for(int i=0;i<n-1;i++){
    printf("Pass %d\n",i+1);
    int idx=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[idx]) {
        idx = j;
      }
    }
    int temp=arr[i];
    arr[i]=arr[idx];
    arr[idx]=temp;

    display(arr,n);
  }
  printf("\nSorted Array:");
  display(arr,n);
}

void insertionSort(int arr[],int n) {
  for(int i=1;i<n;i++){
    printf("Pass %d\n",i-1);
    int temp=arr[i];
    int j;
    for(j=i-1;j>=0;j--) {
      if(arr[j]>temp) {
        arr[j+1]=arr[j];
      }
    }
    arr[j+1]=temp;
    display(arr,n);
  }
  printf("\nSorted Array:");
  display(arr,n);
}


int main(){
  int n;
  printf("Input size of array: ");
  scanf("%d",&n);

  int arr[n];
  printf("Input array elements: ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  printf("Original Array:");
  display(arr,n);
  printf("\n");

  int choice;
  printf("Enter your choice- (1)Bubble Sort , (2)Selection Sort & (3)Insertion Sort : ");
  scanf("%d",&choice);
  switch(choice) {
    case 1:
      bubbleSort(arr,n);
      break;
    case 2:
      selectionSort(arr,n);
      break;
    case 3:
      insertionSort(arr,n);
      break;
    default: printf("Enter valid choice");
  }
  return 0;
}
