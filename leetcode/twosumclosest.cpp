//
// Created by niubin on 17-10-11.
//<a herf="http://www.cnblogs.com/tenosdoit/p/3649607.html">ksum algorithm</a>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
class Solution{
public:
    int twoSumClosest(vector<int>&nums,int target){
        sort(vector1.begin(),vector1.end());
        int result=0;
        if(nums.empty())return 0;
        int j=nums.size()-1;
        int i=0;
        int tmp=INT_MAX;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<target){
                i++;
                if(target-sum<tmp){
                    tmp=target-sum;
                    result=sum;
                }
            }else if(sum>target){
                j--;
                if(sum-target<tmp){
                    tmp=sum-target;
                    result=sum;
                }
            }else{
                return target;
            }
        }
        return result;
    }
};
int main(){
    Solution solution;
    vector<int>vector1{0,1,2};

    cout<<solution.twoSumClosest(vector1,0);
}