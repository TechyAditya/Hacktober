#include<iostream>
using namespace std;
int main()
{
    int num, i, chk=0,countSteps=0;
    cout<<"Enter a Number: ";
    cin>>num;
    for(i=2; i<num/2; i++)
    {
        countSteps++;
        if(num%i==0)
        {
            chk++;
            break;
        }
    }
    if(chk==0)
        cout<<"\nIt is a Prime Number";
    else
        cout<<"\nIt is not a Prime Number";
    cout<<"\nNo. of steps : "<<countSteps;
    cout<<endl;
    return 0;
}
