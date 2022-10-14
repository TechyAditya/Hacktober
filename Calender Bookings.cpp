#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class MyCalendar {
public:
    vector<pair<int,int>> bookings;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto i : bookings) {
            if(start >= i.first && start < i.second)
                return false;
            if(end > i.first && end <= i.second)
                return false;
            if(start < i.first && start < i.second)
        }
        pair<int,int> pp = {start, end};
        bookings.push_back(pp);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main()
{
    MyCalendar* obj = new MyCalendar();
    bool param[100] = {false};
    vector<pair<int,int>> inputs = {{97,100},{33,51},{89,100},{83,100},{75,92},{76,95},{19,30},{53,63},{8,23},{18,37},{87,100},{83,100},{54,67},{35,48},{58,75},{70,89},{13,32},{44,63},{51,62},{2,15}};

    for(int i = 0; i < inputs.size(); i++) {
        param[i] = obj->book(inputs[i].first, inputs[i].second);
    }
    
    for(int i = 0; i < inputs.size(); i++) {
        param[i] ? cout << "true," : cout << "false,";
    }
    cout<<"\b \ntrue,true,false,false,true,false,true,true,false,false,false,false,false,false,false,false,false,false,false,true"<<endl;

    return 0;
}