#include<iostream>
using namespace std;
int lcs(string x, string y){
    int m = x.length(), n = y.length();
    int dp[m+1][n+1];
    int res = INT_MIN;
    for(int i=0; i<m+1; i++)
        for(int j=0; j<n+1; j++)
            if(i==0 || j==0)
                dp[i][j] = 0;
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                res = max(dp[i][j], res);
            }
            else
                dp[i][j] = 0;
        }
    }
    return res;
}
int main(){
    cout<<lcs("abcde", "abedg");
}