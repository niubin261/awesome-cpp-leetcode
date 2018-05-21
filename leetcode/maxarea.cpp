//
// Created by niubin on 17-10-9.
//

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int tmp=0;
        int max=0;
        while(i<=j){
            if(height[i]<height[j]){
                tmp=height[i]*(j-i);
                i++;
            }else{
                tmp=height[j]*(j-i);
                j--;
            }
            if(max<tmp){
                max=tmp;
            }
        }
        return max;
    }
};
int main(){
    Solution solution;
    vector<int>vector1{1,1};
    cout<<solution.maxArea(vector1);
}