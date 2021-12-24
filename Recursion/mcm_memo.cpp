#include<iostream>
using namespace std;
int dp[1001][1001];
int mcm(int a[], int i, int j){
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int mn = INT_MAX;
    for(int k=i; k<j; k++){
        int temp = mcm(a, i, k)+mcm(a, k+1, j)+a[i-1]*a[k]*a[j];
        if(temp<mn)
            mn = temp;
    }
    return dp[i][j] = mn;
}   
int main(){
    int a[] = {40, 20, 30, 10, 30};
    for(int i=0; i<1001; i++)
        for(int j=0; j<1001; j++)
            dp[i][j] = -1;
    cout<<mcm(a, 1, 4);
}