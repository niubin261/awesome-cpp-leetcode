//
// Created by niubin on 17-11-7.
//
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct Line{
    int startPoint;
    int endPoint;
    Line(int begin,int end):startPoint(begin),endPoint(end){}

};
class Solution {
public:
    int lengthAllSegment(vector<Line>&lines){
        int len=lines.size();
        sort(lines.begin(),lines.end(),[](Line a,Line b){return a.startPoint<b.startPoint;});
        int result=lines[0].endPoint-lines[0].startPoint;
        for(int i=0;i<len-1;i++){
            int tmp=max(lines[i+1].endPoint -max(lines[i+1].startPoint,
                                                 lines[i].endPoint)
                    ,0);

            result+=tmp;
        }
        return result;
    }
};
int main(){
    Solution solution;
    Line a(2,4);
    Line b(1,5);
    Line c(7,8);
    vector<Line>lines{a,b,c};
    cout<<solution.lengthAllSegment(lines);

    return 0;
}