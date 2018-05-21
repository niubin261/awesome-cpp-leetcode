//
// Created by niubin on 17-11-22.
//
#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len=nums.size();
        if(len==0)return false;
        map<int,int>intCount{};
        for(int i=0;i<len;i++){
            if(containsKey(intCount,nums[i])){
                int temp=intCount[nums[i]];
                if((i-temp)<=k){
                    return true;
                }else{
                    intCount[nums[i]]=i;
                }

            }else{
                intCount.insert(pair<int,int>{nums[i],i});
            }
        }
        return false;
    }
private:
    bool containsKey(map<int,int>&m,int key){
         if(m.find(key)==m.end()){
             return false;
         }else{
             return true;
         }
    }
};
int main(){
    Solution solution;
    vector<int>nums{3,3};
    cout<<solution.containsNearbyDuplicate(nums,1);
}