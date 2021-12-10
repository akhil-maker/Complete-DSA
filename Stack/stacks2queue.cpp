#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> s1, s2;
    int curr_size;
    public:
    Queue(){
        curr_size = 0;
    }
    void push(int val){
        curr_size++;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        curr_size--;
        if(s1.empty())
            return -1;
        int val = s1.top();
        s1.pop();
        cout<<"popped element is "<<val<<endl;
        return val;
    }
    int size(){
        return curr_size;
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.push(5);
    q.push(6);
    q.push(7);
    q.pop();
}