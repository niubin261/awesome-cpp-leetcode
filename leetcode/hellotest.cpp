#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())return 0;
        int size=nums.size();
        int i=0;
        int j=size-1;
        int result=1;
        while(i<=j){
            if(nums[i]==val){
                nums[i]=nums[j];
                j--;
            }else{
                i++;
            }
        }
        return j+1;
    }
};
int main(){
    Solution solution;
    vector<int>vector1{3,6,4,5,6,7,8,8,8,8,2,2,3};
    cout<<solution.removeElement(vector1,8);
}