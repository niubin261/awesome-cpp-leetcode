//
// Created by niubin on 17-10-17.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution{
public:
    int searchInsert(vector<int>&nums, int target){
        //binary search
        if(nums.empty())return 0;
        int len=nums.size()-1;
        int i=0;
        int j=len;
        int pos=0;
        bool find=false;
        int middle=0;
        while(i<=j){//yi ding yao shi dengyu
            middle=(i+j)/2;
            if(nums[middle]>target){
                j=middle-1;
            }else if(nums[middle]<target){
                i=middle+1;
            }else{
                return middle;
            }
        }
            int index=min(i,j);
            if(target>nums[index]){return index+1;}
            else {return index-1>0? index-1:0;}


    }
};
int main(){
    vector<int>nums{1,3,5,6};
    Solution solution;
    cout<<solution.searchInsert(nums,2);
    return 0;
}