#include<stdio.h>
#include <time.h>
void activity_solution(int s[], int f[], int n) {
    int i=0;
    printf("Activity 0\n");
    for(int m=1;m<n;m++) {
        if(s[m] >= f[i]) {
         printf("Activity %d\n",m);
         i=m;
        }
    } 
}
int main() {
    double total_time;
    clock_t start1, end;
    start1 = clock();
    int start[] = {1,3,0,5,8,5};
    int finish[] = {2,4,6,7,9,9};
    activity_solution(start, finish, 6);
    end = clock();
    total_time = ((double) (end - start1)) / CLK_TCK;
    printf("\nTime taken : %f seconds\n", total_time);
    
}
