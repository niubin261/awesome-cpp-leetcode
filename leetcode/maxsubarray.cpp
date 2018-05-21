//
// Created by niubin on 17-10-18.
//
/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 If you have figured out the O(n) solution, try coding another
 solution using the divide and conquer approach, which is more subtle
 */
//O(n*n)
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())return 0;
        int len=nums.size();
        int pInt[len][len];

        memset(pInt,0, sizeof(pInt));
        int result=nums[len-1];
        for(int i=0;i<len;i++){
            pInt[i][i]=nums[i];
        }

        for(int i=len-1;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                pInt[j][i]=pInt[j+1][i]+nums[j];
                if(pInt[j][i]>result){
                    result=pInt[j][i];
                }
            }
        }
        if(result<pInt[0][0]){
            result=pInt[0][0];
        }
        return result;
    }

public:
    int _maxSubArray(vector<int>&nums){
        int result=nums[0];
        int len=nums.size();
        int sum[len];
        sum[0]=nums[0];
        for(int i=1;i<len;i++){
            sum[i]=max(nums[i],sum[i-1]+nums[i]);
            result=max(result,sum[i]);
        }
        return result;
    }
};
int main(){
    vector<int>nums{2,-1};
    Solution solution;
    cout<<solution._maxSubArray(nums);
}