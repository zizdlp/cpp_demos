#include <iostream>

using namespace std;

/**
 * 1.[l1,r1),[l2,r2)
 * 2. k from 1
 * 
*/
double findk(vector<int>&nums1,vector<int>&nums2,int l1,int r1,int l2,int r2,int k){
        //nums1[l1:r1];
        //[0,k//2]
        int m=r1-l1+1;
        int n=r2-l2+1;
        if (m<=0){return nums2[l2+k-1];}
        if (n<=0){return nums1[l1+k-1];}
        if (k==1){return min(nums1[l1],nums2[l2]);}

        int idx_1=min(r1,l1+k/2-1);
        int idx_2=min(r2,l2+k/2-1);
        if(nums1[idx_1]<nums2[idx_2]){
            return findk(nums1,nums2,idx_1+1,r1,l2,r2,k-(idx_1-l1+1));
        }
        else{
            return findk(nums1,nums2,l1,r1,idx_2+1,r2,k-(idx_2-l2+1));
        }
    }

int main(){
    //[0,0,0,0,0]
    //[-1,0,0,0,0,0,1]
    // [0,0,0,0,0]
// [-1,0,0,0,0,0,1]
    vector<int>nums1={0,0,0,0,0};
    vector<int>nums2={-1,0,0,0,0,0,1};
    int res=findk(nums1,nums2,0,nums1.size(),0,nums2.size(),6);
    cout<<"findK done:"<<res<<endl;;
}