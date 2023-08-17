#include <iostream>

using namespace std;
void print(vector<vector<bool>>dp){
    for(auto i=0;i<dp.size();++i){
        for (auto j=0;j<dp[0].size();++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,0)));
    //dp[i][k][0,1]
    // dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
    // dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
    for (auto k=0;k<3;++k){
        dp[0][k][0]=0;
        dp[0][k][1]=-prices[0];
    }
    for(auto i=1;i<n;++i){
        dp[i][0][0]=0;
        dp[i][0][1]=-prices[i];
        for (auto k=1;k<3;++k){
            dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
            dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
        }
    }
    return max(dp[n-1][1][0],dp[n-1][2][0]);
}
int maximalSquare(vector<vector<char>>& matrix) {
        //dp[i][j]=min(dp[i][j-1],dp[i-1][j])+1 if ==1
        auto m=matrix.size();
        if(m==0) return 0;
        auto n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ma=0;
        for(int i=1;i<m;++i){
            if(matrix[i][0]=='1'){
                ma=1;
                dp[i][0]=1;
            } 
        }
        for(int j=1;j<n;++j){
            if(matrix[0][j]=='1') {
                ma=1;
                dp[0][j]=1;
            }
        }

        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if (matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j])+1;
                    ma=max(ma,dp[i][j]);
                }
            }
        }
        return ma;
    }
    string longestPalindrome(string s) {

        // dp[i][j]=dp[i+1][j-1]+2 or dp[i]
        int m=s.size();
        if (m==0) return "";
        vector<vector<bool>>dp(m,vector<bool>(m,false));
        int malen=0;
        for(int i=0;i<m;++i){
            dp[i][i]=true;
            malen=max(malen,1);
            if(i<m-1 && s[i]==s[i+1]){
                dp[i][i+1]=true; 
                malen=2;
            } 

            if(i>0 && s[i]==s[i-1]){
                dp[i-1][i]=true;
                malen=2;
            } 
        }  
        // print(dp); 
        // cout<<malen;

        // cout<<"000b";
        for(int i=m-1;i>=0;--i){
            for (int j=i+2;j<m;++j){
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                if (dp[j][i]) malen=max(malen,i-j+1);
            }
        }
        // cout<<"000";
        for(int i=0;i<m;++i){
            for(int j=i-2;j>=0;--j){
                if(s[j]==s[i]) {
                    dp[j][i]=dp[j+1][i-1];
                    if (dp[j][i]) malen=max(malen,i-j+1);
                } 
            }
        }
        print(dp);
        cout<<malen;
        for (int i=0;i<m-malen+1;++i){
                if (dp[i][i+malen-1]==true){
                    return s.substr(i,malen);
                }
        }
        
        cout<<malen;
        
        return "";
    }
int main(){
    string s = "a";
    auto res=longestPalindrome(s);
    cout<<"res:"<<res;

}