#include<iostream>
using namespace std;
int mcm(int a[], int n){
    int dp[n][n];
    for(int i=1; i<n; i++)
        dp[i][i] = 0;
    for(int L=2; L<n; L++){
        for(int i=1; i<n-L+1; i++){
            int j = i+L-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q = dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                if(q<dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    return dp[1][n-1];
}
int main(){
    int a[] = {40, 20, 30, 10, 30};
    cout<<mcm(a, 5);
}