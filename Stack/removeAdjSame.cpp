#include<iostream>
#include<stack>
using namespace std;
string remoDupli(string s){
    int n = s.length();
    int i = 0;
    stack<char> st;
    while(i<n){
        if(st.empty() || s[i]!=st.top())
            st.push(s[i]), i++;
        else
            st.pop(), i++;
    }
    if(st.empty())
        return "-1";
    string r = "";
    while(!st.empty()){
        r = st.top()+r;
        st.pop();
    }
    return r;
}
int main(){
    string x = "azxxzy";
    cout<<remoDupli(x);
}