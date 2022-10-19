//WAP to test whether a number n, entered through keyboard is prime or  not by using different algorithms you know for at least 10 inputs 
//and note down the time  complexity by step/frequency count method for each algorithm & for each input. 
//Finally make a comparison of time complexities found for different inputs, plot an appropriate graph & decide which algorithm is faster.

#include<stdio.h> 
int main() 
{ 
    int i=2,n; 
    int count; 

    printf("Enter the number: ");
    scanf("%d",&n); 

    while(i<n) 
    { 
       if(n%i==0){ 
       count=1; 
       break; 
       } 
       else 
      i++; 
    } 

    if (count==1) 
    { 
      printf("Number is not prime  "); 
    } 
    else 
       printf("Number is prime  "); 
       
  return 0; 
}
