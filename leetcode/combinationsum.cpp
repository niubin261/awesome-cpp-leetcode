//
// Created by niubin on 17-11-12.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>results;
        vector<int>result;
        int sum=0;
        int start=0;
        backTrack(results,target,candidates,result,start,sum);
        return results;

    }

private:
    void backTrack(vector<vector<int>>&results,int target,vector<int>&candicates,vector<int>result,int start,int sum){
        if(sum>target)return;
        if(sum==target)
            return results.push_back(result);
        for(int i=start;i<candicates.size();i++){
            sum=sum+candicates[i];
            result.push_back(candicates[i]);
            backTrack(results,target,candicates,result,i,sum);
            sum=sum-result[result.size()-1];
            result.pop_back();

        }
    }

};
int main(){
    Solution solution;
    vector<int>nums{2,3,6,7};
    vector<vector<int>>ret=solution.combinationSum(nums,7);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j];
        }
        cout<<endl;
    }
}