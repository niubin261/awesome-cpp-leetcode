//
// Created by niubin on 17-11-4.
//

/*I 1 V 5 X 10 L 50 C 100 D 500 M 1000
 * the five is bond
 * */
#include <string>
#include <vector>

#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int>alpha{};
        while(num!=0){
            int tmp=num%10;
            alpha.push_back(tmp);
            num=num/10;
        }
        int len=alpha.size();
        string result{};
        for(int i=len-1;i>=0;i--){
            result+=toRoman(alpha[i],i);
        }
        return result;

    }

private:
    string toRoman(int num,int i){
        string result;
        switch (i){
            case 0:
                result=roman(num,'I','V','X');
                break;
            case 1:
                result=roman(num,'X','L','C');
                break;
            case 2:
                result=roman(num,'C','D','M');
                break;
            case 3:
                result=roman(num,'M',' ',' ');
                break;
            default:
                break;
        }
        return result;
    }

private:
    string roman(int num,char c1,char c2,char c3){
        string result;
        if(num<4){
            return result.append(num,c1);
        }
        if(num==4){
            result.append(1,c1);
            return result.append(1,c2);

        }
        if(num==5){
            return result.append(1,c2);
        }
        if(num>5&&num<9){
            result.append(1,c2);
            return result.append(num-5,c1);
        }
        if(num==9){
            result.append(1,c1);
            return result.append(1,c3);
        }
        return result;
    }
};
int main(){
    Solution solution;
    cout<<solution.intToRoman(90);
}