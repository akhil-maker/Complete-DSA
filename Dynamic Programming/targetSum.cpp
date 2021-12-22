#include<iostream>
using namespace std;
int targetSum(int a[], int n, int target){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    if((target+sum)<0 || (target+sum)%2!=0)
        return 0;
    sum = (sum+target)/2;
    int dp[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(a[i-1]<=j)
                dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    int a[] = {1, 1, 1, 1, 1};
    cout<<targetSum(a, 5, 3);
}