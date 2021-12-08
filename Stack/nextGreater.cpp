#include<iostream>
#include<stack>
using namespace std;
void nextGreater(int a[], int n){
    stack<int> s;
    s.push(a[0]);
    for(int i=1; i<n; i++){
        if(s.empty()){
            s.push(a[i]);
            continue;
        }
        while(!s.empty() && s.top()<a[i]){
            cout<<s.top()<<"------>"<<a[i]<<endl;
            s.pop();
        }
        s.push(a[i]);
    }
    while(!s.empty()){
        cout<<s.top()<<"------>"<<-1<<endl;
        s.pop();
    }
}
int main(){
    int a[] = {11, 13, 21, 3};
    nextGreater(a, 4);
}