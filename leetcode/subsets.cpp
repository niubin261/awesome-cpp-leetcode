//
// Created by niubin on 17-11-24.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        if(nums.size()==0)return result;

        vector<int>subset;
        backTrack(nums,0,result,subset);
        return result;
    }

private:
    void backTrack(vector<int>&nums,int start,vector<vector<int>>&result,vector<int>subset){
        result.push_back(subset);
        for(int i=start;i<nums.size();i++){
            subset.push_back(nums[i]);
            backTrack(nums,i+1,result,subset);

            subset.pop_back();
        }
        return;
    }
};
int main(){
    Solution solution;
    vector<int>nums{1,2,3};
    vector<vector<int>>ret=solution.subsets(nums);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j];
        }
        cout<<endl;
    }
}