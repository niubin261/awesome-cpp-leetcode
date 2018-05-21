//
// Created by niubin on 17-12-26.
//
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size=nums.size();
        int i=0; int j=size-1;
        while(true){
            while(nums[i]<2)i++;
            while(nums[j]==2)j--;
            if(i>=j)break;
            swap(nums[i],nums[j]);

        }
        i=0;
        j=j;
        while(true){
            while(nums[i]<1)i++;
            while(nums[j]==1)j--;
            if(i>=j)break;
            swap(nums[i],nums[j]);

        }

    }
};
int main(){
    vector<int>nums{1,2,1,0,2,0};
    Solution solution;
    solution.sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
}