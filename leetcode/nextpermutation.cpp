//
// Created by niubin on 17-11-13.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int i;
        for(i=len-1;i>0;i--){
            if(nums[i-1]<nums[i])break;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());

            return;
        } else {
            next_permutation(nums.begin(),nums.end());
        }
//        int j;
//        for(j=len-1;j>=0;j--){
//            if(nums[j]>nums[i-1])break;
//        }
//        swap(nums[i-1],nums[j]);
//        reverse(nums.begin()+i,nums.end());

    }
};
int main(){
    Solution solution;
    vector<int>nums{1,1,5};
    solution.nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];

    }
}
