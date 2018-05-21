//
// Created by niubin on 17-12-9.
//
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>>  permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int>candidate{};
        for(int i=0;i<nums.size();i++){
            if(containsKey(candidate,nums[i])){
                int cnt=candidate[nums[i]];
                cnt++;
                candidate[nums[i]]=cnt;
            }else{
                candidate[nums[i]]=1;
            }
        }
        vector<int>result;
        vector<vector<int>>results;
        backTrack(results,result,candidate,nums);
        return results;
    }

private:
    bool containsKey(map<int,int>&m,int key){
        if(m.find(key)==m.end()){
            return false;
        }
        return true;
    }

private:
    void backTrack(vector<vector<int>>&results,vector<int>&result,map<int,int>candidate,vector<int>nums){
        if(result.size()==nums.size()){
           return results.push_back(result);
        }

        for(auto&item:candidate){
            if(item.second){
                int cnt=item.second;
                cnt--;
                item.second=cnt;
                result.push_back(item.first);
                backTrack(results,result,candidate,nums);
                int tmp=item.second;
                tmp++;
                item.second=tmp;
                result.pop_back();
            }
        }
        return;
    }
};
int main(){
    Solution solution;
    vector<int>nums{1,1,3};
    vector<vector<int>>ret=solution.permute(nums);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j];
        }
        cout<<endl;
    }
}