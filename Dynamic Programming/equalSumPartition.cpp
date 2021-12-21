#include<iostream>
using namespace std;
bool subsum(int a[], int n, int sum){
    int t[n+1][sum+1];
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
    return t[n][sum];
}
bool equalsumPart(int a[], int n){
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    if(sum%2!=0)
        return false;
    return subsum(a, n, sum/2);
}
int main(){
    int a[] = {1, 5, 11, 5};
    cout<<equalsumPart(a, 4);
}