#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<set<char>,int> m;
        vector<string> ret;
        for(auto i : words1) {
            set<char> a1(words2[0].begin(), words2[0].end());
            set<char> a2(words2[1].begin(), words2[1].end());
            set<char> a = a1;
            a.insert(a2.begin(), a2.end());
            map<char,int> s1,s2,s;
            for(auto j : words2[0]) {
                s1[j]++;
            }
            for(auto j : words2[1]) {
                s2[j]++;
            }
            for(auto j : a) {
                if(s1[j] > s2[j])
                    s[j] = s1[j];
                else
                    s[j] = s2[j];
            }
            map<char,int> track;

            for(int j = 0; j < i.size(); j++) {
                for(auto k : a) {
                    if(i[j] == k) {
                        track[k]++;
                    }
                }
            }
            int flag = 1;
            for(auto j : a) {
                if(track[j] < s[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main()
{
    vector<string> words1 = {"aacbb","caacc","bcbbb","cccbb","acaac"};
    vector<string> words2 = {"c","cc","b"};
    Solution s;
    vector<string> ret = s.wordSubsets(words1, words2);
    for(auto i : ret)
        cout << i << " ";
    return 0;
}