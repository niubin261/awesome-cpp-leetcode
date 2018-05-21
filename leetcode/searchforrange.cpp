//
// Created by niubin on 17-11-3.
//

/*Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1;
        int end=-1;
        vector<int>result{0};

        int pos=binarySearch(nums,target);

        if(pos==-1)return result;
        start=pos;
        end=pos;
        while(nums[++end]==target&&end<=nums.size()-1){}
        end--;
        while(nums[--start]==target&&start>=0){}
        start++;

        result[0]=start;
        result[1]=end;
        result[3]=end;
        return result;



    }
private:
    int binarySearch(vector<int>&nums,int target){
        int pos=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int middle=(low+high)/2;
            if(nums[middle]<target){
                low=middle+1;

            } else if(nums[middle]>target){
                high=middle-1;
            } else{
                pos=middle;
                return pos;
            }
        }
        return pos;

    }
};
int main(){
    Solution solution;
    vector<int>nums{0,0,0,1,2,3};
    vector<int>ret;
    ret=solution.searchRange(nums,0);
    cout<<ret[0]<<ret[1]<<ret[3];

}