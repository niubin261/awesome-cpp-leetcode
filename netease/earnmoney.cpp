//
// Created by niubin on 17-10-29.
//

#include <iostream>
#include <vector>
using namespace std;
int i=0;
bool dfsSearch(int n,int target,vector<int>&step){
    if(n==target){
        return true;
    }
    if(n>target){
        return false;
    }

    if(dfsSearch(2*n+1,target,step)){
        step.push_back(1);
        return true;
    }
    if(dfsSearch(2*n+2,target,step)){
        step.push_back(2);
        return true;
    }


}
int main(){
    int target=10;
    vector<int>step;
    dfsSearch(0,8,step);
    for(int i=step.size()-1;i>=0;i--){
        cout<<step[i];
    }
}