#include <iostream>
#include <stack>
using namespace std;


class MinStack {
public:
    // 两个栈实现最小栈。
    stack<int> x_stack;
    stack<int> min_stack; //维护降序
    MinStack() {

    }
    
    void push(int val) {
        x_stack.push(val);
        if(min_stack.empty() || min_stack.top()>=val){
            min_stack.push(val);
        }
    }
    
    void pop() {//
        if(!x_stack.empty()){
            int topValue=x_stack.top();
            x_stack.pop();
            if(topValue<=min_stack.top()){
                min_stack.pop();
            }
        }
    }
    
    int top() {
        if(!x_stack.empty()){
            return x_stack.top();
        }else{
            return -1;
        }
    }
    
    int getMin() { //o(1)
        if(!min_stack.empty()){
            return min_stack.top();
        }else{
            return -1;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



int main(){
    cout<<"============ test leetcode155 ============="<<endl;
    int val=6;
    MinStack* obj = new MinStack();
    obj->push(val);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}