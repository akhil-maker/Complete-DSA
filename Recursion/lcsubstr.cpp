#include<iostream>
using namespace std;
int lcs(string x, string y, int m, int n, int count){
    if(m==0 || n==0)
        return count;
    if(x[m-1]==y[n-1])
        count = lcs(x, y, m-1, n-1, count+1);
    else
        count = max(count, max(lcs(x, y, m-1, n, 0), lcs(x, y, m, n-1, 0)));
    return count;
}
int main(){
    cout<<lcs("abcde", "abfce", 5, 5, 0);
}