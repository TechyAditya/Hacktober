// Heapsort
#include <stdio.h>
#include <stdlib.h>
//#include <bits/stdc++.h>
#include<time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int choice, flag, l, a[50000], i,j,s;
    printf("   Menu:\n\n");
    printf("0) Exit.\n");
    printf("1) Enter numbers in a list.\n");
    printf("2) Display the list.\n");
    printf("3) Arrange the array in ascending order using heapsort.\n");
    printf("4) Sorting time vs. Array Size table .\n\n");
    flag = 1;
    while (flag == 1)
    {
        printf("Enter choice :\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            flag = 0;
            break;
        case 1:
            printf("Enter size of the array:\n");
            scanf("%d", &l);
            printf("Enter values:\n");
            for (i = 0; i < l; i++)
                scanf("%d", &a[i]);
            break;
        case 2:
            printf("List:\n\n");
            for (i = 0; i < l; i++)
                printf("|%d|", a[i]);
            printf("\n");
            break;
        case 3:
            heapSort(a, l);
            break;
        
        case 4:
            s = 0;
            printf("Analysis Table for Heap Sort Algorithm:\n\n");
            printf("Size of array\tTime Taken:\n\n");
            for (i = 2500; i <= 50000; i += 2500)
            {
                for (j = 0; j < i; j++)
                    a[j] = rand();
                clock_t start, end;
                start = clock();
                heapSort(a, i);
                end = clock();
                double timeTaken = (double)(end - start) / (double)CLOCKS_PER_SEC;
                printf("(%d)            |(%d)          |(%f) \n", ++s, i, timeTaken);

            }
            break;
        default:
            printf("Wrong choice ");
        }
    }
    return 0;
}
