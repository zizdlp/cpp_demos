#include <iostream>

using namespace std;
void print(vector<vector<int>>dp){
    for(auto i=0;i<dp.size();++i){
        for (auto j=0;j<dp[0].size();++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print1dim(vector<int>dp){
    for(auto i=0;i<dp.size();++i){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
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
        // print(dp);
        cout<<malen;
        for (int i=0;i<m-malen+1;++i){
                if (dp[i][i+malen-1]==true){
                    return s.substr(i,malen);
                }
        }
        
        cout<<malen;
        
        return "";
    }
int rob(vector<int>& nums) {
    int n=nums.size();
    if (n==0) return 0;
    if (n==1) return nums[0];
    if (n==2) return max(nums[0],nums[1]);
    vector<vector<int>>dp(n,vector<int>(2,0));
    int ma=0;
    dp[0][0]=0;
    dp[0][1]=nums[0];
    dp[1][1]=max(nums[0],nums[1]);
    dp[1][0]=nums[1];
    for(int i=2;i<n;++i){
        dp[i][1]=max(dp[i-2][1]+nums[i],dp[i-1][1]);
        dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0]);
    }
    // print(dp);
    return max(dp[n-1][0],dp[n-2][1]);
    //dp[i]=dp[i-2]+nums[i],dp[i-1]-->偷第一间
}

int coinChange(vector<int>& coins, int amount) {
    //dp[i]=min dp[i-k]+1 if k in coins
    if (amount==0) return 0;
    vector<int>dp(amount+1,-1);
    dp[0]=0;
    for(int i=1;i<amount+1;++i){
        for (int j=0;j<coins.size();++j){
            if (i-coins[j]>=0){
                if(dp[i-coins[j]]!=-1){
                if (dp[i]==-1){
                    
                    dp[i]=dp[i-coins[j]]+1;
                    // cout<<"dpi:"<<dp[i];
                }else{
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
                }

                
            }
        }
    }
    print1dim(dp);
    return dp[amount];
}
int lengthOfLIS(vector<int>& nums) {
//dp[i]= max dp[k]+1  if nums[i]>nums[k]

int n=nums.size();
if (n<2) return n;
int ma=0;
vector<int>dp(n,0);
dp[0]=1;
ma=1;
for(int i=1;i<n;++i){
    for(int k=0;k<i;++k){
        if (nums[k]<nums[i]){
            dp[i]=max(dp[i],dp[k]+1);
            ma=max(ma,dp[i]);
        }
    }
}
print1dim(dp);

return ma;
}


bool isPalindrome(int x) {
    if (x<0) return false;
    vector<int>s;
    while(x){
        int c=x%10;
        s.push_back(c);
        x=x/10;
    }
    print1dim(s);
    int n=s.size();
    int l=0;
    int r=n-1;
    while(l<r){
        if (s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
int rangeBitwiseAnd(int left, int right) {
    int lbits=0;
    int rbits=0;
    int lt=left;
    int rt=right;
    while(lt){
        lbits+=1;
        lt>>=1;
        
    }
    while(rt){
        rbits+=1;
        rt>>=1;
    }
    int l = lbits;
    cout<<lbits<<"r:"<<rbits;
    if (lbits!=rbits) return 0;
    while(lbits>0 && (left&(1<<lbits-1)) == (right&(1<<lbits-1))){
        lbits-=1;
    }
    int r=lbits;
    cout<<"lbit:"<<l<<";"<<r;
}
// int searchLeft(vector<int>& nums, int target){
//     int n=nums.size();
//     int l=0,r=n-1,m=0;
//     while(l<r){
//         m=(l+r)/2;
//         if(nums[m]<target){
//             l=m+1;
//         }else if(nums[m]>target){
//             r=m-1;
//         }else{
//             r=m;
//         }
//     }
//     if (nums[l]==target) return l;
//     return -1;
// }
//     int searchRight(vector<int>& nums, int target){
//         int n=nums.size();
//         int l=0,r=n-1,m=0;
//         while(l<r){
//             m=(l+r+1)/2;
//             if(nums[m]<target){
//                 l=m+1;
//             }else if(nums[m]>target){
//                 r=m-1;
//             }else{
//                 l=m;
//             }
//         }
//         if (nums[l]==target) return l;
//         return -1;
//     }
int searchLeft(vector<int>& nums, int target){
        int n=nums.size();
        if (n<=0) return -1;
        int l=0,r=n-1,m=0;
        while(l<r){
            m=(l+r)/2;
            if(nums[m]<target){
                l=m+1;
            }else if(nums[m]>target){
                r=m-1;
            }else{
                r=m;
            }
        }
        if (nums[l]==target) return l;
        return -1;
    }
    int searchRight(vector<int>& nums, int target){
        int n=nums.size();
        if (n<=0) return -1;
        int l=0,r=n-1,m=0;
        while(l<r){
            m=(l+r+1)/2;
            if(nums[m]<target){
                l=m+1;
            }else if(nums[m]>target){
                r=m-1;
            }else{
                l=m;
            }
        }
        if (nums[l]==target) return l;
        return -1;
    }
class Solution {
public:
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    int m;
    int n;
    int k;
    bool dfs(vector<vector<char>>& board, string word,int cur,int i,int j){
        if(cur==word.size()) return true;
        if(cur>word.size()) return false;
        for(auto d:directions){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0 && x<m && y>=0 && y<n && word[cur]==board[x][y] ){
                char tmp =board[x][y];
                board[x][y]='.';
                if(dfs(board,word,cur+1,x,y))return true;
                board[x][y]=tmp;
            }
        }
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        if(m==0) return false;
        n=board[0].size();
        k=word.size();

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[0]){
                    char tmp=board[i][j];
                    board[i][j]='.';//set visited
                    cout<<"call dfs i,j:"<<i<<":"<<j<<endl;
                    if (dfs(board,word,1,i,j)){
                        return true;
                    }
                    board[i][j]=tmp;
                }
            }
        }
        return false;
    }
};
int main(){
    // string s = "a";
    // auto res=longestPalindrome(s);
    // cout<<"res:"<<res;
    // vector<int>s={2};
    // coinChange(s,3);
    // rob(s);
    // vector<int>nums={10,9,2,5,3,7,101,18};
    // lengthOfLIS(nums);
    // isPalindrome(123);
    // rangeBitwiseAnd(5,7);//101,111
    // vector<int>nums={2,2};
    // int l=searchLeft(nums,3);
    // int r =searchRight(nums,3);
    // cout<<l<<r<<endl;
    Solution s;
    string word="AAAAAAAAAAAAAAB";
    vector<vector<char>>board={{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    s.exist(board,word);
} 