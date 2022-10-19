#include <stdio.h>

void bubbleSort(int array[], int n) 
{

int count=0;

  for (int i = 0; i < n - 1; i++) 
  {
    for (int j = 0; j < n - i - 1; j++) 
    {
      count++;
      if (array[j] > array[j + 1]) 
      {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  printf("Number of comparisions: %d",count);
}


int main() {
    int n;
    printf("Enter number of array elements: ");
    scanf("%d",&n);
    int arr[n],i;

    printf("Enter the array elements: ");
    
    for(i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }

  bubbleSort(arr, n);
  
  printf("Sorted Array in Ascending Order:\n");
  for (i=0; i<n;i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
  
}
