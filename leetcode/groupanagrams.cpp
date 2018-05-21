//
// Created by niubin on 18-2-6.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <map>
#include <syslog.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();

        map<string,vector<string>> m;

        vector<vector<string>> ret;
        if (len == 0) return ret;
        for (string str: strs) {
            string tmp = str;
            sort(tmp.begin(),tmp.end());
//            if (containsKey(m,tmp)) {
//                m[tmp].push_back(str);
//
//            } else {
//
//                m.insert({tmp,vector<string> {str}});
//                cout << m.size() << endl;
//            }
            m[tmp].push_back(str);
        }
//        vector<string> a;
//        for (auto it = m.begin(); it != m.end(); it++){
//            cout << (*it).first << endl;
//            for (auto s: (*it).second) {
//                a.push_back(s);
//                cout << s << ' ';
//
//            }
//            cout << endl;
//        }
//
//        vector<string> second;
        for (auto p: m) {

            ret.push_back(p.second);
        }
        return ret;


    }

//private:
//    bool containsKey(map<string,vector<string>> m,string s) {
//        for (auto p: m){
//            if (p.first == s)
//                return true;
//        }
//        return false;
//    }


};
int main(){
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    vector<vector<string>> result;
    result = solution.groupAnagrams(strs);
    cout << result.size();
    for (auto p: result){
        for (auto q: p) {
            cout<<q;
        }
    }
}