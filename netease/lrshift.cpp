//
// Created by niubin on 17-11-7.
//

#include <iostream>
using namespace std;
void printGraph(char c){

    cout<<c<<endl;
    if(c=='l'){
        cout<<' '<<c;
    }
    if(c=='r'){
        cout<<' '<<c;
    }
}
int main(){
    char input;
    int i=0;
    while(cin>>input){

        printGraph(input);
    }

}