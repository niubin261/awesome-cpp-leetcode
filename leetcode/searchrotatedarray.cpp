//
// Created by niubin on 17-11-1.
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

//You are given a target value to search. If found in the array return its index, otherwise return -1.

//You may assume no duplicate exists in the array.
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0)
            return -1;
        int i=0;
        i=findIndex(nums);
        int pos=-1;
        binarySearch(nums,pos,target,0,i);
        if(pos!=-1){
            return pos;
        }
        binarySearch(nums,pos,target,i+1,len-1);
        return pos;

    }

private:
    int findIndex(vector<int>&nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (high-low>1) {
            int middle = (low + high) / 2;
            if (nums[middle] > nums[low]) {
                low = middle;
            } else if (nums[middle] < nums[low]) {
                high = middle;
            } else {

            }
        }
        if (nums[high] > nums[low]) {
            return high;
        }
        return low;
    }
private:
    void binarySearch(vector<int>&nums,int&pos,int target,int start,int end){
        int low=start;
        int high=end;
        while(low<=high){
            int middle=(low+high)/2;
            if(nums[middle]<target){
                low=middle+1;

            } else if(nums[middle]>target){
                high=middle-1;
            } else{
                pos=middle;
                return ;
            }
        }

    }
};
int main(){
    Solution solution;
    vector<int>simple{0,1,4,5,6,7};
    cout<<solution.search(simple,4);
}