//
// Created by niubin on 17-9-25.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t size = nums.size();
        if (nums.size() <= 1)return size;
        int j=0;
        int i=0;
        while(i<size){
            if(nums[i]==nums[j])i++;
            else{
                j++;
                nums[j]=nums[i];
                i++;
            }
        }
            return j+1;
    }
};
int main(){
    Solution solution;
    vector<int>vector1{1,2,2,3,3,4,4,5,6,7};
    cout<<solution.removeDuplicates(vector1);
}