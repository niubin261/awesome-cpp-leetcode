//
// Created by niubin on 17-9-17.
//
#include <vector>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        int index=(x>0?1:-1);
        cout<<index<<'\n';
        x=abs(x);
        long long y=0;//long long must
        vector<int>nums;
        while(x!=0){
            int alpha=x%10;
            nums.push_back(alpha);
            x=x/10;
        }
        int beta=nums.size()-1;
        for(int i=0;i<=beta;i++){
            cout<<nums[i]<<'\n';
            y=y+nums[i]*pow(10,beta-i);

            if(index*y<INT32_MIN||index*y>INT32_MAX){
                return 0;
            }
        }
        return index*y;
    }
};
int main(){
    Solution solution;
    std::cout<<solution.reverse(1534236469);
    return 0;
}