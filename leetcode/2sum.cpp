//
// Created by niubin on 17-9-16.
//
#include <vector>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
    }
};
int main(){
    Solution solution;
    vector<int>a{2,7,11,15};
    int target=9;
    solution.twoSum(a,target);
    return 0;
}
