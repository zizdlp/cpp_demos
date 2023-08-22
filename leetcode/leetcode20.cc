#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char>map={
               {'}', '{'},
                {')', '('},
                {']', '['}
        };
        auto n =s.size();
        std::stack<char> st;
        for(auto i =0;i<n;++i){
           if(map.find(s[i])==map.end()){
               st.push(s[i]);
           } else{
               if(st.empty() || st.top()!=map[s[i]]){
                   return false;
               }else{
                   st.pop();
               }
           }
        }
        return st.size()==0;
    }
};