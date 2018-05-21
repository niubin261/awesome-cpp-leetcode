//
// Created by niubin on 17-10-10.
//
//<a href="http://www.cnblogs.com/tenosdoit/p/3649607.html">k sums algorithm</a>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void twoSum(vector<int> &nums, int i, int target,vector<vector<int>>&result) {
        int m=i;
        int n=nums.size()-1;
        while(m<n){

                if(nums[m]+nums[n]>target){
                    n--;
                }else if(nums[m]+nums[n]<target){
                    m++;
                }else{
                    result.push_back(vector<int>{nums[i-1],nums[m],nums[n]});
                    int k=m+1;
                    while(k<n&&nums[k]==nums[m])k++;
                    m=k;

                    int l=n-1;
                    while(l>m&&nums[l]==nums[n])l--;
                    n=l;

                }
            }

        }





public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result{};
        if(nums.empty())return result;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            twoSum(nums,i+1,-nums[i], result);
        }
        return result;

    }

};
int main(){
    Solution solution;

    vector<int>vector1{-1, 0, 1, 2, -1, -4};
    solution.threeSum(vector1);
}