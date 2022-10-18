#include <stdio.h>

int main()
{

int n;
printf("Enter number of array elements");
scanf("%d",&n);
int arr[n],i;

for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}

int j,fr[n],seen=-1,c;

for(i=0;i<n;i++)
{
    c=1;
    for(j=i+1;j<n;j++)
    {
        if(arr[1]==arr[j])
        c++;

        fr[j]=seen;
    }
    if(fr[i] != seen)    
    fr[i] = c;
}

    printf("---------------------\n");    
    printf(" Element | Frequency\n");    
    printf("---------------------\n");    
    for(int i = 0; i < n; i++){    
        if(fr[i] != seen){    
            printf("    %d", arr[i]);    
            printf("    |  ");    
            printf("  %d\n", fr[i]);    
        }    
    }    
    printf("---------------------\n");    
    return 0;    
}     


