#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

template<typename T>
void printVector(vector<T> &nums){
    for(int i=0;i<nums.size();++i){
        cout<<"{"<<i<<":"<<nums[i]<<"}";
    }
    cout<<endl;
}

vector<string> split(string path,char spliter){
    vector<string> result;
    int n=path.size();
    int l=0;
    for (int r=0;r<n;++r){
        if(path[r]==spliter){
            result.push_back(path.substr(l,r-l));
            l=r+1;
        }
    }
    if(l!=n){
        result.push_back(path.substr(l,n-l));
    }
    return result;
}


string simplifyPath(string path) {
    vector<string> split_path=split(path,'/');
    printVector(split_path);
    vector<string>st;
    for(int i=0;i<split_path.size();++i){
        if(split_path[i]==".."){
            if(!st.empty()){
                st.pop_back();
            }
        }else if (split_path[i]=="."){
            //pass
        }else if(split_path[i].size()>0){
            st.push_back(split_path[i]);
        }
    }
    printVector(st);
    
    string ans;
    if(st.empty()){
        return "/";
    }
    for(int i=0;i<st.size();++i){
        ans+="/"+st[i];
    }
    return ans;
}
int main(){
    cout<<"start debug======"<<endl;
    // string path="/a/b/c//../a.bc/assc//a.../...";
    string path="/../";
    string result=simplifyPath(path);
    cout<<"result is:"<<result<<endl;
    deque<int> dq;
}





