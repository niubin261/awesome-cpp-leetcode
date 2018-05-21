//
// Created by niubin on 17-12-1.
//

#include <vector>
#include <iostream>
using namespace std;
bool compareFunc(char a,char b ){
    if(islower(b)&&isupper(a)){
        return true;
    }
    return false;
}
void swap(char&a,char&b){
    char temp;
    temp=a;
    a=b;
    b=temp;
}
int main(){
    vector<char>chars{'A','k','B','C','c'};
    int len=chars.size();
    for(int i=0;i<len;i++)
        for(int j=0;j<len-1-i;j++){
            if(compareFunc(chars[j],chars[j+1])){
                swap(chars[j],chars[j+1]);
            }
        }
    for(int i=0;i<len;i++){
        cout<<chars[i];
    }
}
