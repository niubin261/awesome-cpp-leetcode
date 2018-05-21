//
// Created by niubin on 17-10-11.
//<a herf="http://www.cnblogs.com/tenosdoit/p/3649607.html">ksum algorithm</a>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
class Solution{
public:
    int threeSumClosest(vector<int>&nums,int target){
        sort(nums.begin(),nums.end());
        int result;
        int tmp=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            //The i is iterater from  0 to len-2
            int alpha=twoSumClosest(nums,target-nums[i],i+1);
            int beta=alpha+nums[i];
            if(abs(beta-target)<tmp){
                tmp=abs(beta-target);
                result=beta;
            }
        }
        return result;
    }

private:
    int twoSumClosest(vector<int>&nums,int target,int start){
        int result=0;
        if(nums.empty())return 0;
        int j=nums.size()-1;
        int i=start;
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

    cout<<solution.threeSumClosest(vector1,0);
}