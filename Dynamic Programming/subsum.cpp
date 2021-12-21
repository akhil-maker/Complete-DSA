#include<iostream>
using namespace std;
bool subsum(int a[], int sum, int n){
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
    return t[n][sum];
}
int main(){
    int a[] = {2, 3, 7, 8, 10};
    cout<<subsum(a, 11, 5);
}