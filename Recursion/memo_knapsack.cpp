#include<iostream>
using namespace std;
int t[1001][1001];
int knapsack(int wt[], int val[], int W, int n){
    if(t[n][W]!=-1)
        return t[n][W];
    if(n==0 || W==0)
        return t[n][W] = 0;
    if(wt[n-1]<=W)
        return t[n][W] = max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
    return t[n][W] = knapsack(wt, val, W, n-1);
}
int main(){
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4, W = 7;
    for(int i=0; i<n+1; i++)
        for(int j=0; j<W+1; j++)
            t[i][j] = -1;
    cout<<knapsack(wt, val, W, n);
}