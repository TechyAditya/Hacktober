#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun(vector<int>& nums, int b, int e, int target) {
        int mid = (b + e) / 2;
        if(nums[mid] == target)
            return target;
        else if(b == e)
            return -1;
        else if(nums[mid] > target)
            if(mid == 0)
                return -1;
            else
                return fun(nums, b, mid - 1, target);
        else 
            return fun(nums, mid + 1, e, target);
    }
    int search(vector<int>& nums, int target) {
        return fun(nums, 0, nums.size() - 1, target);
    }
};
int main()
{
    Solution s;
    vector<int> inp = { 2,5 };
    int ret = s.search(inp, 7);
    cout << ret;

    return 0;
}