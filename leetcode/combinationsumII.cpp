//
// Created by niubin on 17-12-8.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>results;
        vector<int>result{};
        backTrack(results,result,candidates,target,0,0);
        return results;
    }

private:
    void backTrack(vector<vector<int>>&results,vector<int>&result,vector<int>candicate,int target,int sum,int start){
        if(target<sum)return;
        if(start>0&&candicate[start]==candicate[start-1])return;;
        if(target==sum)
            return results.push_back(result);
        for(int i=start;i<candicate.size();i++){
            result.push_back(candicate[i]);
            sum=sum+candicate[i];
            start=i+1;
            backTrack(results,result,candicate,target,sum,start);
            sum=sum-result[result.size()-1];
            result.pop_back();
        }

    }
};
int main(){
    Solution solution;
    vector<int>nums{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>>ret=solution.combinationSum2(nums,8);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j];
        }
        cout<<endl;
    }
}