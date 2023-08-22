#include <iostream>
#include <stack>
using namespace std;

// tokens = ["2","1","+","3","*"]
class Solution {
public:
    int string2int(string token){
        int res=0;
        int flag=1;
        for(int i=0;i<token.size();++i){
            if(i==0 && token[i]=='-'){
                flag=-1;
            }else if(token[i]-'0'>=0 && token[i]-'0'<=9){
                int cur=token[i]-'0';
                res=res*10+cur;
            }
        }
        return res*flag;
    }
    void printStack(stack<int> st){
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();++i){
            if(tokens[i]=="+"){
                int right=st.top();st.pop();
                int left=st.top();st.pop();
                st.push(left+right);
            }else if(tokens[i]=="-"){
                int right=st.top();st.pop();
                int left=st.top();st.pop();
                st.push(left-right);
            }else if(tokens[i]=="*"){
                int right=st.top();st.pop();
                int left=st.top();st.pop();
                st.push(left*right);
            }else if(tokens[i]=="/"){
                int right=st.top();st.pop();
                int left=st.top();st.pop();
                st.push(left/right);
            }else{
                st.push(string2int(tokens[i]));
            }
            printStack(st);

        }
        if(!st.empty()){
            return st.top();
        }else{
            return 0;
        }
    }
};

int main(){
    cout<<"============ test leetcode 150 ==============="<<endl;
    Solution s;
    // vector<string>tokens={"2","1","+","3","*"};
    // vector<string>tokens={"4","13","5","/","+"};
    vector<string>tokens={"3","-4","+"};
    int result = s.evalRPN(tokens);
    cout<<"result is:"<<result<<endl;
}