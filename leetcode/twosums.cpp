//
// Created by niubin on 17-9-27.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty()) {
            return vector<int>{};
        }
        int index=-1;
        size_t size=numbers.size();
        for(int i=0;i<size;i++){
            index=binarySearch(numbers,size-1,i+1,target-numbers[i]);
            if(index!=-1){
                return vector<int>{i,index};
            }
        }
        return vector<int>{};
    }

private:
    int binarySearch(vector<int>&numbers,int end,int begin,int key){
        int high=end;
        int low=begin;
        if(low>high)return -1;
        while(low<=high){
            int middle=(low+high)/2;
            if(numbers[middle]>key){
                high=middle-1;
            }else if(numbers[middle]<key){
                low=middle+1;
            } else{
                return middle;
            }

        }
        return -1;
    }
};
int main(){
    Solution solution;
    vector<int>vector1{2,7,11,15};
    vector<int>s=solution.twoSum(vector1, 55);

    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
}