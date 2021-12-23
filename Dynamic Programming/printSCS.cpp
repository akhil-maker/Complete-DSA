#include<iostream>
using namespace std;
string scs(string x, string y){
    int m = x.length(), n = y.length();
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(x[i-1]==y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i = 0, j = 0;
    string res = "";
    while(i<=m && j<=n){
        if(x[i-1]==y[j-1]){
            res.push_back(x[i-1]);
            i++, j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]){
            res.push_back(x[i-1]);
            i++;
        }
        else{
            res.push_back(y[j-1]);
            j++;
        }
    }
    while(i<=m){
        res.push_back(x[i-1]);
        i++;
    }
    while(j<=n){
        res.push_back(y[j-1]);
        j++;
    }
    return res;
}
int main(){
    cout<<scs("abgdh", "abedf");
}