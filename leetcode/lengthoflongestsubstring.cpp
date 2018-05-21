//
// Created by niubin on 17-9-17.
//
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0, left = 0, len = s.length();
        int last[255];
        memset(last, -1, sizeof last);

        for (int i = 0; i < len; i++) {
            if (last[s[i]] >= left) left = last[s[i]] + 1;
            last[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
int main(){
    Solution solution;
    cout<<solution.lengthOfLongestSubstring("dvdf");
}