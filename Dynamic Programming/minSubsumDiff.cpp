#include<iostream>
#include<vector>
using namespace std;
int minSubsumDiff(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    bool t[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j] = true;
            else if(a[i-1]<=j)
                t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    vector<int> r;
    for(int i=0; i<=sum/2; i++)
        if(t[n-1][i]==true)
            r.push_back(i);
    int mn = INT_MAX;
    for(int i=0; i<r.size(); i++)
        mn = min(mn, sum-2*r[i]);
    return mn;
}
int main(){
    int a[] = {1, 2, 4};
    cout<<minSubsumDiff(a, 3);
}   