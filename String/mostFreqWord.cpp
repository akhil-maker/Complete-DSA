#include<iostream>
#include<unordered_map>
using namespace std;
string mostFreqWord(string a[], int n){
    unordered_map<string, int> m;
    unordered_map<string, int> m1;
    for(int i=0; i<n; i++){
        if(m1.count(a[i])>0)
            continue;
        m1[a[i]] = i;
    }
    int mx = 0;
    string ans;
    for(int i=0; i<n; i++){
        m[a[i]]++;
        if(m[a[i]]>mx){
            mx = m[a[i]];
            ans = a[i];
        }
        else if(m[a[i]]==mx && m1[a[i]]<m1[ans])
            ans = a[i];
    }
    return ans;
}
int main(){
    string a[] = {"akhil", "was", "good", "akhil", "is", "good", "akhil", "will", "be", "good"};
    cout<<mostFreqWord(a, 10);
}