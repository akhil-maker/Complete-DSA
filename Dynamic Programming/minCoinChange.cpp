#include<iostream>
using namespace std;
int coinChange(int coins[], int n, int sum){
    int t[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)
                t[i][j] = INT_MAX;
            if(j==0)
                t[i][j] = 0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(coins[i-1]<=j)
                t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
int main(){
    int coins[] = {1, 2, 3};
    cout<<coinChange(coins, 3, 5);
}