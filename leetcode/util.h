#include <iostream>
#include <vector>

template<typename T>
void printVector(vector<T>nums){
    cout<<"vector iter:";
    for(int i=0;i<nums.size();++i){
        cout<<"{"<<i<<":"<<nums[i]<<"}";
    }
    cout<<endl;
}